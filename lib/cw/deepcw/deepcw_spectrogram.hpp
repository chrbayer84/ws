#ifndef CW_DEEPCW_SPECTROGRAM_HPP
#define CW_DEEPCW_SPECTROGRAM_HPP

#include "deepcw_stft.hpp"
#include "deepcw_types.hpp"

#include <vector>

namespace Cw {
namespace DeepCw {

// Builds model-ready spectrogram tensors from 12 kHz audio.
class Frontend {
public:
    Frontend();

    // 65-bin spectrogram over the native 400..1200 Hz band.
    bool standard(float const* samples, int count,
                  std::vector<float>& out, int& frames) const;

    // 65-bin spectrogram with `target_hz` shifted to the model's 800 Hz center,
    // covering +/- bandwidth/2.
    bool shifted(float const* samples, int count, double target_hz,
                 double bandwidth_hz, std::vector<float>& out, int& frames) const;

    // 3-bin spectrogram around `target_hz`.
    bool narrow(float const* samples, int count, double target_hz,
                std::vector<float>& out, int& frames) const;

    struct Detection {
        std::vector<double> frequencies;
        std::vector<float> snr_db;
    };

    // Per-bin keyed SNR (90th percentile vs band median), with sidebands masked.
    Detection detect(float const* samples, int count,
                     double min_hz, double max_hz) const;

private:
    Stft stft_;
    Stft detect_stft_;
};

// Exposed for tests.
void normalize_noise_q90_log1p(std::vector<float>& spectrogram,
                               std::vector<float> const& noise_values);

} // namespace DeepCw
} // namespace Cw

#endif // CW_DEEPCW_SPECTROGRAM_HPP
