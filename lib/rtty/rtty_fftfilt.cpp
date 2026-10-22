//==============================================================================
// rtty_fftfilt.cpp:
//
// Fast convolution Overlap-Add filter using FFTW3 (single precision)
//
// This file is part of WSJT-X.
//==============================================================================

#include "rtty_fftfilt.hpp"
#include <iostream>
#include <algorithm>
#include <vector>

namespace Rtty
{
  FFTFilter::FFTFilter(int len)
    : flen_ {len}
  {
    init_filter();
  }

  FFTFilter::FFTFilter(double f, int len)
    : flen_ {len}
  {
    init_filter();
    rtty_filter(f);
  }

  FFTFilter::~FFTFilter()
  {
    if (fftPlan_) fftwf_destroy_plan(fftPlan_);
    if (ifftPlan_) fftwf_destroy_plan(ifftPlan_);

    fftwf_free(filter_);
    fftwf_free(timedata_);
    fftwf_free(freqdata_);
    fftwf_free(output_);
    fftwf_free(ovlbuf_);
  }

  void FFTFilter::init_filter()
  {
    flen2_ = flen_ >> 1;

    // Use fftwf_malloc for correct alignment (single precision)
    filter_ = static_cast<fftwf_complex*>(fftwf_malloc(flen_ * sizeof(fftwf_complex)));
    timedata_ = static_cast<fftwf_complex*>(fftwf_malloc(flen_ * sizeof(fftwf_complex)));
    freqdata_ = static_cast<fftwf_complex*>(fftwf_malloc(flen_ * sizeof(fftwf_complex)));
    output_ = static_cast<fftwf_complex*>(fftwf_malloc(flen_ * sizeof(fftwf_complex)));
    ovlbuf_ = static_cast<fftwf_complex*>(fftwf_malloc(flen2_ * sizeof(fftwf_complex)));

    // N6NU: rtty_filter() never writes filter_[flen2_], and fftw_malloc'd memory
    // is not zeroed: a stale NaN there killed the channel for good (it showed in
    // WS, never in a fresh test process). Start from an all-zero response.
    for (int i = 0; i < flen_; ++i) {
      filter_[i][0] = 0.0f;
      filter_[i][1] = 0.0f;
    }

    fftPlan_ = fftwf_plan_dft_1d(flen_, timedata_, freqdata_, FFTW_FORWARD, FFTW_ESTIMATE);
    ifftPlan_ = fftwf_plan_dft_1d(flen_, freqdata_, output_, FFTW_BACKWARD, FFTW_ESTIMATE);

    clear_filter();
  }

  void FFTFilter::clear_filter()
  {
    for (int i = 0; i < flen_; ++i) {
      timedata_[i][0] = 0.0f; timedata_[i][1] = 0.0f;
      freqdata_[i][0] = 0.0f; freqdata_[i][1] = 0.0f;
      output_[i][0] = 0.0f; output_[i][1] = 0.0f;
    }
    for (int i = 0; i < flen2_; ++i) {
      ovlbuf_[i][0] = 0.0f; ovlbuf_[i][1] = 0.0f;
    }
    inptr_ = 0;
    pass_ = 1;
  }

  void FFTFilter::rtty_filter(double f)
  {
    float f_ = static_cast<float>(f) * 1.4f;

    for (int i = 0; i < flen2_; ++i) {
      float const x = static_cast<float>(i) / static_cast<float>(flen2_);
      float dht = (x <= 0.0f) ? 1.0f :
                   (x > 2.0f * f_) ? 0.0f :
                   std::cos((M_PI * x) / (f_ * 4.0f));
      dht *= dht; // cos^2
      dht /= sinc(2.0f * i * f_);

      filter_[i][0] = dht * std::cos(i * -0.5f * M_PI);
      filter_[i][1] = dht * std::sin(i * -0.5f * M_PI);
      filter_[(flen_ - i) % flen_][0] = dht * std::cos(i * 0.5f * M_PI);
      filter_[(flen_ - i) % flen_][1] = dht * std::sin(i * 0.5f * M_PI);
    }

    pass_ = 1;
  }

  int FFTFilter::run(cmplx const& in, cmplx ** out)
  {
    timedata_[inptr_][0] = in.real();
    timedata_[inptr_][1] = in.imag();
    inptr_++;
    if (inptr_ < flen2_) return 0;
    if (pass_ > 0) pass_--;

    // Zero-pad second half
    for (int i = flen2_; i < flen_; ++i) {
      timedata_[i][0] = 0.0f;
      timedata_[i][1] = 0.0f;
    }

    fftwf_execute_dft(fftPlan_, timedata_, freqdata_);

    for (int i = 0; i < flen_; ++i) {
      float re = freqdata_[i][0] * filter_[i][0] - freqdata_[i][1] * filter_[i][1];
      float im = freqdata_[i][0] * filter_[i][1] + freqdata_[i][1] * filter_[i][0];
      freqdata_[i][0] = re;
      freqdata_[i][1] = im;
    }

    fftwf_execute_dft(ifftPlan_, freqdata_, output_);

    // Normalize FFTW backward scale (1/N)
    float const scale = 1.0f / static_cast<float>(flen_);
    for (int i = 0; i < flen_; ++i) {
      output_[i][0] *= scale;
      output_[i][1] *= scale;
    }

    // Overlap and add
    for (int i = 0; i < flen2_; ++i) {
      output_[i][0] = ovlbuf_[i][0] + output_[i][0];
      output_[i][1] = ovlbuf_[i][1] + output_[i][1];
      ovlbuf_[i][0] = output_[i + flen2_][0];
      ovlbuf_[i][1] = output_[i + flen2_][1];
    }

    inptr_ = 0;
    if (pass_ > 0) return 0;

    outbuf_.resize(flen2_);
    for (int i = 0; i < flen2_; ++i) {
      outbuf_[i] = cmplx(output_[i][0], output_[i][1]);
    }
    *out = outbuf_.data();
    return flen2_;
  }
}
