#include "CwDecoder.hpp"
#include <algorithm>
#include <cmath>

namespace Cw {

template <typename T>
static inline T clamp_val(T v, T lo, T hi) {
    return std::max(lo, std::min(v, hi));
}

Decoder::Decoder() = default;

Decoder::~Decoder() = default;

void Decoder::begin(qint64 sessionId, qint64 gridOrigin, qint64 firstSearch, int) {
    sessionId_ = sessionId;
    gridOrigin_ = gridOrigin;
    nextRequiredSample_ = firstSearch;

    multiDemod_.init(16, 300.0f, 50.0f);
    multiDemod_.setWpm(20);
    multiDemod_.setBandwidth(100);
    multiDemod_.setSquelch(5.0);
    multiDemod_.setAdaptive(true);

    channels_.assign(16, ChannelState());
    pendingUpdates_.clear();
}

void Decoder::setSubmode(const QString& submode) {
    if (submode.startsWith("CW-")) {
        bool ok = false;
        int wpm = submode.mid(3).toInt(&ok);
        if (ok && wpm >= 5 && wpm <= 50) {
            multiDemod_.setWpm(wpm);
        }
    }
}

void Decoder::setReverse(bool rev) {
    multiDemod_.setReverse(rev);
}

void Decoder::setSquelch(double s) {
    multiDemod_.setSquelch(static_cast<float>(clamp_val(s, 0.0, 30.0)));
}

int Decoder::process(qint16 const* samples, int count, qint64 firstSample,
                     qint64 /*stopSample*/, int /*maxSteps*/, int /*lowFrequency*/,
                     int /*highFrequency*/, float /*centerFrequency*/, float /*tolerance*/) {
    if (count <= 0) return 0;

    std::vector<float> float_samples(count);
    for (int i = 0; i < count; ++i) {
        float_samples[i] = samples[i] / 32768.0f;
    }

    multiDemod_.process(float_samples.data(), count);

    nextRequiredSample_ = firstSample + count;

    auto results = multiDemod_.get_results();
    double elapsed_seconds = static_cast<double>(firstSample - gridOrigin_) / 12000.0;

    for (const auto& r : results) {
        if (r.channel < 0 || r.channel >= static_cast<int>(channels_.size())) continue;

        ChannelState& ch = channels_[r.channel];

        if (!ch.active) {
            ch.active = true;
            ch.messageId = generateMessageId(r.channel);
            ch.startSeconds = elapsed_seconds;
            ch.frequency = r.frequency_hz;
            ch.text = QString::fromStdString(r.text);
            ch.snr = r.snr_db;
            ch.wpm = r.wpm;
            ch.lastTextSample = firstSample;
            ch.idleFrames = 0;
        } else {
            ch.text += QString::fromStdString(r.text);
            ch.snr = r.snr_db;
            ch.wpm = r.wpm;
            ch.lastTextSample = firstSample;
            ch.idleFrames = 0;
        }

        if (r.complete) {
            flushChannelMessage(r.channel, r, true);
        }
    }

    for (size_t i = 0; i < channels_.size(); ++i) {
        ChannelState& ch = channels_[i];
        if (ch.active) {
            qint64 samples_since_text = firstSample - ch.lastTextSample;
            if (samples_since_text > idleSamples) {
                ch.idleFrames++;
                if (ch.idleFrames > 2) {
                    CwMultiDemodResult dummy;
                    dummy.text = ch.text.toStdString();
                    dummy.frequency_hz = static_cast<float>(ch.frequency);
                    dummy.snr_db = static_cast<float>(ch.snr);
                    dummy.wpm = ch.wpm;
                    dummy.channel = static_cast<int>(i);
                    dummy.complete = true;
                    flushChannelMessage(static_cast<int>(i), dummy, true);
                }
            }
        }
    }

    return count;
}

qint64 Decoder::generateMessageId(int channelId) {
    return (sessionId_ << 16) | (static_cast<qint64>(channelId) & 0xFFFF);
}

void Decoder::flushChannelMessage(int channelId, const CwMultiDemodResult&, bool complete) {
    if (channelId < 0 || channelId >= static_cast<int>(channels_.size())) return;

    ChannelState& ch = channels_[channelId];
    if (!ch.active) return;

    Jtty::MessageUpdate update;
    update.messageId = ch.messageId;
    update.text = ch.text;
    update.frequency = ch.frequency;
    update.snr = ch.snr;
    update.sequenceStart = static_cast<float>(ch.startSeconds);
    update.complete = complete;

    pendingUpdates_.append(update);

    if (complete) {
        ch.active = false;
        ch.text.clear();
        ch.idleFrames = 0;
    }
}

QVector<Jtty::MessageUpdate> Decoder::takeUpdates() {
    QVector<Jtty::MessageUpdate> updates = pendingUpdates_;
    pendingUpdates_.clear();
    return updates;
}

} // namespace Cw