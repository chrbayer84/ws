#include "cw_modem.hpp"
#include "cw_morse_table.hpp"
#include <cmath>
#include <algorithm>

namespace Cw {

template <typename T>
static inline T clamp_val(T v, T lo, T hi) {
    return std::max(lo, std::min(v, hi));
}

CwModem::CwModem() {
    tx_init();
}

void CwModem::setWpm(int wpm) {
    wpm_ = clamp_val(wpm, 5, 50);
    tx_init();
}

void CwModem::setToneFrequency(float hz) {
    tone_hz_ = clamp_val(hz, 300.0f, 1200.0f);
    phase_inc_ = 2.0 * M_PI * tone_hz_ / SAMPLE_RATE;
}

void CwModem::setRiseTimeMs(float ms) {
    rise_time_ms_ = clamp_val(ms, 1.0f, 20.0f);
    build_edge_shape();
}

void CwModem::setReverse(bool rev) {
    reverse_ = rev;
}

void CwModem::tx_init() {
    const double dot_sec = 1.2 / wpm_;
    dot_samples_ = static_cast<int>(dot_sec * SAMPLE_RATE + 0.5);
    dash_samples_ = dot_samples_ * 3;
    elem_space_samples_ = dot_samples_;
    char_space_samples_ = dot_samples_ * 3;
    word_space_samples_ = dot_samples_ * 7;

    rise_samples_ = static_cast<int>(rise_time_ms_ * 0.001 * SAMPLE_RATE + 0.5);
    fall_samples_ = rise_samples_;

    rise_samples_ = std::min(rise_samples_, dot_samples_ / 2);
    fall_samples_ = std::min(fall_samples_, dot_samples_ / 2);

    phase_inc_ = 2.0 * M_PI * tone_hz_ / SAMPLE_RATE;
    phase_ = 0.0;

    build_edge_shape();
}

void CwModem::build_edge_shape() {
    edge_shape_.rise.resize(rise_samples_);
    edge_shape_.fall.resize(fall_samples_);

    for (int i = 0; i < rise_samples_; ++i) {
        double x = static_cast<double>(i) / (rise_samples_ - 1);
        edge_shape_.rise[i] = static_cast<float>((1.0 - std::cos(M_PI * x)) * 0.5);
    }
    for (int i = 0; i < fall_samples_; ++i) {
        double x = static_cast<double>(i) / (fall_samples_ - 1);
        edge_shape_.fall[i] = static_cast<float>((1.0 + std::cos(M_PI * x)) * 0.5);
    }
}

void CwModem::encode_text(const std::string& text) {
    encoded_elements_.clear();

    std::string morse = encode_string(text);
    if (morse.empty()) return;

    bool first_element = true;
    for (size_t i = 0; i < morse.size(); ++i) {
        char c = morse[i];
        if (c == '.') {
            if (!first_element) {
                encoded_elements_.emplace_back(false, elem_space_samples_);
            }
            encoded_elements_.emplace_back(true, dot_samples_);
            first_element = false;
        } else if (c == '-') {
            if (!first_element) {
                encoded_elements_.emplace_back(false, elem_space_samples_);
            }
            encoded_elements_.emplace_back(true, dash_samples_);
            first_element = false;
        } else if (c == ' ') {
            if (i + 1 < morse.size() && morse[i + 1] == ' ') {
                encoded_elements_.emplace_back(false, word_space_samples_);
                ++i;
            } else {
                encoded_elements_.emplace_back(false, char_space_samples_);
            }
            first_element = true;
        }
    }
}

void CwModem::generate_element(bool is_tone, int duration, float* output, int& pos, int max_samples) {
    if (pos >= max_samples) return;

    int samples = std::min(duration, max_samples - pos);
    float tone_amp = reverse_ ? -1.0f : 1.0f;

    if (is_tone) {
        int shaped = std::min(samples, rise_samples_ + fall_samples_);
        int steady = samples - shaped;

        for (int i = 0; i < std::min(shaped, rise_samples_); ++i) {
            float env = edge_shape_.rise[i];
            output[pos++] = tone_amp * env * std::sin(phase_);
            phase_ += phase_inc_;
            if (phase_ >= 2.0 * M_PI) phase_ -= 2.0 * M_PI;
        }

        for (int i = 0; i < steady; ++i) {
            output[pos++] = tone_amp * std::sin(phase_);
            phase_ += phase_inc_;
            if (phase_ >= 2.0 * M_PI) phase_ -= 2.0 * M_PI;
        }

        for (int i = 0; i < std::min(shaped - rise_samples_, fall_samples_); ++i) {
            float env = edge_shape_.fall[i];
            output[pos++] = tone_amp * env * std::sin(phase_);
            phase_ += phase_inc_;
            if (phase_ >= 2.0 * M_PI) phase_ -= 2.0 * M_PI;
        }
    } else {
        for (int i = 0; i < samples; ++i) {
            output[pos++] = 0.0f;
        }
    }
}

void CwModem::generate_space(int space_type, float* output, int& pos, int max_samples) {
    int samples = 0;
    switch (space_type) {
        case 1: samples = elem_space_samples_; break;
        case 3: samples = char_space_samples_; break;
        case 7: samples = word_space_samples_; break;
        default: samples = elem_space_samples_; break;
    }
    samples = std::min(samples, max_samples - pos);
    for (int i = 0; i < samples; ++i) {
        output[pos++] = 0.0f;
    }
}

int CwModem::tx_process(float* output, int max_samples, const std::string& text) {
    encode_text(text);
    int pos = 0;

    for (const auto& elem : encoded_elements_) {
        if (pos >= max_samples) break;
        generate_element(elem.first, elem.second, output, pos, max_samples);
    }

    return pos;
}

} // namespace Cw