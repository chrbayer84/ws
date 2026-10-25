#ifndef CW_MULTI_DEMOD_HPP
#define CW_MULTI_DEMOD_HPP

#include "cw_demod.hpp"
#include <vector>
#include <string>

namespace Cw {

struct CwMultiDemodResult {
    std::string text;
    float frequency_hz = 0.0f;
    float snr_db = 0.0f;
    int wpm = 0;
    int channel = 0;
    bool complete = false;
};

class CwMultiDemod {
public:
    static constexpr int MAX_CHANNELS = 32;
    static constexpr int SAMPLE_RATE = 12000;

    CwMultiDemod();
    ~CwMultiDemod() = default;

    void setWpm(int wpm);
    void setBandwidth(int hz);
    void setSquelch(float db);
    void setReverse(bool rev);
    void setAdaptive(bool adaptive);

    void init(int num_channels, float base_freq_hz, float channel_spacing_hz);
    void process(const float* samples, int count);
    std::vector<CwMultiDemodResult> get_results();

    int getNumChannels() const { return num_channels_; }
    float getBaseFreq() const { return base_freq_hz_; }
    float getChannelSpacing() const { return channel_spacing_hz_; }

private:
    int num_channels_ = 0;
    float base_freq_hz_ = 0.0f;
    float channel_spacing_hz_ = 0.0f;

    std::vector<CwDemod> demods_;
    std::vector<float> channel_freqs_;
};

} // namespace Cw

#endif // CW_MULTI_DEMOD_HPP