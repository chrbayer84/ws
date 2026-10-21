//==============================================================================
// rtty_multi_demod.cpp:
//
// Multi-channel panoramic RTTY demodulator (adapted from fldigi by Dave Freese)
//
// This file is part of WSJT-X.
//==============================================================================

#include "rtty_multi_demod.hpp"
#include <algorithm>

namespace Rtty
{
  RttyMultiDemod::RttyMultiDemod(double baud, double shift, double sampleRate)
    : baud_ {baud > 0.0 ? baud : 45.4545}
    , shift_ {shift > 0.0 ? shift : 170.0}
    , sampleRate_ {sampleRate > 0.0 ? sampleRate : 12000.0}
    , channels_(MAX_CHANNELS)
  {
    reset();
  }

  RttyMultiDemod::~RttyMultiDemod() = default;

  void RttyMultiDemod::setBandpass(double lowFreq, double highFreq)
  {
    double clampedLow = clamp(lowFreq, 100.0, 4000.0);
    double clampedHigh = clamp(highFreq, clampedLow + 200.0, 5000.0);
    if (std::abs(clampedLow - lowFreq_) < 1.0 && std::abs(clampedHigh - highFreq_) < 1.0) {
      return;
    }
    lowFreq_ = clampedLow;
    highFreq_ = clampedHigh;
    reset();
  }

  void RttyMultiDemod::setBaud(double baud)
  {
    if (baud > 0.0 && baud != baud_) {
      baud_ = baud;
      for (auto& slot : channels_) {
        if (slot.modem) slot.modem->setBaud(baud_);
      }
    }
  }

  void RttyMultiDemod::setShift(double shift)
  {
    if (shift > 0.0 && shift != shift_) {
      shift_ = shift;
      for (auto& slot : channels_) {
        if (slot.modem) slot.modem->setShift(shift_);
      }
    }
  }

  void RttyMultiDemod::setReverse(bool reverse)
  {
    reverse_ = reverse;
    for (auto& slot : channels_) {
      if (slot.modem) slot.modem->setReverse(reverse_);
    }
  }

  void RttyMultiDemod::setUos(bool uos)
  {
    uos_ = uos;
    for (auto& slot : channels_) {
      if (slot.modem) slot.modem->setUos(uos_);
    }
  }

  void RttyMultiDemod::setSquelch(double squelch)
  {
    squelch_ = squelch;
    for (auto& slot : channels_) {
      if (slot.modem) slot.modem->setSquelch(squelch_);
    }
  }

  void RttyMultiDemod::reset()
  {
    double const span = highFreq_ - lowFreq_;
    double const step = span / static_cast<double>(MAX_CHANNELS);

    for (int i = 0; i < MAX_CHANNELS; ++i) {
      channels_[i].active = true;
      channels_[i].frequency = lowFreq_ + (i + 0.5) * step;
      channels_[i].timeout = 0;
      if (!channels_[i].modem) {
        channels_[i].modem = std::unique_ptr<RttyModem>(new RttyModem(baud_, shift_, sampleRate_, 48000.0));
      }
      channels_[i].modem->setFrequency(channels_[i].frequency);
      channels_[i].modem->setReverse(reverse_);
      channels_[i].modem->setUos(uos_);
      channels_[i].modem->setSquelch(squelch_);
      channels_[i].modem->rxInit();
    }
  }

  void RttyMultiDemod::rxProcess(int16_t const * samples, int count)
  {
    if (!samples || count <= 0) return;
    std::vector<double> dblBuf(count);
    for (int i = 0; i < count; ++i) {
      dblBuf[i] = static_cast<double>(samples[i]) / 32768.0;
    }
    rxProcess(dblBuf.data(), count);
  }

  void RttyMultiDemod::rxProcess(double const * samples, int count)
  {
    if (!samples || count <= 0) return;

#if defined(_OPENMP)
#pragma omp parallel for schedule(static)
#endif
    for (int i = 0; i < MAX_CHANNELS; ++i) {
      if (channels_[i].active && channels_[i].modem) {
        channels_[i].modem->rxProcess(samples, count);
      }
    }
  }

  std::vector<ChannelDecode> RttyMultiDemod::takeDecodes()
  {
    std::vector<ChannelDecode> results;
    for (int i = 0; i < MAX_CHANNELS; ++i) {
      auto& slot = channels_[i];
      if (slot.active && slot.modem && slot.modem->hasDecodedText()) {
        std::string text = slot.modem->takeDecodedText();
        if (!text.empty()) {
          results.push_back({i, slot.modem->frequency(), text, slot.modem->lastSnr()});
        }
      }
    }
    return results;
  }
}
