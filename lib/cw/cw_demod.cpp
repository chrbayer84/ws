#include "cw_demod.hpp"
#include "cw_morse_table.hpp"
#include <cmath>
#include <algorithm>

namespace Cw {

namespace {

template <typename T>
inline T clamp_val(T v, T lo, T hi) {
    return std::max(lo, std::min(v, hi));
}

// Split a set of durations into two clusters and return the cluster means.
// Returns false when the spread doesn't look bimodal (e.g. all dits).
bool split_two(const std::deque<int>& v, float min_ratio, float& low, float& high) {
    if (v.size() < 2) return false;
    int mn = *std::min_element(v.begin(), v.end());
    int mx = *std::max_element(v.begin(), v.end());
    if (mn <= 0) return false;
    if (static_cast<float>(mx) / static_cast<float>(mn) < min_ratio) return false;

    float a = static_cast<float>(mn);
    float b = static_cast<float>(mx);
    for (int iter = 0; iter < 8; ++iter) {
        float sa = 0.0f, sb = 0.0f;
        int na = 0, nb = 0;
        for (int x : v) {
            if (std::abs(x - a) < std::abs(x - b)) {
                sa += x;
                ++na;
            } else {
                sb += x;
                ++nb;
            }
        }
        if (na) a = sa / na;
        if (nb) b = sb / nb;
    }
    low = std::min(a, b);
    high = std::max(a, b);
    return true;
}

} // namespace

CwDemod::CwDemod() {
    rx_init();
}

CwDemod::~CwDemod() = default;

void CwDemod::setWpm(int wpm) {
    wpm_ = clamp_val(wpm, 5, 50);
    dot_samples_ = static_cast<int>(14400.0 / wpm_ + 0.5);
    dash_samples_ = dot_samples_ * 3;
    char_gap_samples_ = dot_samples_ * 2;
    word_gap_samples_ = dot_samples_ * 5;
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
    tone_freq_hz_ = clamp_val(hz, 50.0f, 6000.0f);
}

void CwDemod::rx_init() {
    setWpm(wpm_);

    nco_step_ = 2.0 * M_PI * static_cast<double>(tone_freq_hz_) / SAMPLE_RATE;
    nco_phase_ = 0.0;

    float lp_fc = std::max(60.0f, static_cast<float>(bandwidth_));
    lp_alpha_ = 1.0f - std::exp(-2.0f * static_cast<float>(M_PI) * lp_fc / SAMPLE_RATE);

    lp_i_ = 0.0f;
    lp_q_ = 0.0f;
    noise_ = 0.001f;
    sig_ = 0.0f;
    key_ = false;
    last_snr_ = 0.0f;

    recent_marks_.clear();
    decode_buffer_.clear();
    char_weights_.clear();
    results_.clear();

    state_ = RxState::IDLE;
    tone_start_sample_ = 0;
    silence_start_sample_ = 0;
    char_finalized_ = false;
    word_added_ = false;
    samples_processed_ = 0;
}

void CwDemod::reset() {
    rx_init();
}

void CwDemod::process_samples(const float* samples, int count) {
    for (int i = 0; i < count; ++i) {
        const float x = samples[i];

        // Complex down-mix at the tone frequency.
        const float c = static_cast<float>(std::cos(nco_phase_));
        const float s = static_cast<float>(std::sin(nco_phase_));
        nco_phase_ += nco_step_;
        if (nco_phase_ >= 2.0 * M_PI) nco_phase_ -= 2.0 * M_PI;

        lp_i_ += lp_alpha_ * (x * c - lp_i_);
        lp_q_ += lp_alpha_ * (-x * s - lp_q_);
        const float env = 2.0f * std::sqrt(lp_i_ * lp_i_ + lp_q_ * lp_q_);

        // Signal/noise trackers: fast attack on marks, slow release, noise
        // follows only while the key is up.
        if (env > sig_) {
            sig_ += (env - sig_) * 0.15f;
        } else {
            sig_ -= (sig_ - env) * 0.010f;
        }
        if (!key_) {
            const float a = (env < noise_) ? 0.05f : 0.002f;
            noise_ += (env - noise_) * a;
        }

        const float span = sig_ - noise_;
        bool t = false;
        if (sig_ > noise_ * 2.5f && span > 0.0005f) {
            const float hi = noise_ + span * 0.55f;
            const float lo = noise_ + span * 0.40f;
            t = key_ ? (env > lo) : (env > hi);
        }
        if (reverse_) t = !t;

        const bool prev = key_;
        key_ = t;
        const int absn = samples_processed_ + i;

        if (t && !prev) {
            // Key down.
            if (state_ == RxState::AFTER_TONE) {
                const int space = absn - silence_start_sample_;
                if (space >= char_gap_samples_ && !char_finalized_) {
                    finalize_char();
                    char_finalized_ = true;
                    emit_buffer(false);
                }
            }
            state_ = RxState::IN_TONE;
            tone_start_sample_ = absn;
            char_finalized_ = false;
            word_added_ = false;
            if (sig_ > noise_ * 1.01f) {
                const float sn = 20.0f * std::log10(sig_ / noise_);
                last_snr_ += (sn - last_snr_) * 0.2f;
            }
        } else if (!t && prev) {
            // Key up: a mark just ended.
            const int tone = absn - tone_start_sample_;
            if (tone > dot_samples_ / 3) {
                const float ratio = static_cast<float>(tone) / std::max(1, dot_samples_);
                char_weights_.push_back(ratio > 1.5f ? 1.0f : 0.33f);
                recent_marks_.push_back(tone);
                while (recent_marks_.size() > 16) recent_marks_.pop_front();
                speed_learn();
            }
            state_ = RxState::AFTER_TONE;
            silence_start_sample_ = absn;
            char_finalized_ = false;
            word_added_ = false;
        } else if (!t && state_ == RxState::AFTER_TONE) {
            // Stay in the gap long enough -> the character is over.
            const int space = absn - silence_start_sample_;
            if (!char_finalized_ && space >= char_gap_samples_ && !char_weights_.empty()) {
                finalize_char();
                char_finalized_ = true;
                emit_buffer(false);
            }
            if (!word_added_ && space >= word_gap_samples_) {
                if (decode_buffer_.empty() || decode_buffer_.back() != ' ') {
                    decode_buffer_ += ' ';
                }
                word_added_ = true;
                emit_buffer(true);
            }
        }
    }

    samples_processed_ += count;
}

void CwDemod::speed_learn() {
    if (!adaptive_ || recent_marks_.empty()) return;

    int new_dot = dot_samples_;
    int new_dash = dash_samples_;

    float low = 0.0f, high = 0.0f;
    if (split_two(recent_marks_, 1.7f, low, high)) {
        new_dot = static_cast<int>(low + 0.5f);
        new_dash = static_cast<int>(high + 0.5f);
    } else {
        long sum = 0;
        for (int x : recent_marks_) sum += x;
        const float mean = static_cast<float>(sum) / static_cast<float>(recent_marks_.size());
        if (mean > dot_samples_ * 1.8f && mean < dot_samples_ * 4.5f) {
            new_dash = static_cast<int>(mean + 0.5f);
        } else {
            new_dot = static_cast<int>(mean + 0.5f);
        }
    }

    new_dot = clamp_val(new_dot, static_cast<int>(SAMPLE_RATE * 0.024),
                        static_cast<int>(SAMPLE_RATE * 0.240));
    new_dash = clamp_val(new_dash,
                         static_cast<int>(new_dot * 1.7f),
                         static_cast<int>(new_dot * 4.5f));

    dot_samples_ = new_dot;
    dash_samples_ = new_dash;
    char_gap_samples_ = dot_samples_ * 2;
    word_gap_samples_ = dot_samples_ * 5;

    const int w = static_cast<int>(14400.0 / dot_samples_ + 0.5);
    wpm_ = clamp_val(w, 5, 50);
}

void CwDemod::finalize_char() {
    if (!char_weights_.empty()) {
        decode_buffer_ += match_pattern(char_weights_);
        char_weights_.clear();
    }
}

void CwDemod::emit_buffer(bool complete) {
    if (decode_buffer_.empty()) return;

    const float snr = compute_snr();
    // Squelch: drop text that doesn't clear the configured SNR, but never
    // drop before a signal has been measured.
    if (snr > 0.0f && snr < squelch_db_) {
        decode_buffer_.clear();
        return;
    }

    CwDecodeResult result;
    result.text = decode_buffer_;
    result.frequency_hz = tone_freq_hz_;
    result.snr_db = snr;
    result.wpm = wpm_;
    result.complete = complete;
    results_.push_back(result);
    decode_buffer_.clear();
}

float CwDemod::compute_snr() const {
    return last_snr_;
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

    if (best_diff > weights.size() * 0.5f) {
        return "?";
    }

    return best_match;
}

void CwDemod::rx_process(const float* samples, int count, float center_freq_hz) {
    if (count <= 0) return;

    if (std::abs(center_freq_hz - tone_freq_hz_) > 1.0f) {
        setToneFrequency(center_freq_hz);
        rx_init();
    }

    process_samples(samples, count);
}

std::vector<CwDecodeResult> CwDemod::get_results() {
    auto results = results_;
    results_.clear();
    return results;
}

} // namespace Cw
