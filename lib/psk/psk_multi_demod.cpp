#include "psk_multi_demod.hpp"
#include <omp.h>
#include <algorithm>
#include <cmath>

namespace Psk {

PskMultiDemod::PskMultiDemod(double sampleRate, int lowFreq, int highFreq)
    : sampleRate_(sampleRate), lowFreq_(lowFreq), highFreq_(highFreq),
      squelch_(5.0), reverse_(false) {
    channels_.resize(MAX_CHANNELS);
    reset();
}

PskMultiDemod::~PskMultiDemod() = default;

void PskMultiDemod::setSampleRate(double rate) {
    if (std::abs(sampleRate_ - rate) > 0.01) {
        sampleRate_ = rate;
        reset();
    }
}

void PskMultiDemod::setFrequencyRange(int low, int high) {
    lowFreq_ = low;
    highFreq_ = high;
    reset();
}

void PskMultiDemod::setSquelch(double s) {
    squelch_ = s;
    for (auto& ch : channels_) {
        if (ch.modem) ch.modem->setSquelch(s);
    }
}

void PskMultiDemod::setReverse(bool rev) {
    reverse_ = rev;
    for (auto& ch : channels_) {
        if (ch.modem) ch.modem->setReverse(rev);
    }
}

void PskMultiDemod::reset() {
    double span = highFreq_ - lowFreq_;
    double step = span / static_cast<double>(MAX_CHANNELS);

    for (int i = 0; i < MAX_CHANNELS; ++i) {
        channels_[i].active = true;
        channels_[i].frequency = lowFreq_ + (i + 0.5) * step;
        channels_[i].timeout = 0;
        channels_[i].idleFrames = 0;
        if (!channels_[i].modem) {
            channels_[i].modem = std::unique_ptr<PskModem>(new PskModem(sampleRate_));
        }
        channels_[i].modem->setFrequency(channels_[i].frequency);
        channels_[i].modem->setReverse(reverse_);
        channels_[i].modem->setSquelch(squelch_);
        channels_[i].modem->rxInit();
        channels_[i].text.clear();
        channels_[i].hasText = false;
    }
    pendingDecodes_.clear();
}

void PskMultiDemod::rxProcess(const int16_t* samples, int count) {
    if (!samples || count <= 0) return;

    std::vector<int> activeIndices;
    activeIndices.reserve(MAX_CHANNELS);
    for (int i = 0; i < MAX_CHANNELS; ++i) {
        if (channels_[i].active && channels_[i].modem) {
            activeIndices.push_back(i);
        }
    }

    #pragma omp parallel for schedule(dynamic)
    for (size_t idx = 0; idx < activeIndices.size(); ++idx) {
        int i = activeIndices[idx];
        Channel& ch = channels_[i];
        PskModem* modem = ch.modem.get();

        modem->rxProcess(samples, count);

        if (modem->hasOutput()) {
            std::string newText = modem->takeOutput();
            if (!newText.empty()) {
                ch.text += newText;
                ch.hasText = true;
                ch.idleFrames = 0;
            }
        } else {
            ch.idleFrames++;
        }

        double snr = modem->getSNR();
        bool dcd = modem->isDCD();

        if (dcd) {
            ch.timeout = 0;
        } else {
            ch.timeout++;
        }

        if (ch.idleFrames > 50 && ch.hasText && ch.text.size() >= 3) {
            DecodeResult result;
            result.channelId = i;
            result.frequency = ch.frequency;
            result.text = ch.text;
            result.snr = snr;
            result.complete = true;

            #pragma omp critical
            {
                pendingDecodes_.push_back(result);
            }
            ch.text.clear();
            ch.hasText = false;
        }

        if (ch.timeout > 200 && ch.hasText && ch.text.size() >= 3) {
            DecodeResult result;
            result.channelId = i;
            result.frequency = ch.frequency;
            result.text = ch.text;
            result.snr = snr;
            result.complete = true;

            #pragma omp critical
            {
                pendingDecodes_.push_back(result);
            }
            ch.text.clear();
            ch.hasText = false;
        }
    }
}

std::vector<PskMultiDemod::DecodeResult> PskMultiDemod::takeDecodes() {
    std::vector<DecodeResult> result = std::move(pendingDecodes_);
    pendingDecodes_.clear();
    return result;
}

} // namespace Psk