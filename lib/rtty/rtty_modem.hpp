//==============================================================================
// rtty_modem.hpp:
//
// Standalone single-channel RTTY modem (adapted from fldigi by Dave Freese, W1HKJ)
//
// This file is part of WSJT-X.
//==============================================================================

#ifndef RTTY_MODEM_HPP
#define RTTY_MODEM_HPP

#include "rtty_filters.hpp"
#include "rtty_fftfilt.hpp"
#include "rtty_baudot.hpp"
#include "rtty_shaper.hpp"

#include <vector>
#include <string>
#include <deque>
#include <cstdint>

namespace Rtty
{
  enum class RxState : uint8_t
  {
    Idle = 0,
    Start,
    Data,
    Stop
  };

  class RttyModem
  {
  public:
    static constexpr int MAX_PIPE = 1024;
    static constexpr int MAX_BITS = 2048;

    explicit RttyModem(double baud = 45.4545, double shift = 170.0,
                       double rxSampleRate = 12000.0, double txSampleRate = 48000.0);
    ~RttyModem();

    RttyModem(RttyModem const&) = delete;
    RttyModem& operator=(RttyModem const&) = delete;

    void setFrequency(double freqHz);
    double frequency() const { return frequency_; }

    void setBaud(double baud);
    double baud() const { return baud_; }

    void setShift(double shift);
    double shift() const { return shift_; }

    void setReverse(bool reverse) { reverse_ = reverse; }
    bool isReverse() const { return reverse_; }

    void setUos(bool uos) { uos_ = uos; }
    bool isUos() const { return uos_; }

    void setAfc(bool afc) { afc_ = afc; }
    bool isAfc() const { return afc_; }

    void setSquelch(double squelch) { squelch_ = squelch; }
    double squelch() const { return squelch_; }

    void rxInit();
    void txInit();

    // Ingest 12 kHz RX audio samples
    void rxProcess(int16_t const * samples, int count);
    void rxProcess(double const * samples, int count);

    // Retrieve decoded ASCII string accumulated during rxProcess
    std::string takeDecodedText();
    bool hasDecodedText() const { return !decodedBuffer_.empty(); }

    double lastFreqError() const { return freqErr_; }
    double lastSnr() const { return snrDb_; }
    double metric() const { return metric_; }

    // Synthesize 48 kHz TX audio waveforms
    std::vector<int16_t> modulateText(std::string const& text, double txFreqHz);
    std::vector<int16_t> modulatePreamble(int ltrsCount = 4, double txFreqHz = 1500.0);
    std::vector<int16_t> modulateIdle(double txFreqHz = 1500.0);
    std::vector<int16_t> modulatePostamble(double txFreqHz = 1500.0);

  private:
    void updateParameters();
    void resetFilters();
    bool isMarkSpace(int& correction);
    bool isMark() const;
    bool rxBit(bool bitVal);
    void updateMetric();

    // TX generation helpers
    void appendSymbol(bool mark, int sampleLen, double txFreqHz, std::vector<int16_t>& out);
    void appendChar(char c, double txFreqHz, std::vector<int16_t>& out);
    void appendBaudotCode(uint8_t code, double txFreqHz, std::vector<int16_t>& out);

    double baud_ {45.4545};
    double shift_ {170.0};
    double rxSampleRate_ {12000.0};
    double txSampleRate_ {48000.0};
    double stopBits_ {1.5};
    bool reverse_ {false};
    bool uos_ {true};
    bool afc_ {true};
    double squelch_ {2.0};

    double frequency_ {1500.0};
    double freqErr_ {0.0};
    double metric_ {0.0};
    double snrDb_ {0.0};
    double dcdContrast_ {0.0};

    int symbolLenRx_ {264};
    int stopLenRx_ {396};
    int filterLen_ {512};

    int symbolLenTx_ {1056};
    int stopLenTx_ {1584};

    // RX DSP state
    FFTFilter * markFilt_ {nullptr};
    FFTFilter * spaceFilt_ {nullptr};
    MovingAverage * bitsAvg_ {nullptr};

    double markPhase_ {0.0};
    double spacePhase_ {0.0};
    double markMag_ {0.0};
    double spaceMag_ {0.0};
    double markEnv_ {0.0};
    double spaceEnv_ {0.0};
    double markNoise_ {0.0};
    double spaceNoise_ {0.0};
    double sigPwr_ {0.0};
    double noisePwr_ {0.0};

    cmplx markHistory_[MAX_PIPE];
    cmplx spaceHistory_[MAX_PIPE];
    int inpPtr_ {0};

    bool bitBuf_[MAX_BITS];
    RxState rxState_ {RxState::Idle};
    int counter_ {0};
    int bitCntr_ {0};
    int rxData_ {0};
    ShiftState rxShift_ {ShiftState::Letters};
    char lastChar_ {'\0'};

    std::string decodedBuffer_;

    // TX DSP state
    Oscillator txOscMark_ {48000.0};
    Oscillator txOscSpace_ {48000.0};
    SymbolShaper txShaperMark_ {45.4545, 48000.0};
    SymbolShaper txShaperSpace_ {45.4545, 48000.0};
    ShiftState txShift_ {ShiftState::Letters};
  };
}

#endif // RTTY_MODEM_HPP
