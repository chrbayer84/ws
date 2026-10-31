#ifndef CW_GT_DEMOD_HPP
#define CW_GT_DEMOD_HPP

#include "cw_demod.hpp"
#include <string>
#include <vector>
#include <complex>
#include <deque>
#include <cmath>

namespace Cw {

class CwGtDemod {
public:
    static constexpr int SAMPLE_RATE = 12000;
    static constexpr int FFT_SIZE = 2048;

    CwGtDemod();
    ~CwGtDemod();

    void setWpm(int wpm);
    void setBandwidth(int hz);
    void setSquelch(float db);
    void setReverse(bool rev);
    void setAdaptive(bool adaptive);
    void setToneFrequency(float hz);

    void rx_init();
    void rx_process(const float* samples, int count, float center_freq_hz);
    std::vector<CwDecodeResult> get_results();

    void reset();

    int getWpm() const { return wpm_; }
    int getBandwidth() const { return bandwidth_; }
    float getSquelch() const { return squelch_db_; }
    bool getReverse() const { return reverse_; }
    bool getAdaptive() const { return adaptive_; }

private:
    enum class RxState {
        IDLE,
        IN_TONE,
        AFTER_TONE
    };

    struct Element {
        bool is_tone;
        int duration_samples;
        float avg_power;
    };

    void apply_bandpass(const float* samples, int count);
    void envelope_detect(const float* samples, int count);
    void detect_elements(int count);
    void decode_elements();
    void update_wpm_tracking(int dot_samples, int dash_samples);
    std::string match_pattern(const std::vector<float>& weights);
    void flush_decode_buffer();
    float compute_snr();

    int wpm_ = 20;
    int bandwidth_ = 100;
    float squelch_db_ = 5.0f;
    bool reverse_ = false;
    bool adaptive_ = true;

    int dot_samples_ = 0;
    int dash_samples_ = 0;
    int elem_space_samples_ = 0;
    int char_space_samples_ = 0;
    int word_space_samples_ = 0;
    int two_dots_samples_ = 0;

    float tone_freq_hz_ = 600.0f;

    // Bandpass filter state (2nd order IIR)
    struct Biquad {
        float b0, b1, b2, a1, a2;
        float x1, x2, y1, y2;
        void reset() { x1 = x2 = y1 = y2 = 0.0f; }
        float process(float in) {
            float out = b0 * in + b1 * x1 + b2 * x2 - a1 * y1 - a2 * y2;
            x2 = x1; x1 = in;
            y2 = y1; y1 = out;
            return out;
        }
    };
    Biquad bp_filter_;

    // Envelope detector state
    float env_state_ = 0.0f;
    float env_alpha_ = 0.0f;
    float env_beta_ = 0.0f;

    std::vector<float> filtered_samples_;
    std::vector<float> envelope_;

    std::deque<Element> elements_;
    std::string decode_buffer_;
    std::vector<CwDecodeResult> results_;

    RxState state_ = RxState::IDLE;
    int tone_start_sample_ = 0;
    int silence_start_sample_ = 0;
    float noise_floor_ = 0.0f;
    float signal_peak_ = 0.0f;

    double dot_tracking_ = 0.0;
    double dash_tracking_ = 0.0;
    int adaptive_count_ = 0;

    int samples_processed_ = 0;
};

} // namespace Cw

#endif // CW_GT_DEMOD_HPP