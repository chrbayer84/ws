//==============================================================================
// rtty_filters.cpp:
//
// Filter definitions and DSP helpers for RTTY (ported from fldigi)
// Single precision version using float
//
// This file is part of WSJT-X.
//==============================================================================

#include "rtty_filters.hpp"

namespace Rtty
{
  MovingAverage::MovingAverage(int filtlen)
    : in_ {new float[filtlen > 0 ? filtlen : 1]}
    , len_ {filtlen > 0 ? filtlen : 1}
    , empty_ {true}
  {
  }

  MovingAverage::~MovingAverage()
  {
    delete [] in_;
  }

  float MovingAverage::run(float a)
  {
    if (!in_ || len_ <= 0) return a;
    if (empty_) {
      empty_ = false;
      out_ = 0.0f;
      for (int i = 0; i < len_; ++i) {
        in_[i] = a;
        out_ += a;
      }
      pint_ = 0;
      return a;
    }
    out_ = out_ - in_[pint_] + a;
    in_[pint_] = a;
    if (++pint_ >= len_) pint_ = 0;
    return out_ / len_;
  }

  void MovingAverage::setLength(int filtlen)
  {
    if (filtlen <= 0) filtlen = 1;
    if (filtlen > len_) {
      delete [] in_;
      in_ = new float[filtlen];
    }
    len_ = filtlen;
    empty_ = true;
  }

  void MovingAverage::reset()
  {
    empty_ = true;
    out_ = 0.0f;
    pint_ = 0;
  }
}