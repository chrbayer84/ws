#include "cw_demod.hpp"
#include "cw_morse_table.hpp"
#include <cmath>
#include <algorithm>
#include <numeric>
#include <fftw3.h>

namespace Cw {

template <typename T>
static inline T clamp_val(T v, T lo, T hi) {
    return std::max(lo, std::min(v, hi));
}

CwDemod::CwDemod() {
    fft_buffer_.resize(FFT_SIZE);
    filter_response_.resize(FFT_SIZE / 2 + 1);
    power_buffer_.resize(FFT_SIZE);
    filtered_power_.resize(FFT_SIZE);
    rx_init();
}

CwDemod::~CwDemod() = default;

void CwDemod::setWpm(int wpm) {
    wpm_ = clamp_val(wpm, 5, 50);
    const double dot_sec = 1.2 / wpm_;
    dot_samples_ = static_cast<int>(dot_sec * SAMPLE_RATE + 0.5);
    dash_samples_ = dot_samples_ * 3;
    elem_space_samples_ = dot_samples_;
    char_space_samples_ = dot_samples_ * 3;
    word_space_samples_ = dot_samples_ * 7;
    two_dots_samples_ = dot_samples_ * 2;
}

void CwDemod::setBandwidth(int hz) {
    bandwidth_ = clamp_val(hz, 20, 500);
    float bw_norm = bandwidth_ / static_cast<float>(SAMPLE_RATE);
    for (size_t i = 0; i < filter_response_.size(); ++i) {
        float f = static_cast<float>(i) / FFT_SIZE;
        float df = std::abs(f - tone_freq_hz_ / SAMPLE_RATE);
        if (df < bw_norm * 0.5f) {
            filter_response_[i] = 1.0f;
        } else if (df < bw_norm) {
            filter_response_[i] = 0.5f * (1.0f + std::cos(M_PI * (df - bw_norm * 0.5f) / (bw_norm * 0.5f)));
        } else {
            filter_response_[i] = 0.0f;
        }
    }
}

void CwDemod::setSquelch(float db) {
    squelch_db_ = clamp_val(db, 0.0f, 30.0f);
}

void CwDemod::setReverse(bool rev) {
    reverse_ = rev;
}

void CwDemod::setAdaptive(bool adaptive) {
    adaptive_ = adaptive;
}

void CwDemod::rx_init() {
    setWpm(wpm_);
    setBandwidth(bandwidth_);

    mix_phase_ = 0.0;
    mix_phase_inc_ = 2.0 * M_PI * tone_freq_hz_ / SAMPLE_RATE;

    std::fill(power_buffer_.begin(), power_buffer_.end(), 0.0f);
    std::fill(filtered_power_.begin(), filtered_power_.end(), 0.0f);
    elements_.clear();
    decode_buffer_.clear();
    results_.clear();

    state_ = RxState::IDLE;
    tone_start_sample_ = 0;
    silence_start_sample_ = 0;
    noise_floor_ = 0.0f;
    signal_peak_ = 0.0f;

    dot_tracking_ = dot_samples_;
    dash_tracking_ = dash_samples_;
    adaptive_count_ = 0;

    samples_processed_ = 0;
}

void CwDemod::reset() {
    rx_init();
}

void CwDemod::mix_down(const float* samples, int count, float center_freq_hz) {
    float freq_offset = center_freq_hz - tone_freq_hz_;
    double phase_inc = 2.0 * M_PI * freq_offset / SAMPLE_RATE;

    for (int i = 0; i < count; ++i) {
        float real = samples[i] * std::cos(mix_phase_);
        float imag = -samples[i] * std::sin(mix_phase_);
        fft_buffer_[i] = std::complex<float>(real, imag);
        mix_phase_ += phase_inc;
        if (mix_phase_ >= 2.0 * M_PI) mix_phase_ -= 2.0 * M_PI;
    }
}

void CwDemod::apply_matched_filter() {
    fftwf_plan plan = fftwf_plan_dft_1d(FFT_SIZE,
        reinterpret_cast<fftwf_complex*>(fft_buffer_.data()),
        reinterpret_cast<fftwf_complex*>(fft_buffer_.data()),
        FFTW_FORWARD, FFTW_ESTIMATE);
    fftwf_execute(plan);
    fftwf_destroy_plan(plan);

    for (size_t i = 0; i < filter_response_.size(); ++i) {
        fft_buffer_[i] *= filter_response_[i];
    }

    plan = fftwf_plan_dft_1d(FFT_SIZE,
        reinterpret_cast<fftwf_complex*>(fft_buffer_.data()),
        reinterpret_cast<fftwf_complex*>(fft_buffer_.data()),
        FFTW_BACKWARD, FFTW_ESTIMATE);
    fftwf_execute(plan);
    fftwf_destroy_plan(plan);

    float scale = 1.0f / FFT_SIZE;
    for (int i = 0; i < FFT_SIZE; ++i) {
        float mag = std::abs(fft_buffer_[i]) * scale;
        power_buffer_[i] = mag * mag;
    }
}

void CwDemod::detect_elements() {
    const float beta = 0.001f;

    for (int i = 0; i < FFT_SIZE; ++i) {
        float p = power_buffer_[i];
        if (p > signal_peak_) signal_peak_ = p;
        noise_floor_ = noise_floor_ * (1.0f - beta) + p * beta;

        float snr = (signal_peak_ > noise_floor_ && noise_floor_ > 0.0f)
            ? 10.0f * std::log10f(signal_peak_ / noise_floor_) : 0.0f;

        bool tone_present = snr > squelch_db_;

        if (reverse_) tone_present = !tone_present;

        switch (state_) {
            case RxState::IDLE:
                if (tone_present) {
                    state_ = RxState::IN_TONE;
                    tone_start_sample_ = samples_processed_ + i;
                } else {
                    silence_start_sample_ = samples_processed_ + i;
                }
                break;

            case RxState::IN_TONE:
                if (!tone_present) {
                    int tone_duration = samples_processed_ + i - tone_start_sample_;
                    if (tone_duration > dot_samples_ / 4) {
                        elements_.push_back({true, tone_duration, signal_peak_});
                    }
                    state_ = RxState::AFTER_TONE;
                    silence_start_sample_ = samples_processed_ + i;
                    signal_peak_ = 0.0f;
                }
                break;

            case RxState::AFTER_TONE:
                if (tone_present) {
                    int space_duration = samples_processed_ + i - silence_start_sample_;
                    if (space_duration > dot_samples_ / 4) {
                        elements_.push_back({false, space_duration, noise_floor_});
                    }
                    state_ = RxState::IN_TONE;
                    tone_start_sample_ = samples_processed_ + i;
                    signal_peak_ = 0.0f;
                }
                break;
        }
    }
    samples_processed_ += FFT_SIZE;
}

void CwDemod::decode_elements() {
    std::vector<float> current_char_weights;
    std::string current_word;

    for (const auto& elem : elements_) {
        if (elem.is_tone) {
            float ratio = static_cast<float>(elem.duration_samples) / dot_samples_;
            float weight = (ratio > 1.5f) ? 1.0f : 0.33f;
            current_char_weights.push_back(weight);

            if (adaptive_ && adaptive_count_ < 100) {
                if (ratio > 1.5f) {
                    dash_tracking_ = dash_tracking_ * 0.9 + elem.duration_samples * 0.1;
                } else {
                    dot_tracking_ = dot_tracking_ * 0.9 + elem.duration_samples * 0.1;
                }
                adaptive_count_++;
                if (adaptive_count_ >= 20) {
                    dot_samples_ = static_cast<int>(dot_tracking_ + 0.5);
                    dash_samples_ = static_cast<int>(dash_tracking_ + 0.5);
                    elem_space_samples_ = dot_samples_;
                    char_space_samples_ = dot_samples_ * 3;
                    word_space_samples_ = dot_samples_ * 7;
                    two_dots_samples_ = dot_samples_ * 2;
                }
            }
        } else {
            int space_ratio = elem.duration_samples / dot_samples_;

            if (space_ratio >= 5) {
                if (!current_char_weights.empty()) {
                    decode_buffer_ += match_pattern(current_char_weights);
                    current_char_weights.clear();
                }
                if (!decode_buffer_.empty() && decode_buffer_.back() != ' ') {
                    decode_buffer_ += ' ';
                }
            } else if (space_ratio >= 2) {
                if (!current_char_weights.empty()) {
                    decode_buffer_ += match_pattern(current_char_weights);
                    current_char_weights.clear();
                }
            }
        }
    }

    if (!current_char_weights.empty()) {
        decode_buffer_ += match_pattern(current_char_weights);
    }

    if (!decode_buffer_.empty()) {
        CwDecodeResult result;
        result.text = decode_buffer_;
        result.frequency_hz = tone_freq_hz_;
        result.wpm = wpm_;
        result.snr_db = (signal_peak_ > noise_floor_ && noise_floor_ > 0.0f)
            ? 10.0f * std::log10f(signal_peak_ / noise_floor_) : 0.0f;
        result.complete = false;
        results_.push_back(result);
        decode_buffer_.clear();
    }

    elements_.clear();
}

std::string CwDemod::match_pattern(const std::vector<float>& weights) {
    if (weights.empty()) return "";

    float best_diff = 1e9f;
    std::string best_match = "?";

    for (const auto& sym : get_morse_table()) {
        if (sym.weights.size() != weights.size()) continue;

        float diff = 0.0f;
        for (size_t i = 0; i < weights.size(); ++i) {
            diff += std::abs(weights[i] - sym.weights[i]);
        }

        if (diff < best_diff) {
            best_diff = diff;
            best_match = decode_morse(sym.representation);
        }
    }

    return best_match;
}

void CwDemod::flush_decode_buffer() {
    if (!decode_buffer_.empty()) {
        CwDecodeResult result;
        result.text = decode_buffer_;
        result.frequency_hz = tone_freq_hz_;
        result.wpm = wpm_;
        result.snr_db = (signal_peak_ > noise_floor_ && noise_floor_ > 0.0f)
            ? 10.0f * std::log10f(signal_peak_ / noise_floor_) : 0.0f;
        result.complete = true;
        results_.push_back(result);
        decode_buffer_.clear();
    }
}

void CwDemod::rx_process(const float* samples, int count, float center_freq_hz) {
    const int hop_size = FFT_SIZE / 2;

    for (int offset = 0; offset < count; offset += hop_size) {
        int chunk = std::min(hop_size, count - offset);

        std::fill(fft_buffer_.begin(), fft_buffer_.end(), std::complex<float>(0, 0));
        mix_down(samples + offset, chunk, center_freq_hz);
        apply_matched_filter();
        detect_elements();

        if (elements_.size() > 10) {
            decode_elements();
        }
    }
}

std::vector<CwDecodeResult> CwDemod::get_results() {
    flush_decode_buffer();
    auto results = results_;
    results_.clear();
    return results;
}

} // namespace Cw