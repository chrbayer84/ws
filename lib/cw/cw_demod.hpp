#ifndef CW_DEMOD_HPP
#define CW_DEMOD_HPP

#include <string>
#include <vector>
#include <complex>
#include <deque>

namespace Cw {

struct CwDecodeResult {
    std::string text;
    float frequency_hz = 0.0f;
    float snr_db = 0.0f;
    int wpm = 0;
    bool complete = false;
};

class CwDemod {
public:
    static constexpr int SAMPLE_RATE = 12000;
    static constexpr int FFT_SIZE = 2048;
    static constexpr int MAX_ELEMENTS = 128;

    CwDemod();
    ~CwDemod();

    void setWpm(int wpm);
    void setBandwidth(int hz);
    void setSquelch(float db);
    void setReverse(bool rev);
    void setAdaptive(bool adaptive);

    int getWpm() const { return wpm_; }
    int getBandwidth() const { return bandwidth_; }
    float getSquelch() const { return squelch_db_; }
    bool getReverse() const { return reverse_; }
    bool getAdaptive() const { return adaptive_; }

    void rx_init();
    void rx_process(const float* samples, int count, float center_freq_hz);
    std::vector<CwDecodeResult> get_results();

    void reset();

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

    void mix_down(const float* samples, int count, float freq_hz);
    void apply_matched_filter();
    void detect_elements();
    void decode_elements();
    void update_wpm_tracking(int dot_samples, int dash_samples);
    std::string match_pattern(const std::vector<float>& weights);
    void flush_decode_buffer();

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
    double mix_phase_ = 0.0;
    double mix_phase_inc_ = 0.0;

    std::vector<std::complex<float>> fft_buffer_;
    std::vector<float> filter_response_;
    std::vector<float> power_buffer_;
    std::vector<float> filtered_power_;

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

#endif // CW_DEMOD_HPP