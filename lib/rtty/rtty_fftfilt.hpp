#ifndef RTTY_FFTFILT_HPP
#define RTTY_FFTFILT_HPP

#include "rtty_filters.hpp"
#include <fftw3.h>
#include <cstring>

namespace Rtty
{
  using fftwf_complex = float[2];  // FFTW3 native single-precision complex type

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
    
    fftwf_plan fftPlan_ {nullptr};
    fftwf_plan ifftPlan_ {nullptr};

    fftwf_complex * filter_ {nullptr};
    fftwf_complex * timedata_ {nullptr};
    fftwf_complex * freqdata_ {nullptr};
    fftwf_complex * ovlbuf_ {nullptr};
    fftwf_complex * output_ {nullptr};
    int inptr_ {0};
    int pass_ {0};
  };
}

#endif // RTTY_FFTFILT_HPP
