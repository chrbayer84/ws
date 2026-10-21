//==============================================================================
// rtty_shaper.hpp:
//
// Raised-cosine pulse shaper and NCO oscillator for RTTY AFSK synthesis
// Ported from fldigi (Dave Freese, W1HKJ / Stefan Fendt, DL1SMF)
//
// This file is part of WSJT-X.
//==============================================================================

#ifndef RTTY_SHAPER_HPP
#define RTTY_SHAPER_HPP

#include "rtty_filters.hpp"

namespace Rtty
{
  class Oscillator
  {
  public:
    explicit Oscillator(double samplerate = 48000.0);

    double update(double frequency);
    void resetPhase(double phase = 0.0) { phase_ = phase; }

  private:
    double phase_ {0.0};
    double samplerate_ {48000.0};
  };

  class SymbolShaper
  {
  public:
    explicit SymbolShaper(double baud = 45.4545, double samplerate = 48000.0);
    ~SymbolShaper();

    SymbolShaper(SymbolShaper const&) = delete;
    SymbolShaper& operator=(SymbolShaper const&) = delete;

    void preset(double baud, double samplerate);
    void reset();
    double update(bool state);

  private:
    int tableSize_ {0};
    double * sincTable_ {nullptr};

    bool state_ {false};
    double accumulator_ {0.0};
    long counter0_ {1024};
    long counter1_ {1024};
    long counter2_ {1024};
    long counter3_ {1024};
    long counter4_ {1024};
    long counter5_ {1024};
    double factor0_ {0.0};
    double factor1_ {0.0};
    double factor2_ {0.0};
    double factor3_ {0.0};
    double factor4_ {0.0};
    double factor5_ {0.0};

    double baudrate_ {45.4545};
    double samplerate_ {48000.0};
  };
}

#endif // RTTY_SHAPER_HPP
