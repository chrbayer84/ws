#include "deepcw_stft.hpp"

#include <cmath>
#include <cstring>

#if defined(__has_include)
#  if __has_include(<fftw3f.h>)
#    include <fftw3f.h>
#  else
#    include <fftw3.h>
#  endif
#else
#  include <fftw3.h>
#endif

namespace Cw {
namespace DeepCw {

Stft::Stft(int fft_length, int hop_length)
    : fft_length_(fft_length)
    , hop_length_(hop_length)
    , plan_(nullptr)
    , time_domain_(nullptr)
    , freq_domain_(nullptr) {
    window_.resize(static_cast<size_t>(fft_length_));
    for (int i = 0; i < fft_length_; ++i) {
        window_[i] = 0.5f * (1.0f - std::cos(2.0f * static_cast<float>(M_PI) * i / fft_length_));
    }

    time_domain_ = fftwf_alloc_real(static_cast<size_t>(fft_length_));
    freq_domain_ = static_cast<void*>(fftwf_alloc_complex(static_cast<size_t>(fft_length_ / 2 + 1)));
    if (time_domain_ && freq_domain_) {
        plan_ = static_cast<void*>(fftwf_plan_dft_r2c_1d(
            fft_length_, time_domain_, static_cast<fftwf_complex*>(freq_domain_), FFTW_ESTIMATE));
    }
}

Stft::~Stft() {
    if (plan_) fftwf_destroy_plan(static_cast<fftwf_plan>(plan_));
    if (time_domain_) fftwf_free(time_domain_);
    if (freq_domain_) fftwf_free(freq_domain_);
}

int Stft::frame_count(int sample_count) const {
    if (sample_count <= 0 || hop_length_ <= 0) return 0;
    return 1 + sample_count / hop_length_;
}

float Stft::sample_reflected(float const* samples, int sample_count, int index) const {
    if (sample_count <= 0) return 0.0f;
    if (sample_count == 1) return samples[0];

    while (index < 0 || index >= sample_count) {
        if (index < 0) index = -index;
        if (index >= sample_count) index = 2 * sample_count - 2 - index;
    }
    return samples[index];
}

bool Stft::magnitudes(float const* samples, int sample_count,
                      int start_frame, int end_frame,
                      int bin_start, int bin_stop,
                      std::vector<float>& out) const {
    out.clear();
    if (!plan_ || !samples || sample_count <= 0) return false;
    if (start_frame < 0) start_frame = 0;
    const int frames = frame_count(sample_count);
    if (end_frame > frames) end_frame = frames;
    if (end_frame <= start_frame || bin_stop <= bin_start) return false;

    const int total_bins = fft_length_ / 2 + 1;
    if (bin_start < 0) bin_start = 0;
    if (bin_stop > total_bins) bin_stop = total_bins;
    if (bin_stop <= bin_start) return false;

    const int pad = fft_length_ / 2;
    const int bins = bin_stop - bin_start;
    out.resize(static_cast<size_t>(end_frame - start_frame) * bins);

    for (int frame = start_frame; frame < end_frame; ++frame) {
        const int center = frame * hop_length_;
        for (int i = 0; i < fft_length_; ++i) {
            const int source = center - pad + i;
            time_domain_[i] = sample_reflected(samples, sample_count, source) * window_[i];
        }
        fftwf_execute(static_cast<fftwf_plan>(plan_));

        float* dst = out.data() + static_cast<size_t>(frame - start_frame) * bins;
        fftwf_complex* freq = static_cast<fftwf_complex*>(freq_domain_);
        for (int b = bin_start; b < bin_stop; ++b) {
            const float re = freq[b][0];
            const float im = freq[b][1];
            dst[b - bin_start] = std::sqrt(re * re + im * im);
        }
    }

    return true;
}

} // namespace DeepCw
} // namespace Cw
