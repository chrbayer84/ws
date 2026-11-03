#ifndef CW_DEEPCW_STFT_HPP
#define CW_DEEPCW_STFT_HPP

#include <vector>

namespace Cw {
namespace DeepCw {

// Center-padded, Hann-windowed real STFT. Frame t is centered on sample
// t * hop, matching the reference front-end (reflect padding by fft/2).
class Stft {
public:
    Stft(int fft_length, int hop_length);
    ~Stft();

    Stft(Stft const&) = delete;
    Stft& operator=(Stft const&) = delete;

    int fft_length() const { return fft_length_; }
    int hop_length() const { return hop_length_; }
    int frame_count(int sample_count) const;

    // Writes frame-major magnitudes for frames [start_frame, end_frame) and
    // bins [bin_start, bin_stop) into `out`.
    bool magnitudes(float const* samples, int sample_count,
                    int start_frame, int end_frame,
                    int bin_start, int bin_stop,
                    std::vector<float>& out) const;

private:
    float sample_reflected(float const* samples, int sample_count, int index) const;

    int fft_length_;
    int hop_length_;
    void* plan_;
    float* time_domain_;
    void* freq_domain_;
    std::vector<float> window_;
};

} // namespace DeepCw
} // namespace Cw

#endif // CW_DEEPCW_STFT_HPP
