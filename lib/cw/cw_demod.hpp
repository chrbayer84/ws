#ifndef CW_DEMOD_HPP
#define CW_DEMOD_HPP

#include <string>
#include <vector>
#include <deque>

namespace Cw {

struct CwDecodeResult {
    std::string text;
    float frequency_hz = 0.0f;
    float snr_db = 0.0f;
    int wpm = 0;
    bool complete = false;
    bool replace = false;
    int channel = 0;
};

// Single-tone (fldigi-style) CW demodulator.
//
// The audio is mixed to baseband with a complex NCO and the envelope is taken
// from sqrt(I^2+Q^2), so there is no 2*fc ripple to make the key chatter. The
// key threshold is level-relative and hysteretic, following signal and noise
// instead of comparing against a fixed amplitude. Element lengths are learned
// continuously (no fixed/one-shot speed), and characters are emitted as soon
// as the inter-element gap says the character is complete, with word spaces
// flushed on the longer word gap.
class CwDemod {
public:
    static constexpr int SAMPLE_RATE = 12000;
    static constexpr int FFT_SIZE = 2048;

    CwDemod();
    ~CwDemod();

    void setWpm(int wpm);
    void setBandwidth(int hz);
    void setSquelch(float db);
    void setReverse(bool rev);
    void setAdaptive(bool adaptive);
    void setToneFrequency(float hz);

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

    void process_samples(const float* samples, int count);
    void finalize_char();
    void emit_buffer(bool complete);
    void speed_learn();
    float compute_snr() const;
    std::string match_pattern(const std::vector<float>& weights);

    int wpm_ = 20;
    int bandwidth_ = 50;
    float squelch_db_ = 5.0f;
    bool reverse_ = false;
    bool adaptive_ = true;

    int dot_samples_ = 0;
    int dash_samples_ = 0;
    int char_gap_samples_ = 0;
    int word_gap_samples_ = 0;

    float tone_freq_hz_ = 600.0f;

    // Complex down-mixer and low-pass envelope detector.
    double nco_phase_ = 0.0;
    double nco_step_ = 0.0;
    float lp_i_ = 0.0f;
    float lp_q_ = 0.0f;
    float lp_alpha_ = 0.05f;

    // Level-relative key detector with hysteresis.
    float noise_ = 0.001f;
    float sig_ = 0.0f;
    bool key_ = false;
    float last_snr_ = 0.0f;

    // Key debounce and glitch rollback (noise spikes must not reset gaps).
    bool pending_key_ = false;
    int pending_key_count_ = 0;
    int glitch_silence_ = 0;
    bool glitch_char_finalized_ = false;
    bool glitch_word_added_ = false;

    // Recent mark lengths (samples) for continuous speed learning.
    std::deque<int> recent_marks_;

    std::string decode_buffer_;
    std::vector<float> char_weights_;
    std::vector<CwDecodeResult> results_;

    RxState state_ = RxState::IDLE;
    int tone_start_sample_ = 0;
    int silence_start_sample_ = 0;
    bool char_finalized_ = false;
    bool word_added_ = false;

    int samples_processed_ = 0;
};

} // namespace Cw

#endif // CW_DEMOD_HPP
