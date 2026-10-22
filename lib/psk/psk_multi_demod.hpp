#ifndef PSK_MULTI_DEMOD_HPP
#define PSK_MULTI_DEMOD_HPP

#include "psk_modem.hpp"
#include <vector>
#include <memory>
#include <cstdint>

namespace Psk {

class PskMultiDemod {
public:
    static constexpr int MAX_CHANNELS = 128;
    static constexpr int DEFAULT_LOW_FREQ = 200;
    static constexpr int DEFAULT_HIGH_FREQ = 2800;

    struct Channel {
        bool active = false;
        double frequency = 0.0;
        int timeout = 0;
        int idleFrames = 0;
        std::unique_ptr<PskModem> modem;
        std::string text;
        bool hasText = false;
    };

    PskMultiDemod(double sampleRate = 12000.0,
                  int lowFreq = DEFAULT_LOW_FREQ,
                  int highFreq = DEFAULT_HIGH_FREQ);
    ~PskMultiDemod();

    void setSampleRate(double rate);
    void setFrequencyRange(int low, int high);
    void setSquelch(double s);
    void setReverse(bool rev);

    void reset();
    void rxProcess(const int16_t* samples, int count);

    struct DecodeResult {
        int channelId;
        double frequency;
        std::string text;
        double snr;
        bool complete;
    };
    std::vector<DecodeResult> takeDecodes();

private:
    double sampleRate_;
    int lowFreq_;
    int highFreq_;
    double squelch_;
    bool reverse_;

    std::vector<Channel> channels_;
    std::vector<DecodeResult> pendingDecodes_;
};

} // namespace Psk

#endif // PSK_MULTI_DEMOD_HPP