//==============================================================================
// rtty_fftfilt.cpp:
//
// Fast convolution Overlap-Add filter using FFTW3
//
// This file is part of WSJT-X.
//==============================================================================

#include "rtty_fftfilt.hpp"
#include <iostream>
#include <algorithm>

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
    if (fftPlan_) fftw_destroy_plan(fftPlan_);
    if (ifftPlan_) fftw_destroy_plan(ifftPlan_);

    fftw_free(filter_);
    fftw_free(timedata_);
    fftw_free(freqdata_);
    fftw_free(output_);
    fftw_free(ovlbuf_);
  }

  void FFTFilter::init_filter()
  {
    flen2_ = flen_ >> 1;

    // Use fftw_malloc for correct alignment
    filter_ = static_cast<cmplx*>(fftw_malloc(flen_ * sizeof(cmplx)));
    timedata_ = static_cast<cmplx*>(fftw_malloc(flen_ * sizeof(cmplx)));
    freqdata_ = static_cast<cmplx*>(fftw_malloc(flen_ * sizeof(cmplx)));
    output_ = static_cast<cmplx*>(fftw_malloc(flen_ * sizeof(cmplx)));
    ovlbuf_ = static_cast<cmplx*>(fftw_malloc(flen2_ * sizeof(cmplx)));

    fftPlan_ = fftw_plan_dft_1d(flen_, reinterpret_cast<fftw_complex*>(timedata_), 
                                 reinterpret_cast<fftw_complex*>(freqdata_), 
                                 FFTW_FORWARD, FFTW_ESTIMATE);
    
    ifftPlan_ = fftw_plan_dft_1d(flen_, reinterpret_cast<fftw_complex*>(freqdata_), 
                                  reinterpret_cast<fftw_complex*>(output_), 
                                  FFTW_BACKWARD, FFTW_ESTIMATE);

    clear_filter();
  }

  void FFTFilter::clear_filter()
  {
    for (int i = 0; i < flen_; ++i) {
      timedata_[i] = cmplx(0.0, 0.0);
      freqdata_[i] = cmplx(0.0, 0.0);
      output_[i] = cmplx(0.0, 0.0);
    }
    for (int i = 0; i < flen2_; ++i) {
      ovlbuf_[i] = cmplx(0.0, 0.0);
    }
    inptr_ = 0;
    pass_ = 1;
  }

  void FFTFilter::rtty_filter(double f)
  {
    f *= 1.4;

    for (int i = 0; i < flen2_; ++i) {
      double const x = static_cast<double>(i) / static_cast<double>(flen2_);
      double dht = (x <= 0.0) ? 1.0 :
                   (x > 2.0 * f) ? 0.0 :
                   std::cos((M_PI * x) / (f * 4.0));
      dht *= dht; // cos^2
      dht /= sinc(2.0 * i * f);

      filter_[i] = cmplx(dht * std::cos(i * -0.5 * M_PI),
                         dht * std::sin(i * -0.5 * M_PI));
      filter_[(flen_ - i) % flen_] = cmplx(dht * std::cos(i * 0.5 * M_PI),
                                           dht * std::sin(i * 0.5 * M_PI));
    }

    pass_ = 1;
  }

  int FFTFilter::run(cmplx const& in, cmplx ** out)
  {
    timedata_[inptr_++] = in;
    if (inptr_ < flen2_) return 0;
    if (pass_ > 0) --pass_;

    // Zero-pad second half
    for (int i = flen2_; i < flen_; ++i) {
      timedata_[i] = cmplx(0.0, 0.0);
    }

    fftw_execute_dft(fftPlan_, reinterpret_cast<fftw_complex*>(timedata_), 
                     reinterpret_cast<fftw_complex*>(freqdata_));

    for (int i = 0; i < flen_; ++i) {
      freqdata_[i] *= filter_[i];
    }

    fftw_execute_dft(ifftPlan_, reinterpret_cast<fftw_complex*>(freqdata_), 
                     reinterpret_cast<fftw_complex*>(output_));

    // Normalize FFTW backward scale (1/N)
    double const scale = 1.0 / static_cast<double>(flen_);
    for (int i = 0; i < flen_; ++i) {
      output_[i] *= scale;
    }

    // Overlap and add
    for (int i = 0; i < flen2_; ++i) {
      output_[i] = ovlbuf_[i] + output_[i];
      ovlbuf_[i] = output_[i + flen2_];
    }

    inptr_ = 0;
    if (pass_ > 0) return 0;

    *out = output_;
    return flen2_;
  }
}
