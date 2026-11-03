#include "CwDecoder.hpp"
#include <algorithm>
#include <cmath>

#ifdef WSJT_HAVE_DEEPCW
#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QStandardPaths>
#include <QStringList>
#include <QDebug>
#include <thread>
#endif

namespace Cw {

#ifdef WSJT_HAVE_DEEPCW
namespace {

QString deepcwModelPath() {
    QStringList dirs;
    const QString env = qEnvironmentVariable("WSJT_DEEPCW_MODELS");
    if (!env.isEmpty()) dirs << env;

    const QString appData = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    if (!appData.isEmpty()) dirs << appData + "/models/deepcw";

    const QString appDir = QCoreApplication::applicationDirPath();
    dirs << appDir + "/models/deepcw";
    dirs << appDir + "/../share/wsjtx/models/deepcw";

    for (const QString& dir : dirs) {
        const QString path = QDir(dir).filePath("model.onnx");
        if (QFileInfo::exists(path)) return path;
    }
    return {};
}

} // namespace

void Decoder::ensureDeepCwStarted() {
    if (deepcw_started_ || deepcw_failed_) return;

    const QString model_path = deepcwModelPath();
    if (model_path.isEmpty()) {
        deepcw_failed_ = true;
        qWarning() << "DeepCW: model.onnx not found (set WSJT_DEEPCW_MODELS or install models/deepcw)";
        return;
    }

    if (!deepcw_) deepcw_.reset(new DeepCw::Decoder());
    DeepCw::Settings settings;
    settings.model_path = model_path.toStdString();
    const QString narrow_path = QFileInfo(model_path).dir().filePath("model_narrow.onnx");
    if (QFileInfo::exists(narrow_path)) {
        settings.model_narrow_path = narrow_path.toStdString();
    }
    settings.max_segment_seconds = 12;
    settings.cadence_ms = 1000;
    settings.idle_finalize_ms = 1500;
    settings.multi_channel = true;
    settings.max_channels = 5;
    const int hw = static_cast<int>(std::thread::hardware_concurrency());
    settings.intra_threads = std::max(1, std::min(4, hw / 2));

    std::string error;
    if (!deepcw_->start(settings, error)) {
        deepcw_failed_ = true;
        qWarning() << "DeepCW: failed to start:" << QString::fromStdString(error);
        return;
    }
    deepcw_started_ = true;
}
#endif

void Decoder::setDecoderType(DecoderType type) {
#ifdef WSJT_HAVE_DEEPCW
    if (type != DecoderType::DeepCw && deepcw_) {
        deepcw_->stop();
        deepcw_.reset();
        deepcw_started_ = false;
        deepcw_failed_ = false;
    }
#endif
    decoder_type_ = type;
    reinit();
}

Decoder::Decoder() {
    multiDemod_gt_.reset(new CwGtDemod());
}

Decoder::~Decoder() = default;

void Decoder::reinit() {
    fldigiLow_ = -1;
    fldigiHigh_ = -1;
    if (decoder_type_ == DecoderType::Fldigi) {
        multiDemod_fldigi_.init(55, 300.0f, 3000.0f);
        multiDemod_fldigi_.setWpm(20);
        multiDemod_fldigi_.setBandwidth(50);
        multiDemod_fldigi_.setSquelch(5.0);
        multiDemod_fldigi_.setAdaptive(true);
        multiDemod_fldigi_.setReverse(false);
    } else if (decoder_type_ == DecoderType::Gridtracker) {
        // Gridtracker decoder
        multiDemod_gt_->setWpm(20);
        multiDemod_gt_->setBandwidth(50);
        multiDemod_gt_->setSquelch(5.0f);
        multiDemod_gt_->setAdaptive(true);
        multiDemod_gt_->setReverse(false);
        multiDemod_gt_->setRange(300, 3000);
        multiDemod_gt_->rx_init();
    }
#ifdef WSJT_HAVE_DEEPCW
    else if (decoder_type_ == DecoderType::DeepCw) {
        if (deepcw_) {
            deepcw_->stop();
            deepcw_.reset();
        }
        deepcw_started_ = false;
        deepcw_failed_ = false;
        ensureDeepCwStarted();
    }
#endif
}

void Decoder::begin(qint64 sessionId, qint64 gridOrigin, qint64 firstSearch, int samplesPerSymbol) {
    (void)samplesPerSymbol;
    sessionId_ = sessionId;
    gridOrigin_ = gridOrigin;
    nextRequiredSample_ = firstSearch;

    if (decoder_type_ == DecoderType::DeepCw) {
#ifdef WSJT_HAVE_DEEPCW
        ensureDeepCwStarted();
        if (deepcw_started_) deepcw_->reset();
#endif
    } else {
        reinit();
    }

    channels_.assign(64, ChannelState());
    pendingUpdates_.clear();
}

void Decoder::setSubmode(const QString& submode) {
    (void)submode;
    // Ensure adaptive is always enabled for RX
    if (decoder_type_ == DecoderType::Fldigi) {
        multiDemod_fldigi_.setAdaptive(true);
    } else if (decoder_type_ == DecoderType::Gridtracker) {
        multiDemod_gt_->setAdaptive(true);
    }
}

void Decoder::setReverse(bool rev) {
    if (decoder_type_ == DecoderType::Fldigi) {
        multiDemod_fldigi_.setReverse(rev);
    } else if (decoder_type_ == DecoderType::Gridtracker) {
        multiDemod_gt_->setReverse(rev);
    }
}

void Decoder::setSquelch(double s) {
    if (decoder_type_ == DecoderType::Fldigi) {
        multiDemod_fldigi_.setSquelch(static_cast<float>(s));
    } else if (decoder_type_ == DecoderType::Gridtracker) {
        multiDemod_gt_->setSquelch(static_cast<float>(s));
    }
}

int Decoder::process(qint16 const* samples, int count, qint64 firstSample,
                     qint64 /*stopSample*/, int /*maxSteps*/, int lowFrequency,
                     int highFrequency, float centerFrequency, float /*tolerance*/) {
    if (count <= 0) return 0;

    std::vector<float> float_samples(count);
    for (int i = 0; i < count; ++i) {
        float_samples[i] = samples[i] / 32768.0f;
    }

    // Decode the whole receive passband, not just a band around the TX tone.
    // nfa can legitimately be 0, so only clamp the low edge away from DC/hum.
    int low = std::max(50, lowFrequency);
    int high = (highFrequency > low + 50) ? highFrequency : low + 2700;

    // Process with the selected decoder
    if (decoder_type_ == DecoderType::Fldigi) {
        // fldigi is a single-signal demod. Use one channel at the selected RX
        // tone (GT/DeepCW provide wide passband/multi-channel decoding).
        const int center = centerFrequency > 0.0f
            ? static_cast<int>(std::lround(centerFrequency)) : 800;
        if (center != fldigiLow_ || center != fldigiHigh_) {
            multiDemod_fldigi_.init(1, static_cast<float>(center), static_cast<float>(center));
            fldigiLow_ = center;
            fldigiHigh_ = center;
        }
        multiDemod_fldigi_.process(float_samples.data(), count);
    } else if (decoder_type_ == DecoderType::Gridtracker) {
        multiDemod_gt_->setRange(low, high);
        multiDemod_gt_->rx_process(float_samples.data(), count, 0.0f);
    }
#ifdef WSJT_HAVE_DEEPCW
    else if (decoder_type_ == DecoderType::DeepCw) {
        ensureDeepCwStarted();
        if (deepcw_started_) {
            deepcw_->set_center_frequency(centerFrequency > 0.0f ? centerFrequency : 800.0);
            deepcw_->process(float_samples.data(), count);
        }
    }
#endif

    nextRequiredSample_ = firstSample + count;

    double elapsed_seconds = static_cast<double>(firstSample - gridOrigin_) / 12000.0;

    if (decoder_type_ == DecoderType::Fldigi) {
        auto results = multiDemod_fldigi_.get_results();
        for (const auto& r : results) {
            if (r.channel < 0 || r.channel >= static_cast<int>(channels_.size())) continue;
            // fldigi's complete flag marks a word gap; the line continues.
            feedText(r.channel, r.text, r.frequency_hz, r.snr_db, r.wpm,
                     elapsed_seconds, firstSample);
        }
    } else if (decoder_type_ == DecoderType::Gridtracker) {
        auto results = multiDemod_gt_->get_results();
        for (const auto& r : results) {
            int channel = r.channel;
            if (channel < 0 || channel >= static_cast<int>(channels_.size())) continue;
            if (r.replace) {
                replaceText(channel, r.text, r.frequency_hz, r.snr_db, r.wpm,
                            elapsed_seconds, firstSample);
            } else {
                feedText(channel, r.text, r.frequency_hz, r.snr_db, r.wpm,
                         elapsed_seconds, firstSample);
            }
            // GT completes on a new transmission / channel close.
            if (r.complete) completeChannel(channel);
        }
    }
#ifdef WSJT_HAVE_DEEPCW
    else if (decoder_type_ == DecoderType::DeepCw) {
        if (deepcw_started_) {
            auto results = deepcw_->take_results();
            for (const auto& r : results) {
                feedText(r.channel, r.text, r.frequency_hz, r.snr_db, r.wpm,
                         elapsed_seconds, firstSample);
                if (r.complete) completeChannel(r.channel);
            }
        }
    }
#endif

    // Each decoder emits characters as they are decoded. A message ends after
    // a real pause, not at every word gap, so CW shows a growing live line.
    for (size_t i = 0; i < channels_.size(); ++i) {
        ChannelState& ch = channels_[i];
        if (!ch.active) continue;
        if (firstSample - ch.lastTextSample > idleSamples) {
            ch.idleFrames++;
            if (ch.idleFrames > 2) completeChannel(static_cast<int>(i));
        }
    }

    return count;
}

qint64 Decoder::generateMessageId(int channelId) {
    // One id per transmission, not per channel: a station that transmits again
    // on the same channel must get a new line + timestamp in the UI.
    const qint64 serial = static_cast<qint64>(++nextMessageSerial_);
    return (sessionId_ << 40)
        | ((static_cast<qint64>(channelId) & 0xFFLL) << 32)
        | (serial & 0xFFFFFFFFLL);
}

void Decoder::feedText(int channelId, std::string const& text, float frequency,
                       float snr, int wpm, double elapsedSeconds, qint64 firstSample) {
    if (channelId < 0 || channelId >= static_cast<int>(channels_.size())) return;

    ChannelState& ch = channels_[channelId];
    if (!ch.active) {
        ch.active = true;
        ch.messageId = generateMessageId(channelId);
        ch.startSeconds = elapsedSeconds;
        ch.frequency = frequency;
        ch.snr = snr;
        ch.wpm = wpm;
        ch.lastTextSample = firstSample;
        ch.idleFrames = 0;
    } else {
        ch.frequency = frequency;
        ch.snr = snr;
        ch.wpm = wpm;
    }

    for (char c : text) {
        if (ch.text.isEmpty() && c == ' ') continue; // no leading space on a new line
        ch.text += QChar(c);
        ch.lastTextSample = firstSample;
        ch.idleFrames = 0;
        emitPartial(channelId);
    }
}

void Decoder::replaceText(int channelId, std::string const& text, float frequency,
                          float snr, int wpm, double elapsedSeconds, qint64 firstSample) {
    if (channelId < 0 || channelId >= static_cast<int>(channels_.size())) return;

    ChannelState& ch = channels_[channelId];
    if (!ch.active) {
        ch.active = true;
        ch.messageId = generateMessageId(channelId);
        ch.startSeconds = elapsedSeconds;
        ch.idleFrames = 0;
    }
    ch.frequency = frequency;
    ch.snr = snr;
    ch.wpm = wpm;
    ch.lastTextSample = firstSample;

    QString revised = QString::fromStdString(text);
    while (revised.startsWith(' ')) revised.remove(0, 1);
    ch.text = revised;
    emitPartial(channelId);
}

void Decoder::emitPartial(int channelId) {
    if (channelId < 0 || channelId >= static_cast<int>(channels_.size())) return;
    ChannelState& ch = channels_[channelId];
    if (!ch.active || ch.text.isEmpty()) return;

    Jtty::MessageUpdate update;
    update.messageId = ch.messageId;
    update.text = ch.text;
    update.frequency = ch.frequency;
    update.snr = ch.snr;
    update.sequenceStart = static_cast<float>(ch.startSeconds);
    update.complete = false;
    pendingUpdates_.append(update);
}

void Decoder::completeChannel(int channelId) {
    if (channelId < 0 || channelId >= static_cast<int>(channels_.size())) return;
    ChannelState& ch = channels_[channelId];
    if (!ch.active) return;

    if (!ch.text.trimmed().isEmpty()) {
        Jtty::MessageUpdate update;
        update.messageId = ch.messageId;
        update.text = ch.text;
        update.frequency = ch.frequency;
        update.snr = ch.snr;
        update.sequenceStart = static_cast<float>(ch.startSeconds);
        update.complete = true;
        pendingUpdates_.append(update);
    }

    ch.active = false;
    ch.text.clear();
    ch.idleFrames = 0;
}

QVector<Jtty::MessageUpdate> Decoder::takeUpdates() {
    QVector<Jtty::MessageUpdate> updates = pendingUpdates_;
    pendingUpdates_.clear();
    return updates;
}

} // namespace Cw