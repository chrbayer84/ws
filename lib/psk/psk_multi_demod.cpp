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
    if (lowFreq_ != low || highFreq_ != high) {
        lowFreq_ = low;
        highFreq_ = high;
        reset();
    }
}

void PskMultiDemod::setCenterFrequency(double f0) {
    if (std::abs(centerFreq_ - f0) > 1.0) {
        centerFreq_ = f0;
        if (!channels_.empty()) {
            channels_[0].frequency = f0;
            channels_[0].active = true;
            if (!channels_[0].modem) {
                channels_[0].modem = std::unique_ptr<PskModem>(new PskModem(sampleRate_));
            }
            channels_[0].modem->setFrequency(f0);
            channels_[0].modem->rxInit();
        }
    }
}

void PskMultiDemod::setSquelch(double s) {
    if (std::abs(squelch_ - s) > 0.01) {
        squelch_ = s;
        for (auto& ch : channels_) {
            if (ch.modem) ch.modem->setSquelch(s);
        }
    }
}

void PskMultiDemod::setReverse(bool rev) {
    if (reverse_ != rev) {
        reverse_ = rev;
        for (auto& ch : channels_) {
            if (ch.modem) ch.modem->setReverse(rev);
        }
    }
}

void PskMultiDemod::reset() {
    double span = highFreq_ - lowFreq_;
    double step = span / static_cast<double>(MAX_CHANNELS > 1 ? MAX_CHANNELS - 1 : 1);

    // Channel 0 directly monitors the selected QSO center frequency
    if (!channels_.empty()) {
        channels_[0].active = true;
        channels_[0].frequency = centerFreq_;
        channels_[0].timeout = 0;
        channels_[0].idleFrames = 0;
        if (!channels_[0].modem) {
            channels_[0].modem = std::unique_ptr<PskModem>(new PskModem(sampleRate_));
        }
        channels_[0].modem->setFrequency(centerFreq_);
        channels_[0].modem->setReverse(reverse_);
        channels_[0].modem->setSquelch(squelch_);
        channels_[0].modem->rxInit();
        channels_[0].text.clear();
        channels_[0].hasText = false;
    }

    // Channels 1..MAX_CHANNELS-1 cover the entire passband
    for (int i = 1; i < MAX_CHANNELS && i < static_cast<int>(channels_.size()); ++i) {
        channels_[i].active = true;
        channels_[i].frequency = lowFreq_ + (i - 0.5) * step;
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
                DecodeResult result;
                result.channelId = i;
                result.frequency = modem->getFrequency();
                result.text = newText;
                result.snr = modem->getSNR();
                result.complete = false;

                #pragma omp critical
                {
                    pendingDecodes_.push_back(result);
                }
            }
        }
    }
}

std::vector<PskMultiDemod::DecodeResult> PskMultiDemod::takeDecodes() {
    std::vector<DecodeResult> result;
    #pragma omp critical
    {
        result = std::move(pendingDecodes_);
        pendingDecodes_.clear();
    }
    return result;
}

} // namespace Psk