#ifndef CW_MODEM_HPP
#define CW_MODEM_HPP

#include <string>
#include <vector>
#include <complex>

namespace Cw {

class CwModem {
public:
    static constexpr int SAMPLE_RATE = 12000;
    static constexpr float DEFAULT_TONE_HZ = 600.0f;
    static constexpr float DEFAULT_RISE_TIME_MS = 5.0f;

    CwModem();
    ~CwModem() = default;

    void setWpm(int wpm);
    void setToneFrequency(float hz);
    void setRiseTimeMs(float ms);
    void setReverse(bool rev);

    int getWpm() const { return wpm_; }
    float getToneFrequency() const { return tone_hz_; }
    float getRiseTimeMs() const { return rise_time_ms_; }
    bool getReverse() const { return reverse_; }

    void tx_init();
    int tx_process(float* output, int max_samples, const std::string& text);

private:
    struct EdgeShape {
        std::vector<float> rise;
        std::vector<float> fall;
    };

    void build_edge_shape();
    void encode_text(const std::string& text);
    void generate_element(bool is_tone, int duration, float* output, int& pos, int max_samples);
    void generate_space(int space_type, float* output, int& pos, int max_samples);

    int wpm_ = 20;
    float tone_hz_ = DEFAULT_TONE_HZ;
    float rise_time_ms_ = DEFAULT_RISE_TIME_MS;
    bool reverse_ = false;

    int dot_samples_ = 0;
    int dash_samples_ = 0;
    int elem_space_samples_ = 0;
    int char_space_samples_ = 0;
    int word_space_samples_ = 0;
    int rise_samples_ = 0;
    int fall_samples_ = 0;

    EdgeShape edge_shape_;
    std::vector<std::pair<bool, int>> encoded_elements_;
    double phase_ = 0.0;
    double phase_inc_ = 0.0;
};

} // namespace Cw

#endif // CW_MODEM_HPP