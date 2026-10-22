//
// N6NU 2026-10-22: the fixed grid of 30 channels is replaced by a signal search.
// Every scanHop samples a smoothed spectrum is searched for mark/space tone pairs
// one shift apart; a demodulator is placed exactly on each pair (primed with the
// last historySamples of audio so the start of the over is not lost) and its text
// is passed on only while the pair is present in the spectrum. The modem's own
// squelch compares its tones with the power of the whole passband, which closes
// on every signal once a few stations share the band, so it is off here.
//==============================================================================

#ifndef RTTY_MULTI_DEMOD_HPP
#define RTTY_MULTI_DEMOD_HPP

#include "rtty_modem.hpp"
#include <fftw3.h>
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
    void setSquelch(double squelch);   // detection threshold in dB over the noise per bin

    void reset();

    // Process 12 kHz input samples across the band
    void rxProcess(int16_t const * samples, int count);
    void rxProcess(double const * samples, int count);

    // Retrieve accumulated decodes from all channels
    std::vector<ChannelDecode> takeDecodes();

    // True if a tone pair is currently detected within tolHz of freqHz
    bool signalAt(double freqHz, double tolHz) const;

    // Changes whenever the channel is given to a newly found signal
    int generation(int channel) const { return channels_[channel].generation; }

  private:
    static constexpr int scanSize = 4096;        // 2.93 Hz bins at 12 kHz
    static constexpr int scanHop = 2048;         // a new spectrum every 0.17 s
    static constexpr int historySamples = 18000; // 1.5 s to prime a new channel
    static constexpr int hangoverScans = 2;      // text still passed 0.35 s after the pair fades
    static constexpr int releaseScans = 60;      // channel freed after 10 s without its pair
    static constexpr double matchHz = 50.0;      // a pair this close to a channel belongs to it
    static constexpr double contrastGate = 0.45; // see RttyModem::setContrastGate

    void scan();
    void allocate(double centerHz, double snrDb);
    void collectText();

    double baud_ {45.4545};
    double shift_ {170.0};
    double sampleRate_ {12000.0};
    double lowFreq_ {200.0};
    double highFreq_ {2800.0};
    bool reverse_ {false};
    bool uos_ {true};
    double thresholdDb_ {10.0};

    struct ChannelSlot
    {
      bool active {false};
      double frequency {0.0};   // where the pair was found
      int missed {0};           // scans since the pair was last seen
      int age {0};              // scans since the channel was allocated
      int generation {0};       // allocations so far
      std::string pending;      // gated text not yet taken
      double snr {0.0};
      std::unique_ptr<RttyModem> modem;
    };

    std::vector<ChannelSlot> channels_;
    std::vector<double> history_;   // ring buffer of the last historySamples
    int historyPos_ {0};
    long long historyFill_ {0};
    int sinceScan_ {0};
    int scans_ {0};
    std::vector<double> pending_;   // pairs seen in the last scan but not yet given a channel
    std::vector<double> window_;
    std::vector<double> spectrum_;  // smoothed power per bin
    bool spectrumValid_ {false};
    float * fftIn_ {nullptr};
    fftwf_complex * fftOut_ {nullptr};
    fftwf_plan plan_ {nullptr};
  };
}

#endif // RTTY_MULTI_DEMOD_HPP
