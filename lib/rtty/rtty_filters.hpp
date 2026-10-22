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
  using cmplx = std::complex<float>;

  inline float sinc(float x)
  {
    if (std::fabs(x) < 1e-10f) return 1.0f;
    return std::sin(M_PI * x) / (M_PI * x);
  }

  inline float clamp(float x, float minVal, float maxVal)
  {
    return (x < minVal) ? minVal : ((x > maxVal) ? maxVal : x);
  }

  inline float decayavg(float average, float input, int weight)
  {
    if (weight <= 1) return input;
    return ((input - average) / static_cast<float>(weight)) + average;
  }

  inline float rcos(float t, float T, float alpha = 1.0f)
  {
    if (t == 0.0f) return 1.0f;
    float const taT = T / (2.0f * alpha);
    if (std::fabs(t) == taT) {
      return (alpha / 2.0f) * std::sin(M_PI / (2.0f * alpha));
    }
    return (std::sin(M_PI * t / T) / (M_PI * t / T)) *
           std::cos(alpha * M_PI * t / T) / (1.0f - (t / taT) * (t / taT));
  }

  class MovingAverage
  {
  public:
    explicit MovingAverage(int filtlen = 64);
    ~MovingAverage();

    MovingAverage(MovingAverage const&) = delete;
    MovingAverage& operator=(MovingAverage const&) = delete;

    float run(float a);
    void setLength(int filtlen);
    void reset();
    float value() const { return len_ > 0 ? (out_ / len_) : 0.0f; }

  private:
    float * in_ {nullptr};
    float out_ {0.0f};
    int len_ {0};
    int pint_ {0};
    bool empty_ {true};
  };
}

#endif // RTTY_FILTERS_HPP
