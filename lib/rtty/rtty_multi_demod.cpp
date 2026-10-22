//
// N6NU 2026-10-22: signal search instead of a fixed channel grid, see the header.
//==============================================================================

#include "rtty_multi_demod.hpp"
#include <algorithm>
#include <cmath>

namespace Rtty
{
  RttyMultiDemod::RttyMultiDemod(double baud, double shift, double sampleRate)
    : baud_ {baud > 0.0 ? baud : 45.4545}
    , shift_ {shift > 0.0 ? shift : 170.0}
    , sampleRate_ {sampleRate > 0.0 ? sampleRate : 12000.0}
    , channels_(MAX_CHANNELS)
    , history_(historySamples, 0.0)
    , window_(scanSize)
    , spectrum_(scanSize / 2 + 1, 0.0)
  {
    for (int i = 0; i < scanSize; ++i)
      window_[i] = 0.5 - 0.5 * std::cos(2.0 * M_PI * i / scanSize);
    fftIn_ = static_cast<float *>(fftwf_malloc(sizeof(float) * scanSize));
    fftOut_ = static_cast<fftwf_complex *>(fftwf_malloc(sizeof(fftwf_complex) * (scanSize / 2 + 1)));
    plan_ = fftwf_plan_dft_r2c_1d(scanSize, fftIn_, fftOut_, FFTW_ESTIMATE);
    reset();
  }

  RttyMultiDemod::~RttyMultiDemod()
  {
    if (plan_) fftwf_destroy_plan(plan_);
    fftwf_free(fftIn_);
    fftwf_free(fftOut_);
  }

  void RttyMultiDemod::setBandpass(double lowFreq, double highFreq)
  {
    // Channels outside a new band are released once their pair is no longer found.
    lowFreq_ = clamp(lowFreq, 100.0, 4000.0);
    highFreq_ = clamp(highFreq, lowFreq_ + 200.0, 5000.0);
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
    if (squelch > 0.0) thresholdDb_ = squelch;
  }

  void RttyMultiDemod::reset()
  {
    for (auto& slot : channels_) {
      int const generation = slot.generation;   // keeps growing, so stale text is never matched
      slot = ChannelSlot {};
      slot.generation = generation;
    }
    std::fill(history_.begin(), history_.end(), 0.0);
    std::fill(spectrum_.begin(), spectrum_.end(), 0.0);
    historyPos_ = 0;
    historyFill_ = 0;
    sinceScan_ = 0;
    scans_ = 0;
    pending_.clear();
    spectrumValid_ = false;
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
    // Feed at most up to the next scan at a time, so the search sees the audio
    // in step whatever the caller's block size.
    while (count > scanHop - sinceScan_) {
      int const n = scanHop - sinceScan_;
      rxProcess(samples, n);
      samples += n;
      count -= n;
    }

    for (int i = 0; i < count; ++i) {
      history_[historyPos_] = samples[i];
      historyPos_ = (historyPos_ + 1) % historySamples;
    }
    historyFill_ += count;

#if defined(_OPENMP)
#pragma omp parallel for schedule(dynamic)
#endif
    for (int i = 0; i < MAX_CHANNELS; ++i) {
      if (channels_[i].active && channels_[i].modem) {
        channels_[i].modem->rxProcess(samples, count);
      }
    }
    collectText();

    // Channels allocated by scan() are primed with the history, which already
    // holds this block, so they must not also get it from the loop above.
    sinceScan_ += count;
    while (sinceScan_ >= scanHop) {
      sinceScan_ -= scanHop;
      if (historyFill_ >= scanSize) scan();
    }
  }

  void RttyMultiDemod::scan()
  {
    // Newest scanSize samples, windowed
    int start = (historyPos_ - scanSize + historySamples) % historySamples;
    for (int i = 0; i < scanSize; ++i)
      fftIn_[i] = static_cast<float>(history_[(start + i) % historySamples] * window_[i]);
    fftwf_execute(plan_);
    int const nbins = scanSize / 2 + 1;
    for (int k = 0; k < nbins; ++k) {
      double const p = fftOut_[k][0] * fftOut_[k][0] + fftOut_[k][1] * fftOut_[k][1];
      spectrum_[k] = spectrumValid_ ? 0.65 * spectrum_[k] + 0.35 * p : p;
    }
    spectrumValid_ = true;
    if (++scans_ < 3) return;   // let the average settle: one raw spectrum shows false pairs

    double const df = sampleRate_ / scanSize;
    int const kLo = std::max(1, int(lowFreq_ / df));
    int const kHi = std::min(nbins - 1, int(highFreq_ / df));
    if (kHi - kLo < 100) return;
    std::vector<double> band(spectrum_.begin() + kLo, spectrum_.begin() + kHi);
    std::nth_element(band.begin(), band.begin() + band.size() / 2, band.end());
    double const noise = std::max(1e-20, band[band.size() / 2]);

    int const half = int(std::lround(shift_ / 2.0 / df));
    auto peak = [this, nbins] (int k) {
      double m = 0.0;
      for (int j = std::max(0, k - 2); j <= std::min(nbins - 1, k + 2); ++j) m = std::max(m, spectrum_[j]);
      return m;
    };
    // Signal power for the SNR: everything from one baud below space to one baud
    // above mark (the keying sidebands carry a good part of it), less the noise.
    int const wing = int(std::lround(baud_ / df));
    auto power = [this, nbins, half, wing, noise] (int c) {
      double s = 0.0;
      int n = 0;
      for (int j = std::max(0, c - half - wing); j <= std::min(nbins - 1, c + half + wing); ++j, ++n) s += spectrum_[j];
      return s - n * noise;
    };

    // Tone-pair score per centre bin: the weaker tone, if both stand out of the
    // noise, are not wildly unbalanced and the gap between them is quiet.
    double const threshold = noise * std::pow(10.0, thresholdDb_ / 10.0);
    std::vector<double> score(nbins, 0.0);
    for (int c = kLo + half + 3; c < kHi - half - 3; ++c) {
      double const mk = peak(c + half);
      double const sp = peak(c - half);
      double const weak = std::min(mk, sp);
      if (weak < threshold || std::max(mk, sp) > 20.0 * weak) continue;
      double mid = 0.0;
      for (int j = c - 3; j <= c + 3; ++j) mid += spectrum_[j];
      if (mid / 7.0 > weak / 3.0) continue;
      score[c] = weak;
    }

    struct Candidate { double score; int bin; };
    std::vector<Candidate> found;
    for (int c = kLo; c < kHi; ++c) {
      if (score[c] <= 0.0) continue;
      bool isMax = true;
      for (int j = std::max(0, c - 3); j <= std::min(nbins - 1, c + 3) && isMax; ++j)
        if (j != c && score[j] > score[c]) isMax = false;
      if (isMax) found.push_back({score[c], c});
    }
    std::sort(found.begin(), found.end(),
              [] (Candidate const& a, Candidate const& b) { return a.score > b.score; });

    std::vector<double> accepted;
    std::vector<double> pendingNow;
    for (auto const& cand : found) {
      double const fc = cand.bin * df;
      bool clash = false;
      for (double f : accepted) if (std::abs(f - fc) < 100.0) clash = true;
      if (clash) continue;
      accepted.push_back(fc);
      double const sig = std::max(1e-20, power(cand.bin));
      double const snrDb = 10.0 * std::log10(sig / noise * df / 2500.0);

      bool matched = false;
      for (auto& slot : channels_) {
        if (slot.active && std::abs(slot.frequency - fc) < matchHz) {
          matched = true;
          slot.missed = 0;
          slot.snr = snrDb;
          slot.frequency = fc;
          if (slot.modem && std::abs(slot.modem->frequency() - fc) > 10.0) slot.modem->setFrequency(fc);
          break;
        }
      }
      if (matched) continue;
      // A new pair gets a channel only when the previous scan saw it too
      bool confirmed = false;
      for (double f : pending_) if (std::abs(f - fc) < 10.0) confirmed = true;
      if (confirmed) allocate(fc, snrDb);
      else pendingNow.push_back(fc);
    }
    pending_ = pendingNow;

    for (auto& slot : channels_) {
      if (!slot.active) continue;
      bool seen = false;
      for (double f : accepted) if (std::abs(slot.frequency - f) < matchHz) seen = true;
      if (!seen && ++slot.missed > releaseScans) slot.active = false;
    }
    // Two channels that ended up on the same signal: keep the older one
    for (int i = 0; i < MAX_CHANNELS; ++i) {
      for (int j = i + 1; j < MAX_CHANNELS; ++j) {
        auto& a = channels_[i];
        auto& b = channels_[j];
        if (a.active && b.active && std::abs(a.frequency - b.frequency) < matchHz) {
          (a.age < b.age ? a : b).active = false;
        }
      }
    }
    for (auto& slot : channels_) if (slot.active) ++slot.age;
  }

  void RttyMultiDemod::allocate(double centerHz, double snrDb)
  {
    ChannelSlot * slot = nullptr;
    for (auto& s : channels_) {
      if (!s.active) { slot = &s; break; }
    }
    if (!slot) {                // all busy: take the one silent longest, if any is silent
      for (auto& s : channels_) {
        if (s.missed > hangoverScans && (!slot || s.missed > slot->missed)) slot = &s;
      }
    }
    if (!slot) return;
    if (!slot->modem) slot->modem.reset(new RttyModem(baud_, shift_, sampleRate_, 48000.0));
    slot->modem->setShift(shift_);
    slot->modem->setBaud(baud_);
    slot->modem->setReverse(reverse_);
    slot->modem->setUos(uos_);
    slot->modem->setSquelch(0.0);   // gated by the spectrum instead, see the header
    slot->modem->setContrastGate(contrastGate);
    slot->modem->setFrequency(centerHz);
    slot->modem->rxInit();
    slot->active = true;
    slot->frequency = centerHz;
    slot->missed = 0;
    slot->age = 0;
    ++slot->generation;
    slot->pending.clear();   // untaken text of the previous signal (only with very long caller blocks)
    slot->snr = snrDb;

    // Prime with the recent audio, oldest first, so the over is decoded from its start
    long long const have = std::min<long long>(historyFill_, historySamples);
    int const first = int((historyPos_ - have + historySamples) % historySamples);
    std::vector<double> past(static_cast<size_t>(have));
    for (long long i = 0; i < have; ++i) past[size_t(i)] = history_[(first + i) % historySamples];
    slot->modem->rxProcess(past.data(), int(have));
    if (slot->modem->hasDecodedText()) slot->pending += slot->modem->takeDecodedText();
  }

  // Text is gated when it is decoded, not when it is taken, so the result does
  // not depend on how often the caller asks.
  void RttyMultiDemod::collectText()
  {
    for (auto& slot : channels_) {
      if (slot.active && slot.modem && slot.modem->hasDecodedText()) {
        std::string const text = slot.modem->takeDecodedText();
        if (slot.missed <= hangoverScans) slot.pending += text;
      }
    }
  }

  std::vector<ChannelDecode> RttyMultiDemod::takeDecodes()
  {
    std::vector<ChannelDecode> results;
    for (int i = 0; i < MAX_CHANNELS; ++i) {
      auto& slot = channels_[i];
      if (!slot.pending.empty()) {
        results.push_back({i, slot.modem ? slot.modem->frequency() : slot.frequency, slot.pending, slot.snr});
        slot.pending.clear();
      }
    }
    return results;
  }

  bool RttyMultiDemod::signalAt(double freqHz, double tolHz) const
  {
    for (auto const& slot : channels_) {
      if (slot.active && slot.missed <= hangoverScans && std::abs(slot.frequency - freqHz) <= tolHz) return true;
    }
    return false;
  }
}
