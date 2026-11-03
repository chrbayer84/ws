#include "cw_multi_demod.hpp"
#include <algorithm>

namespace Cw {

template <typename T>
static inline T clamp_val(T v, T lo, T hi) {
    return std::max(lo, std::min(v, hi));
}

CwMultiDemod::CwMultiDemod() {
    demods_.resize(MAX_CHANNELS);
}

void CwMultiDemod::setWpm(int wpm) {
    for (auto& d : demods_) d.setWpm(wpm);
}

void CwMultiDemod::setBandwidth(int hz) {
    for (auto& d : demods_) d.setBandwidth(hz);
}

void CwMultiDemod::setSquelch(float db) {
    for (auto& d : demods_) d.setSquelch(db);
}

void CwMultiDemod::setReverse(bool rev) {
    for (auto& d : demods_) d.setReverse(rev);
}

void CwMultiDemod::setAdaptive(bool adaptive) {
    for (auto& d : demods_) d.setAdaptive(adaptive);
}

void CwMultiDemod::init(int num_channels, float low_hz, float high_hz) {
    num_channels_ = clamp_val(num_channels, 1, MAX_CHANNELS);
    if (high_hz <= low_hz) high_hz = low_hz + 100.0f;
    low_freq_hz_ = std::max(0.0f, low_hz);
    high_freq_hz_ = high_hz;
    channel_spacing_hz_ = (num_channels_ > 1)
        ? (high_freq_hz_ - low_freq_hz_) / static_cast<float>(num_channels_ - 1)
        : 0.0f;

    channel_freqs_.resize(num_channels_);
    for (int i = 0; i < num_channels_; ++i) {
        channel_freqs_[i] = low_freq_hz_ + i * channel_spacing_hz_;
        demods_[i].setToneFrequency(channel_freqs_[i]);
        demods_[i].rx_init();
    }
}

void CwMultiDemod::process(const float* samples, int count) {
    for (int ch = 0; ch < num_channels_; ++ch) {
        demods_[ch].rx_process(samples, count, channel_freqs_[ch]);
    }
}

std::vector<CwMultiDemodResult> CwMultiDemod::get_results() {
    std::vector<CwMultiDemodResult> all_results;

    for (int ch = 0; ch < num_channels_; ++ch) {
        auto results = demods_[ch].get_results();
        for (auto& r : results) {
            CwMultiDemodResult mr;
            mr.text = r.text;
            mr.frequency_hz = r.frequency_hz;
            mr.snr_db = r.snr_db;
            mr.wpm = r.wpm;
            mr.channel = ch;
            mr.complete = r.complete;
            all_results.push_back(mr);
        }
    }

    // A single signal leaks into neighboring 50 Hz channels. Keep only the
    // strongest channel in a local group so the UI does not show the same
    // text many times (and weak neighbors' noise decodes are dropped).
    if (all_results.size() < 2) return all_results;

    const float radius = std::max(50.0f, channel_spacing_hz_ * 1.5f);
    std::vector<CwMultiDemodResult> filtered;
    filtered.reserve(all_results.size());
    for (auto const& r : all_results) {
        if (r.snr_db <= 0.0f) {
            filtered.push_back(r);
            continue;
        }
        float best = r.snr_db;
        for (auto const& other : all_results) {
            if (&other == &r || other.snr_db <= 0.0f) continue;
            if (std::abs(other.frequency_hz - r.frequency_hz) <= radius
                && other.snr_db > best) {
                best = other.snr_db;
            }
        }
        if (r.snr_db + 1.0f < best) continue;
        filtered.push_back(r);
    }

    return filtered;
}

} // namespace Cw
