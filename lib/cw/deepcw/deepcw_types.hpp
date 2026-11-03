#ifndef CW_DEEPCW_TYPES_HPP
#define CW_DEEPCW_TYPES_HPP

#include <string>
#include <vector>

namespace Cw {
namespace DeepCw {

// WSJT-X runs at 12 kHz. The model is trained at 3.2 kHz with FFT 256 / hop 48
// (12.5 Hz bins, 80 ms window, 15 ms hop). Scaling the STFT by 12000/3200 keeps
// the exact same time and frequency resolution without resampling, the same
// trick the web decoder uses at 9.6 kHz.
constexpr int kInputRate = 12000;
constexpr int kBaselineRate = 3200;
constexpr int kFftLength = 960;   // 256 * 12000 / 3200
constexpr int kHopLength = 180;   // 48 * 12000 / 3200
constexpr int kOutputTimeStride = 2;
constexpr int kOutputHopLength = kHopLength * kOutputTimeStride; // 360 samples = 30 ms
constexpr int kDetectHopLength = 240;                            // 20 ms
constexpr double kBinHz = static_cast<double>(kInputRate) / kFftLength; // 12.5 Hz

struct ModelSpec {
    const char* name;
    int frequency_bins;
    double min_freq_hz;
    double max_freq_hz;
    int blank_index;
    int num_classes;
    const char* const* chars;
};

// Standard 65-bin model (400..1200 Hz native band) and the 3-bin narrow model
// used for per-carrier multi-channel decoding.
const ModelSpec& standard_spec();
const ModelSpec& narrow_spec();

int space_index(const ModelSpec& spec);

struct DecodeResult {
    std::string text;
    float frequency_hz = 0.0f;
    float snr_db = 0.0f;
    int wpm = 0;
    int channel = 0;
    bool complete = false;
};

} // namespace DeepCw
} // namespace Cw

#endif // CW_DEEPCW_TYPES_HPP
