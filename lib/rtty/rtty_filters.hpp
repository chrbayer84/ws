//==============================================================================
// rtty_filters.hpp:
//
// Filter definitions and DSP helpers for RTTY (ported from fldigi)
//
// This file is part of WSJT-X.
//==============================================================================

#ifndef RTTY_FILTERS_HPP
#define RTTY_FILTERS_HPP

#include <cmath>
#include <complex>
#include <algorithm>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

namespace Rtty
{
  using cmplx = std::complex<double>;

  inline double sinc(double x)
  {
    if (std::fabs(x) < 1e-10) return 1.0;
    return std::sin(M_PI * x) / (M_PI * x);
  }

  inline double clamp(double x, double minVal, double maxVal)
  {
    return (x < minVal) ? minVal : ((x > maxVal) ? maxVal : x);
  }

  inline double decayavg(double average, double input, int weight)
  {
    if (weight <= 1) return input;
    return ((input - average) / static_cast<double>(weight)) + average;
  }

  inline double rcos(double t, double T, double alpha = 1.0)
  {
    if (t == 0.0) return 1.0;
    double const taT = T / (2.0 * alpha);
    if (std::fabs(t) == taT) {
      return (alpha / 2.0) * std::sin(M_PI / (2.0 * alpha));
    }
    return (std::sin(M_PI * t / T) / (M_PI * t / T)) *
           std::cos(alpha * M_PI * t / T) / (1.0 - (t / taT) * (t / taT));
  }

  class MovingAverage
  {
  public:
    explicit MovingAverage(int filtlen = 64);
    ~MovingAverage();

    MovingAverage(MovingAverage const&) = delete;
    MovingAverage& operator=(MovingAverage const&) = delete;

    double run(double a);
    void setLength(int filtlen);
    void reset();
    double value() const { return len_ > 0 ? (out_ / len_) : 0.0; }

  private:
    double * in_ {nullptr};
    double out_ {0.0};
    int len_ {0};
    int pint_ {0};
    bool empty_ {true};
  };
}

#endif // RTTY_FILTERS_HPP
