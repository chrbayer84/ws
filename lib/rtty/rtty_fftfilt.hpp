//==============================================================================
// rtty_fftfilt.hpp:
//
// Fast convolution Overlap-Add filter using FFTW3
//
// This file is part of WSJT-X.
//==============================================================================

#ifndef RTTY_FFTFILT_HPP
#define RTTY_FFTFILT_HPP

#include "rtty_filters.hpp"
#include <fftw3.h>
#include <cstring>

namespace Rtty
{
  class FFTFilter
  {
  public:
    explicit FFTFilter(int len);
    FFTFilter(double f, int len);
    ~FFTFilter();

    FFTFilter(FFTFilter const&) = delete;
    FFTFilter& operator=(FFTFilter const&) = delete;

    void rtty_filter(double f);
    void clear_filter();
    int run(cmplx const& in, cmplx ** out);
    int flush_size() const { return flen_ - inptr_; }

  private:
    void init_filter();

    int flen_ {0};
    int flen2_ {0};
    
    fftw_plan fftPlan_ {nullptr};
    fftw_plan ifftPlan_ {nullptr};

    cmplx * filter_ {nullptr};
    cmplx * timedata_ {nullptr};
    cmplx * freqdata_ {nullptr};
    cmplx * ovlbuf_ {nullptr};
    cmplx * output_ {nullptr};
    int inptr_ {0};
    int pass_ {0};
  };
}

#endif // RTTY_FFTFILT_HPP
