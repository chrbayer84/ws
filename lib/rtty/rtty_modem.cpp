//==============================================================================
// rtty_modem.cpp:
//
// Standalone single-channel RTTY modem (adapted from fldigi by Dave Freese, W1HKJ)
//
// This file is part of WSJT-X.
//==============================================================================

#include "rtty_modem.hpp"
#include <cmath>
#include <algorithm>

namespace Rtty
{
  RttyModem::RttyModem(double baud, double shift, double rxSampleRate, double txSampleRate)
    : baud_ {baud > 0.0 ? baud : 45.4545}
    , shift_ {shift > 0.0 ? shift : 170.0}
    , rxSampleRate_ {rxSampleRate > 0.0 ? rxSampleRate : 12000.0}
    , txSampleRate_ {txSampleRate > 0.0 ? txSampleRate : 48000.0}
  {
    updateParameters();
    rxInit();
    txInit();
  }

  RttyModem::~RttyModem()
  {
    delete markFilt_;
    delete spaceFilt_;
    delete bitsAvg_;
  }

  void RttyModem::setFrequency(double freqHz)
  {
    frequency_ = clamp(freqHz, 100.0, 5000.0);
  }

  void RttyModem::setBaud(double baud)
  {
    if (baud > 0.0 && baud != baud_) {
      baud_ = baud;
      updateParameters();
      resetFilters();
    }
  }

  void RttyModem::setShift(double shift)
  {
    if (shift > 0.0 && shift != shift_) {
      shift_ = shift;
      updateParameters();
      resetFilters();
    }
  }

  void RttyModem::updateParameters()
  {
    symbolLenRx_ = static_cast<int>(rxSampleRate_ / baud_ + 0.5);
    if (symbolLenRx_ < 1) symbolLenRx_ = 1;
    stopLenRx_ = static_cast<int>(stopBits_ * rxSampleRate_ / baud_ + 0.5);

    symbolLenTx_ = static_cast<int>(txSampleRate_ / baud_ + 0.5);
    if (symbolLenTx_ < 1) symbolLenTx_ = 1;
    stopLenTx_ = static_cast<int>(stopBits_ * txSampleRate_ / baud_ + 0.5);

    filterLen_ = 512;
    if (baud_ >= 150.0) filterLen_ = 256;
    if (baud_ >= 200.0) filterLen_ = 128;
    if (baud_ >= 300.0) filterLen_ = 64;

    resetFilters();
  }

  void RttyModem::resetFilters()
  {
    delete markFilt_;
    delete spaceFilt_;
    double const f = baud_ / rxSampleRate_;
    markFilt_ = new FFTFilter(f, filterLen_);
    spaceFilt_ = new FFTFilter(f, filterLen_);

    if (!bitsAvg_) {
      bitsAvg_ = new MovingAverage(std::max(1, symbolLenRx_ / 8));
    } else {
      bitsAvg_->setLength(std::max(1, symbolLenRx_ / 8));
    }

    txShaperMark_.preset(baud_, txSampleRate_);
    txShaperSpace_.preset(baud_, txSampleRate_);
  }

  void RttyModem::rxInit()
  {
    rxState_ = RxState::Idle;
    rxShift_ = ShiftState::Letters;
    counter_ = 0;
    bitCntr_ = 0;
    rxData_ = 0;
    lastChar_ = '\0';
    freqErr_ = 0.0;
    metric_ = 0.0;
    snrDb_ = 0.0;

    markPhase_ = 0.0;
    spacePhase_ = 0.0;
    markMag_ = 0.0;
    spaceMag_ = 0.0;
    markEnv_ = 0.0;
    spaceEnv_ = 0.0;
    markNoise_ = 0.0;
    spaceNoise_ = 0.0;
    sigPwr_ = 1e-12;
    noisePwr_ = 1.0;
    dcdContrast_ = 0.0;

    inpPtr_ = 0;
    for (int i = 0; i < MAX_PIPE; ++i) {
      markHistory_[i] = cmplx(0.0, 0.0);
      spaceHistory_[i] = cmplx(0.0, 0.0);
    }
    for (int i = 0; i < MAX_BITS; ++i) {
      bitBuf_[i] = false;
    }

    if (markFilt_) markFilt_->clear_filter();
    if (spaceFilt_) spaceFilt_->clear_filter();
    if (bitsAvg_) bitsAvg_->reset();
  }

  void RttyModem::txInit()
  {
    txShift_ = ShiftState::Letters;
    txShaperMark_.reset();
    txShaperSpace_.reset();
    txOscMark_.resetPhase();
    txOscSpace_.resetPhase();
  }

  bool RttyModem::isMarkSpace(int& correction)
  {
    correction = 0;
    if (symbolLenRx_ >= MAX_BITS) return false;
    if (bitBuf_[0] && !bitBuf_[symbolLenRx_ - 1]) {
      for (int i = 0; i < symbolLenRx_; ++i) {
        correction += bitBuf_[i] ? 1 : 0;
      }
      if (std::abs(symbolLenRx_ / 2 - correction) < std::max(2, symbolLenRx_ / 10)) {
        return true;
      }
    }
    return false;
  }

  bool RttyModem::isMark() const
  {
    if (symbolLenRx_ / 2 < MAX_BITS) {
      return bitBuf_[symbolLenRx_ / 2];
    }
    return false;
  }

  bool RttyModem::rxBit(bool bitVal)
  {
    bool validChar = false;
    int correction = 0;

    for (int i = 1; i < symbolLenRx_ && i < MAX_BITS; ++i) {
      bitBuf_[i - 1] = bitBuf_[i];
    }
    bitBuf_[std::min(symbolLenRx_ - 1, MAX_BITS - 1)] = bitVal;

    switch (rxState_) {
    case RxState::Idle:
      if (metric_ >= squelch_ || squelch_ <= 0.0) {
        if (isMarkSpace(correction)) {
          rxState_ = RxState::Start;
          counter_ = correction;
        }
      }
      break;

    case RxState::Start:
      if (--counter_ <= 0) {
        if (!isMark() && (metric_ >= squelch_ || squelch_ <= 0.0)) {
          rxState_ = RxState::Data;
          counter_ = symbolLenRx_;
          bitCntr_ = 0;
          rxData_ = 0;
        } else {
          rxState_ = RxState::Idle;
        }
      }
      break;

    case RxState::Data:
      if (--counter_ <= 0) {
        rxData_ |= (isMark() ? 1 : 0) << bitCntr_++;
        counter_ = symbolLenRx_;
      }
      if (bitCntr_ >= 5) {
        rxState_ = RxState::Stop;
      }
      break;

    case RxState::Stop:
      if (--counter_ <= 0) {
        if (isMark()) {
          // If we have a very low metric score, consider it garbage and drop it
          if (metric_ >= squelch_ || squelch_ <= 0.0) {
            char c = Baudot::decode(rxData_, rxShift_, uos_);
            if (c != '\0') {
              // Suppress duplicate CR or LF sequences
              if ((c == '\r' && lastChar_ == '\r') || (c == '\n' && lastChar_ == '\n')) {
                // ignore duplicate
              } else {
                decodedBuffer_ += c;
              }
              lastChar_ = c;
            }
          }
          validChar = true;
        }
        rxState_ = RxState::Idle;
      }
      break;
    }

    return validChar;
  }

  void RttyModem::updateMetric()
  {
    double const sigLevel = std::max(markEnv_, spaceEnv_);
    double const noiseLevel = std::min(markNoise_, spaceNoise_) + 1e-6;
    snrDb_ = 20.0 * std::log10(std::max(1.0, sigLevel / noiseLevel));
  }

  void RttyModem::rxProcess(int16_t const * samples, int count)
  {
    if (!samples || count <= 0) return;
    std::vector<double> dblBuf(count);
    for (int i = 0; i < count; ++i) {
      dblBuf[i] = static_cast<double>(samples[i]) / 32768.0;
    }
    rxProcess(dblBuf.data(), count);
  }

  void RttyModem::rxProcess(double const * samples, int count)
  {
    if (!samples || count <= 0 || !markFilt_ || !spaceFilt_) return;

    double const markFreq = reverse_ ? (frequency_ - shift_ / 2.0) : (frequency_ + shift_ / 2.0);
    double const spaceFreq = reverse_ ? (frequency_ + shift_ / 2.0) : (frequency_ - shift_ / 2.0);

    double const markDelta = 2.0 * M_PI * markFreq / rxSampleRate_;
    double const spaceDelta = 2.0 * M_PI * spaceFreq / rxSampleRate_;

    for (int sampleIdx = 0; sampleIdx < count; ++sampleIdx) {
      double const inVal = samples[sampleIdx];
      cmplx const z(inVal, inVal);

      // Downconvert Mark and Space to baseband analytic signals
      cmplx const zmark = z * cmplx(std::cos(markPhase_), -std::sin(markPhase_));
      markPhase_ += markDelta;
      if (markPhase_ > 2.0 * M_PI) markPhase_ = std::fmod(markPhase_, 2.0 * M_PI);

      cmplx const zspace = z * cmplx(std::cos(spacePhase_), -std::sin(spacePhase_));
      spacePhase_ += spaceDelta;
      if (spacePhase_ > 2.0 * M_PI) spacePhase_ = std::fmod(spacePhase_, 2.0 * M_PI);

      cmplx * zpMark = nullptr;
      cmplx * zpSpace = nullptr;

      markFilt_->run(zmark, &zpMark);
      int const nOut = spaceFilt_->run(zspace, &zpSpace);

      if (nOut > 0 && zpMark && zpSpace) {
        for (int i = 0; i < nOut; ++i) {
          markMag_ = std::abs(zpMark[i]);
          markEnv_ = decayavg(markEnv_, markMag_, (markMag_ > markEnv_) ? symbolLenRx_ / 4 : symbolLenRx_ * 16);
          markNoise_ = decayavg(markNoise_, markMag_, (markMag_ < markNoise_) ? symbolLenRx_ / 4 : symbolLenRx_ * 48);

          spaceMag_ = std::abs(zpSpace[i]);
          spaceEnv_ = decayavg(spaceEnv_, spaceMag_, (spaceMag_ > spaceEnv_) ? symbolLenRx_ / 4 : symbolLenRx_ * 16);
          spaceNoise_ = decayavg(spaceNoise_, spaceMag_, (spaceMag_ < spaceNoise_) ? symbolLenRx_ / 4 : symbolLenRx_ * 48);

          double const noiseFloor = std::min(spaceNoise_, markNoise_);
          double mclipped = clamp(markMag_, noiseFloor, markEnv_);
          double sclipped = clamp(spaceMag_, noiseFloor, spaceEnv_);

          // Optimal ATC Slicer
          double const v3 = (mclipped - noiseFloor) * (markEnv_ - noiseFloor)
                          - (sclipped - noiseFloor) * (spaceEnv_ - noiseFloor)
                          - 0.25 * ((markEnv_ - noiseFloor) * (markEnv_ - noiseFloor)
                                  - (spaceEnv_ - noiseFloor) * (spaceEnv_ - noiseFloor));

          bool bit = (v3 > 0.0);

          // Instantaneous FSK tone contrast (near ~0.85 on signal, ~0.12 on Gaussian noise)
          double const totalTone = markMag_ + spaceMag_;
          double const diffTone = std::abs(markMag_ - spaceMag_);
          double const instContrast = totalTone > 1e-4 ? (diffTone / totalTone) : 0.0;
          dcdContrast_ = decayavg(dcdContrast_, instContrast, symbolLenRx_ / 2);
          metric_ = clamp((dcdContrast_ - 0.22) / 0.50 * 10.0, 0.0, 10.0);

          markHistory_[inpPtr_] = zpMark[i];
          spaceHistory_[inpPtr_] = zpSpace[i];
          inpPtr_ = (inpPtr_ + 1) % MAX_PIPE;

          if (rxBit(reverse_ ? !bit : bit)) {
            if (afc_) {
              int const mp0 = (inpPtr_ - 2 + MAX_PIPE) % MAX_PIPE;
              int const mp1 = (mp0 + 1) % MAX_PIPE;
              double ferr = (2.0 * M_PI * rxSampleRate_ / baud_) *
                            (!reverse_ ?
                              std::arg(std::conj(markHistory_[mp1]) * markHistory_[mp0]) :
                              std::arg(std::conj(spaceHistory_[mp1]) * spaceHistory_[mp0]));
              if (std::abs(ferr) > baud_ / 2.0) ferr = 0.0;
              freqErr_ = decayavg(freqErr_, ferr / 8.0, 4);
              if (metric_ >= squelch_ || squelch_ <= 0.0) {
                setFrequency(frequency_ - freqErr_);
              }
            }
          }
        }
      }
    }

    updateMetric();
  }

  std::string RttyModem::takeDecodedText()
  {
    std::string result = std::move(decodedBuffer_);
    decodedBuffer_.clear();
    return result;
  }

  void RttyModem::appendSymbol(bool mark, int sampleLen, double txFreqHz, std::vector<int16_t>& out)
  {
    bool const sym = reverse_ ? !mark : mark;
    double const freqMark = txFreqHz + shift_ / 2.0;
    double const freqSpace = txFreqHz - shift_ / 2.0;

    for (int i = 0; i < sampleLen; ++i) {
      double const markAmp = txShaperMark_.update(sym) * txOscMark_.update(freqMark);
      double const spaceAmp = txShaperSpace_.update(!sym) * txOscSpace_.update(freqSpace);
      double const signal = markAmp + spaceAmp;

      double clamped = clamp(signal, -1.0, 1.0);
      out.push_back(static_cast<int16_t>(std::round(clamped * 32767.0)));
    }
  }

  void RttyModem::appendBaudotCode(uint8_t code, double txFreqHz, std::vector<int16_t>& out)
  {
    // Start bit (Space = false)
    appendSymbol(false, symbolLenTx_, txFreqHz, out);

    // 5 Data bits (LSB first)
    for (int bit = 0; bit < 5; ++bit) {
      bool const bitVal = ((code >> bit) & 1) != 0;
      appendSymbol(bitVal, symbolLenTx_, txFreqHz, out);
    }

    // Stop bit(s) (Mark = true)
    appendSymbol(true, stopLenTx_, txFreqHz, out);
  }

  void RttyModem::appendChar(char c, double txFreqHz, std::vector<int16_t>& out)
  {
    if (c == ' ' && uos_) {
      if (txShift_ != ShiftState::Letters) {
        appendBaudotCode(Baudot::LTRS_CODE, txFreqHz, out);
        txShift_ = ShiftState::Letters;
      }
      appendBaudotCode(Baudot::SPACE_CODE, txFreqHz, out);
      return;
    }

    auto const encoded = Baudot::encode(c);
    if (!encoded.valid) return;

    if (encoded.requiredShift != txShift_) {
      if (encoded.requiredShift == ShiftState::Figures) {
        appendBaudotCode(Baudot::FIGS_CODE, txFreqHz, out);
        txShift_ = ShiftState::Figures;
      } else {
        appendBaudotCode(Baudot::LTRS_CODE, txFreqHz, out);
        txShift_ = ShiftState::Letters;
      }
    }

    appendBaudotCode(encoded.code, txFreqHz, out);
  }

  std::vector<int16_t> RttyModem::modulateText(std::string const& text, double txFreqHz)
  {
    std::vector<int16_t> out;
    out.reserve(text.size() * (symbolLenTx_ * 6 + stopLenTx_));
    for (char c : text) {
      appendChar(c, txFreqHz, out);
    }
    return out;
  }

  std::vector<int16_t> RttyModem::modulatePreamble(int ltrsCount, double txFreqHz)
  {
    std::vector<int16_t> out;
    out.reserve(ltrsCount * (symbolLenTx_ * 6 + stopLenTx_));
    for (int i = 0; i < ltrsCount; ++i) {
      appendBaudotCode(Baudot::LTRS_CODE, txFreqHz, out);
    }
    txShift_ = ShiftState::Letters;
    return out;
  }

  std::vector<int16_t> RttyModem::modulateIdle(double txFreqHz)
  {
    std::vector<int16_t> out;
    appendBaudotCode(Baudot::LTRS_CODE, txFreqHz, out);
    txShift_ = ShiftState::Letters;
    return out;
  }

  std::vector<int16_t> RttyModem::modulatePostamble(double txFreqHz)
  {
    std::vector<int16_t> out;
    appendBaudotCode(Baudot::CR_CODE, txFreqHz, out);
    appendBaudotCode(Baudot::LF_CODE, txFreqHz, out);
    appendBaudotCode(Baudot::LTRS_CODE, txFreqHz, out);
    txShift_ = ShiftState::Letters;
    return out;
  }
}
