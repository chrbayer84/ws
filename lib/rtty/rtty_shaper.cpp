//==============================================================================
// rtty_shaper.cpp:
//
// Raised-cosine pulse shaper and NCO oscillator for RTTY AFSK synthesis
// Ported from fldigi (Dave Freese, W1HKJ / Stefan Fendt, DL1SMF)
//
// This file is part of WSJT-X.
//==============================================================================

#include "rtty_shaper.hpp"
#include <cmath>

namespace Rtty
{
  Oscillator::Oscillator(double samplerate)
    : phase_ {0.0}
    , samplerate_ {samplerate > 0.0 ? samplerate : 48000.0}
  {
  }

  double Oscillator::update(double frequency)
  {
    phase_ += (frequency / samplerate_) * 2.0 * M_PI;
    if (phase_ > 2.0 * M_PI) {
      phase_ = std::fmod(phase_, 2.0 * M_PI);
    }
    return std::sin(phase_);
  }

  SymbolShaper::SymbolShaper(double baud, double samplerate)
  {
    preset(baud, samplerate);
  }

  SymbolShaper::~SymbolShaper()
  {
    delete [] sincTable_;
  }

  void SymbolShaper::reset()
  {
    state_ = false;
    accumulator_ = 0.0;
    counter0_ = 20000;
    counter1_ = 20000;
    counter2_ = 20000;
    counter3_ = 20000;
    counter4_ = 20000;
    counter5_ = 20000;
    factor0_ = 0.0;
    factor1_ = 0.0;
    factor2_ = 0.0;
    factor3_ = 0.0;
    factor4_ = 0.0;
    factor5_ = 0.0;
  }

  void SymbolShaper::preset(double baud, double samplerate)
  {
    baudrate_ = baud > 0.0 ? baud : 45.4545;
    samplerate_ = samplerate > 0.0 ? samplerate : 48000.0;

    tableSize_ = static_cast<int>(samplerate_ / baudrate_ * 5.49);
    if (tableSize_ < 16) tableSize_ = 16;

    delete [] sincTable_;
    sincTable_ = new double[tableSize_];

    long double sum = 0.0;
    int const offset = tableSize_ / 2;
    double const wfactor = 1.0 / 1.568;
    double const T = wfactor * samplerate_ / (baudrate_ * 2.0);

    for (int x = 0; x < tableSize_; ++x) {
      double const t = x - offset;
      sincTable_[x] = rcos(t, T, 1.0);
      sum += sincTable_[x];
    }

    if (sum != 0.0) {
      for (int x = 0; x < tableSize_; ++x) {
        sincTable_[x] /= static_cast<double>(sum);
      }
    }

    reset();
  }

  double SymbolShaper::update(bool state)
  {
    if (state_ != state) {
      state_ = state;
      if (counter0_ >= tableSize_) {
        counter0_ = 0;
        factor0_ = state ? 1.0 : -1.0;
      } else if (counter1_ >= tableSize_) {
        counter1_ = 0;
        factor1_ = state ? 1.0 : -1.0;
      } else if (counter2_ >= tableSize_) {
        counter2_ = 0;
        factor2_ = state ? 1.0 : -1.0;
      } else if (counter3_ >= tableSize_) {
        counter3_ = 0;
        factor3_ = state ? 1.0 : -1.0;
      } else if (counter4_ >= tableSize_) {
        counter4_ = 0;
        factor4_ = state ? 1.0 : -1.0;
      } else if (counter5_ >= tableSize_) {
        counter5_ = 0;
        factor5_ = state ? 1.0 : -1.0;
      }
    }

    if (counter0_ < tableSize_) accumulator_ += factor0_ * sincTable_[counter0_++];
    if (counter1_ < tableSize_) accumulator_ += factor1_ * sincTable_[counter1_++];
    if (counter2_ < tableSize_) accumulator_ += factor2_ * sincTable_[counter2_++];
    if (counter3_ < tableSize_) accumulator_ += factor3_ * sincTable_[counter3_++];
    if (counter4_ < tableSize_) accumulator_ += factor4_ * sincTable_[counter4_++];
    if (counter5_ < tableSize_) accumulator_ += factor5_ * sincTable_[counter5_++];

    return accumulator_;
  }
}
