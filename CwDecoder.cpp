#include "CwDecoder.hpp"
#include <algorithm>
#include <cmath>

namespace Cw {

Decoder::Decoder() {
    multiDemod_gt_.reset(new CwGtDemod());
}

Decoder::~Decoder() = default;

void Decoder::reinit() {
    if (decoder_type_ == DecoderType::Fldigi) {
        multiDemod_fldigi_.init(16, 300.0f, 50.0f);
        multiDemod_fldigi_.setWpm(20);
        multiDemod_fldigi_.setBandwidth(100);
        multiDemod_fldigi_.setSquelch(5.0);
        multiDemod_fldigi_.setAdaptive(true);
        multiDemod_fldigi_.setReverse(false);
    } else {
        // Gridtracker decoder
        multiDemod_gt_->setWpm(20);
        multiDemod_gt_->setBandwidth(100);
        multiDemod_gt_->setSquelch(5.0f);
        multiDemod_gt_->setAdaptive(true);
        multiDemod_gt_->setReverse(false);
    }
}

void Decoder::begin(qint64 sessionId, qint64 gridOrigin, qint64 firstSearch, int samplesPerSymbol) {
    (void)samplesPerSymbol;
    sessionId_ = sessionId;
    gridOrigin_ = gridOrigin;
    nextRequiredSample_ = firstSearch;

    reinit();

    channels_.assign(16, ChannelState());
    pendingUpdates_.clear();
}

void Decoder::setSubmode(const QString& submode) {
    (void)submode;
    // Ensure adaptive is always enabled for RX
    if (decoder_type_ == DecoderType::Fldigi) {
        multiDemod_fldigi_.setAdaptive(true);
    } else {
        multiDemod_gt_->setAdaptive(true);
    }
}

void Decoder::setReverse(bool rev) {
    if (decoder_type_ == DecoderType::Fldigi) {
        multiDemod_fldigi_.setReverse(rev);
    } else {
        multiDemod_gt_->setReverse(rev);
    }
}

void Decoder::setSquelch(double s) {
    if (decoder_type_ == DecoderType::Fldigi) {
        multiDemod_fldigi_.setSquelch(static_cast<float>(s));
    } else {
        multiDemod_gt_->setSquelch(static_cast<float>(s));
    }
}

int Decoder::process(qint16 const* samples, int count, qint64 firstSample,
                     qint64 /*stopSample*/, int /*maxSteps*/, int /*lowFrequency*/,
                     int /*highFrequency*/, float centerFrequency, float /*tolerance*/) {
    if (count <= 0) return 0;

    std::vector<float> float_samples(count);
    for (int i = 0; i < count; ++i) {
        float_samples[i] = samples[i] / 32768.0f;
    }

    // Process with the selected decoder
    if (decoder_type_ == DecoderType::Fldigi) {
        multiDemod_fldigi_.process(float_samples.data(), count);
    } else {
        multiDemod_gt_->rx_process(float_samples.data(), count, centerFrequency);
    }

    nextRequiredSample_ = firstSample + count;

    double elapsed_seconds = static_cast<double>(firstSample - gridOrigin_) / 12000.0;

    if (decoder_type_ == DecoderType::Fldigi) {
        auto results = multiDemod_fldigi_.get_results();
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
    } else {
        auto results = multiDemod_gt_->get_results();
        for (const auto& r : results) {
            int channel = r.channel;
            if (channel < 0 || channel >= static_cast<int>(channels_.size())) continue;

            ChannelState& ch = channels_[channel];

            if (!ch.active) {
                ch.active = true;
                ch.messageId = generateMessageId(channel);
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
                Cw::CwMultiDemodResult mdr;
                mdr.text = r.text;
                mdr.frequency_hz = r.frequency_hz;
                mdr.snr_db = r.snr_db;
                mdr.wpm = r.wpm;
                mdr.channel = r.channel;
                mdr.complete = r.complete;
                flushChannelMessage(channel, mdr, true);
            }
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