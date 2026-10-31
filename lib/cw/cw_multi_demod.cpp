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

void CwMultiDemod::init(int num_channels, float base_freq_hz, float channel_spacing_hz) {
    num_channels_ = clamp_val(num_channels, 1, MAX_CHANNELS);
    base_freq_hz_ = base_freq_hz;
    channel_spacing_hz_ = channel_spacing_hz;

    channel_freqs_.resize(num_channels_);
    for (int i = 0; i < num_channels_; ++i) {
        channel_freqs_[i] = base_freq_hz_ + i * channel_spacing_hz_;
        demods_[i].setToneFrequency(channel_freqs_[i]);
        demods_[i].rx_init();
        demods_[i].setWpm(20);
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

    return all_results;
}

} // namespace Cw