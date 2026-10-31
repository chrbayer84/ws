#include "cw_demod.hpp"
#include "cw_morse_table.hpp"
#include <cmath>
#include <algorithm>
#include <numeric>

namespace Cw {

template <typename T>
static inline T clamp_val(T v, T lo, T hi) {
    return std::max(lo, std::min(v, hi));
}

CwDemod::CwDemod() {
    filtered_samples_.resize(FFT_SIZE);
    envelope_.resize(FFT_SIZE);
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

void CwDemod::setToneFrequency(float hz) {
    tone_freq_hz_ = clamp_val(hz, 300.0f, 1200.0f);
}

void CwDemod::rx_init() {
    setWpm(wpm_);
    setBandwidth(bandwidth_);

    // Design bandpass filter (2nd order Butterworth)
    float fc = tone_freq_hz_ / SAMPLE_RATE;
    float bw = bandwidth_ / static_cast<float>(SAMPLE_RATE);
    float R = std::tan(M_PI * bw);
    float C = std::cos(2.0f * M_PI * fc);
    float D = 2.0f * C;
    float beta_num = 1.0f - R;
    float beta_den = 1.0f + R;
    float beta = 0.5f * beta_num / beta_den;
    float gamma = (0.5f + beta) * C;
    float alpha = (0.5f + beta - gamma) / 0.5f;

    bp_filter_.b0 = alpha;
    bp_filter_.b1 = 0.0f;
    bp_filter_.b2 = -alpha;
    bp_filter_.a1 = -D * beta;
    bp_filter_.a2 = 2.0f * beta;

    // Normalize bandpass filter to unity gain at center frequency
    float w0 = 2.0f * M_PI * fc;
    float z_cos = std::cos(w0);
    float z_sin = std::sin(w0);
    float cos2 = std::cos(2.0f * w0);
    float sin2 = std::sin(2.0f * w0);
    float num_real = bp_filter_.b0 + bp_filter_.b2 * cos2;
    float num_imag = -bp_filter_.b2 * sin2;
    float num_mag = std::sqrt(num_real * num_real + num_imag * num_imag);
    float den_real = 1.0f + bp_filter_.a1 * z_cos + bp_filter_.a2 * cos2;
    float den_imag = -bp_filter_.a1 * z_sin - bp_filter_.a2 * sin2;
    float den_mag = std::sqrt(den_real * den_real + den_imag * den_imag);
    float gain = num_mag / den_mag;
    if (gain > 0.0f) {
        float inv_gain = 1.0f / gain;
        bp_filter_.b0 *= inv_gain;
        bp_filter_.b1 *= inv_gain;
        bp_filter_.b2 *= inv_gain;
    }
    bp_filter_.reset();

    // Envelope detector: fast attack, tuned release for CW element separation
    env_alpha_ = 0.9f;   // attack
    env_beta_ = 0.95f;   // release

    std::fill(filtered_samples_.begin(), filtered_samples_.end(), 0.0f);
    std::fill(envelope_.begin(), envelope_.end(), 0.0f);
    elements_.clear();
    decode_buffer_.clear();
    results_.clear();

    state_ = RxState::IDLE;
    tone_start_sample_ = 0;
    silence_start_sample_ = 0;
    noise_floor_ = 0.01f;
    signal_peak_ = 0.0f;
    env_state_ = 0.0f;

    dot_tracking_ = dot_samples_;
    dash_tracking_ = dash_samples_;
    adaptive_count_ = 0;

    samples_processed_ = 0;
}

void CwDemod::reset() {
    rx_init();
}

void CwDemod::apply_bandpass(const float* samples, int count) {
    for (int i = 0; i < count; ++i) {
        filtered_samples_[i] = bp_filter_.process(samples[i]);
    }
}

void CwDemod::envelope_detect(const float* samples, int count) {
    for (int i = 0; i < count; ++i) {
        float x = std::abs(samples[i]);
        if (x > env_state_) {
            env_state_ = env_alpha_ * env_state_ + (1.0f - env_alpha_) * x;
        } else {
            env_state_ = env_beta_ * env_state_ + (1.0f - env_beta_) * x;
        }
        envelope_[i] = env_state_;
    }
}

void CwDemod::detect_elements(int count) {
    for (int i = 0; i < count; ++i) {
        float env = envelope_[i];
        bool tone_present = env > 0.15f;

        if (reverse_) tone_present = !tone_present;

        switch (state_) {
            case RxState::IDLE:
                if (tone_present) {
                    state_ = RxState::IN_TONE;
                    tone_start_sample_ = samples_processed_ + i;
                    signal_peak_ = env;
                } else {
                    silence_start_sample_ = samples_processed_ + i;
                    noise_floor_ = noise_floor_ * 0.999f + env * 0.001f;
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
                    noise_floor_ = env;
                } else {
                    signal_peak_ = std::max(signal_peak_, env);
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
                    signal_peak_ = env;
                } else {
                    noise_floor_ = noise_floor_ * 0.9f + env * 0.1f;
                }
                break;
        }
    }
    samples_processed_ += count;
}

float CwDemod::compute_snr() {
    if (signal_peak_ <= noise_floor_ || noise_floor_ <= 0.0f) return 0.0f;
    return 10.0f * log10f(signal_peak_ / noise_floor_);
}

void CwDemod::decode_elements() {
    std::vector<float> current_char_weights;

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
        result.snr_db = compute_snr();
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

    // Reject poor matches (too much error)
    if (best_diff > weights.size() * 0.5f) {
        return "?";
    }

    return best_match;
}

void CwDemod::flush_decode_buffer() {
    if (!decode_buffer_.empty()) {
        CwDecodeResult result;
        result.text = decode_buffer_;
        result.frequency_hz = tone_freq_hz_;
        result.wpm = wpm_;
        result.snr_db = compute_snr();
        result.complete = true;
        results_.push_back(result);
        decode_buffer_.clear();
    }
}

void CwDemod::rx_process(const float* samples, int count, float /*center_freq_hz*/) {
    const int chunk_size = 512;

    for (int offset = 0; offset < count; offset += chunk_size) {
        int chunk = std::min(chunk_size, count - offset);

        apply_bandpass(samples + offset, chunk);
        envelope_detect(filtered_samples_.data(), chunk);
        detect_elements(chunk);

        if (elements_.size() > 10) {
            decode_elements();
        }
    }
    // Process any remaining elements
    if (!elements_.empty()) {
        decode_elements();
    }
}

std::vector<CwDecodeResult> CwDemod::get_results() {
    flush_decode_buffer();
    auto results = results_;
    results_.clear();
    return results;
}

} // namespace Cw