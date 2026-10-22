//==============================================================================
// rtty_multi_demod.hpp:
//
// Multi-channel panoramic RTTY demodulator (adapted from fldigi by Dave Freese)
//
// This file is part of WSJT-X.
//==============================================================================

#ifndef RTTY_MULTI_DEMOD_HPP
#define RTTY_MULTI_DEMOD_HPP

#include "rtty_modem.hpp"
#include <vector>
#include <string>
#include <memory>

namespace Rtty
{
  struct ChannelDecode
  {
    ChannelDecode(int id, double f, std::string t, double s) : channelId(id), frequency(f), text(std::move(t)), snr(s) {}
    ChannelDecode() = default;
    int channelId {0};
    double frequency {0.0};
    std::string text;
    double snr {0.0};
  };

  class RttyMultiDemod
  {
  public:
    static constexpr int MAX_CHANNELS = 64;

    explicit RttyMultiDemod(double baud = 45.4545, double shift = 170.0,
                            double sampleRate = 12000.0);
    ~RttyMultiDemod();

    RttyMultiDemod(RttyMultiDemod const&) = delete;
    RttyMultiDemod& operator=(RttyMultiDemod const&) = delete;

    void setBandpass(double lowFreq, double highFreq);
    void setBaud(double baud);
    void setShift(double shift);
    void setReverse(bool reverse);
    void setUos(bool uos);
    void setSquelch(double squelch);

    void reset();

    // Process 12 kHz input samples across the band
    void rxProcess(int16_t const * samples, int count);
    void rxProcess(double const * samples, int count);

    // Retrieve accumulated decodes from all channels
    std::vector<ChannelDecode> takeDecodes();

  private:
    void scanAndAllocateSignals(double const * samples, int count);

    double baud_ {45.4545};
    double shift_ {170.0};
    double sampleRate_ {12000.0};
    double lowFreq_ {200.0};
    double highFreq_ {2800.0};
    bool reverse_ {false};
    bool uos_ {true};
    double squelch_ {0.0};

    struct ChannelSlot
    {
      bool active {false};
      double frequency {0.0};
      int timeout {0};
      std::unique_ptr<RttyModem> modem;
    };

    std::vector<ChannelSlot> channels_;
    int scanCounter_ {0};
  };
}

#endif // RTTY_MULTI_DEMOD_HPP
