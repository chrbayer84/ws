#include "psk_carrier_detector.hpp"

#include <algorithm>
#include <cmath>
#include <numeric>
#include <vector>

#if defined(__has_include)
#  if __has_include(<fftw3f.h>)
#    include <fftw3f.h>
#  else
#    include <fftw3.h>
#  endif
#else
#  include <fftw3.h>
#endif

namespace Psk {

namespace
{
  constexpr double twoPi = 6.283185307179586476925286766559;

  int clampInt(int value, int low, int high)
  {
    return std::max(low, std::min(high, value));
  }

  double median(std::vector<double>& values)
  {
    if (values.empty()) return 0.0;
    auto const middle = values.begin() + static_cast<std::ptrdiff_t>(values.size() / 2);
    std::nth_element(values.begin(), middle, values.end());
    return *middle;
  }
}

struct CarrierDetector::Impl
{
  double sampleRate {12000.0};
  int fftSize {8192};
  int hopSize {2048};
  int passLow {0};
  int passHigh {6000};
  double bandwidth {31.25};
  double thresholdDb {6.0};

  std::vector<float> ring;
  int ringPos {0};
  int filled {0};
  int sinceAnalysis {0};
  std::uint64_t totalSamples {0};
  std::uint64_t sequence {0};

  std::vector<double> window;
  std::vector<float> timeDomain;
  std::vector<float> power;
  std::vector<double> smoothed;
  std::vector<double> noiseScratch;
  fftwf_complex* freqDomain {nullptr};
  fftwf_plan plan {nullptr};
  std::vector<CarrierCandidate> candidates;
  std::vector<CarrierCandidate> peakCandidates;

  Impl(double rate, int nfft, int hop)
    : sampleRate {rate}, fftSize {nfft}, hopSize {hop}
  {
    if (fftSize < 256) fftSize = 256;
    if (hopSize < 1) hopSize = fftSize / 4;
    passHigh = static_cast<int>(sampleRate / 2.0);
    ring.assign(static_cast<std::size_t>(fftSize), 0.0f);
    window.resize(static_cast<std::size_t>(fftSize));
    for (int i = 0; i < fftSize; ++i) {
      window[static_cast<std::size_t>(i)] =
        0.5 * (1.0 - std::cos(twoPi * i / fftSize));
    }
    timeDomain.resize(static_cast<std::size_t>(fftSize));
    power.resize(static_cast<std::size_t>(fftSize / 2 + 1));
    smoothed.resize(power.size());
    freqDomain = fftwf_alloc_complex(static_cast<std::size_t>(power.size()));
    if (freqDomain) {
      plan = fftwf_plan_dft_r2c_1d(fftSize, timeDomain.data(), freqDomain,
                                   FFTW_ESTIMATE);
    }
  }

  ~Impl()
  {
    if (plan) fftwf_destroy_plan(plan);
    if (freqDomain) fftwf_free(freqDomain);
  }

  void reset()
  {
    std::fill(ring.begin(), ring.end(), 0.0f);
    ringPos = 0;
    filled = 0;
    sinceAnalysis = 0;
    totalSamples = 0;
    sequence = 0;
    candidates.clear();
    peakCandidates.clear();
  }

  double binWidth() const
  {
    return sampleRate / static_cast<double>(fftSize);
  }

  int binFor(double frequency) const
  {
    return clampInt(static_cast<int>(std::lround(frequency / binWidth())),
                      0, static_cast<int>(power.size()) - 1);
  }

  void analyse()
  {
    if (!plan) return;

    for (int i = 0; i < fftSize; ++i) {
      int const source = (ringPos + i) % fftSize;
      timeDomain[static_cast<std::size_t>(i)] =
        static_cast<float>(ring[static_cast<std::size_t>(source)] *
                           window[static_cast<std::size_t>(i)]);
    }
    fftwf_execute(plan);

    for (std::size_t i = 0; i < power.size(); ++i) {
      double const re = freqDomain[i][0];
      double const im = freqDomain[i][1];
      power[i] = static_cast<float>(re * re + im * im);
    }

    int const halfWindow =
      std::max(1, static_cast<int>(std::lround(0.5 * bandwidth / binWidth())));
    int const lastBin = static_cast<int>(power.size()) - 1;

    // Moving-average power over roughly one PSK bandwidth. PSK31 is a
    // suppressed-carrier signal, so the raw FFT peak is usually a sideband
    // edge; the centre of the shaped group is the useful frequency estimate.
    double running = 0.0;
    for (int i = -halfWindow; i <= halfWindow; ++i) {
      running += power[static_cast<std::size_t>(clampInt(i, 0, lastBin))];
    }
    int const denominator = 2 * halfWindow + 1;
    for (int i = 0; i <= lastBin; ++i) {
      smoothed[static_cast<std::size_t>(i)] = running / denominator;
      int const add = clampInt(i + halfWindow + 1, 0, lastBin);
      int const remove = clampInt(i - halfWindow, 0, lastBin);
      running += power[static_cast<std::size_t>(add)] -
                 power[static_cast<std::size_t>(remove)];
    }

    int const lowBin = clampInt(binFor(passLow), 0, lastBin);
    int const highBin = clampInt(binFor(passHigh), lowBin, lastBin);

    noiseScratch.clear();
    noiseScratch.reserve(static_cast<std::size_t>(std::max(1, highBin - lowBin + 1)));
    double peakPower = 0.0;
    for (int i = lowBin; i <= highBin; ++i) {
      double const value = smoothed[static_cast<std::size_t>(i)];
      noiseScratch.push_back(value);
      peakPower = std::max(peakPower, value);
    }
    double noise = median(noiseScratch);
    // Synthetic and very quiet audio can contain long exact-zero stretches.
    // Do not let those drive the noise floor to zero and turn FFT sidelobes
    // into hundreds of fake carriers.
    noise = std::max(noise, peakPower * 1.0e-6);
    if (noise < 1.0e-12) noise = 1.0e-12;

    double const threshold = noise * std::pow(10.0, thresholdDb / 10.0);

    candidates.clear();
    peakCandidates.clear();
    int i = lowBin;
    while (i <= highBin) {
      if (smoothed[static_cast<std::size_t>(i)] <= threshold) {
        ++i;
        continue;
      }
      int regionBegin = i;
      int regionEnd = i;
      while (regionEnd + 1 <= highBin &&
             smoothed[static_cast<std::size_t>(regionEnd + 1)] > threshold) {
        ++regionEnd;
      }

      int regionPeakBin = regionBegin;
      for (int k = regionBegin; k <= regionEnd; ++k) {
        if (smoothed[static_cast<std::size_t>(k)] >
            smoothed[static_cast<std::size_t>(regionPeakBin)]) {
          regionPeakBin = k;
        }
      }

      {
        double const peakPower =
          smoothed[static_cast<std::size_t>(regionPeakBin)];
        double const groupThreshold = peakPower * 0.75;
        int groupBegin = regionPeakBin;
        int groupEnd = regionPeakBin;
        while (groupBegin > regionBegin &&
               smoothed[static_cast<std::size_t>(groupBegin - 1)] >
                 groupThreshold) {
          --groupBegin;
        }
        while (groupEnd < regionEnd &&
               smoothed[static_cast<std::size_t>(groupEnd + 1)] >
                 groupThreshold) {
          ++groupEnd;
        }

        CarrierCandidate candidate;
        candidate.frequency = 0.5 * (groupBegin + groupEnd) * binWidth();
        candidate.power = peakPower;
        candidate.prominence = peakPower / noise;
        candidate.bandwidth = (groupEnd - groupBegin) * binWidth();
        candidate.peakBased = false;
        candidates.push_back(candidate);
      }

      for (int peakBin = regionBegin; peakBin <= regionEnd; ++peakBin) {
        double const peakPower = smoothed[static_cast<std::size_t>(peakBin)];
        if (peakPower <= threshold) continue;
        if (peakBin > regionBegin &&
            peakPower < smoothed[static_cast<std::size_t>(peakBin - 1)]) {
          continue;
        }
        if (peakBin < regionEnd &&
            peakPower < smoothed[static_cast<std::size_t>(peakBin + 1)]) {
          continue;
        }
        if (peakBin > regionBegin &&
            peakPower == smoothed[static_cast<std::size_t>(peakBin - 1)]) {
          continue;
        }

        double const groupThreshold = peakPower * 0.75;
        int groupBegin = peakBin;
        int groupEnd = peakBin;
        while (groupBegin > regionBegin) {
          double const previous =
            smoothed[static_cast<std::size_t>(groupBegin - 1)];
          double const current =
            smoothed[static_cast<std::size_t>(groupBegin)];
          if (previous <= groupThreshold || previous > current) break;
          --groupBegin;
        }
        while (groupEnd < regionEnd) {
          double const next =
            smoothed[static_cast<std::size_t>(groupEnd + 1)];
          double const current =
            smoothed[static_cast<std::size_t>(groupEnd)];
          if (next <= groupThreshold || next > current) break;
          ++groupEnd;
        }

        CarrierCandidate candidate;
        candidate.frequency = 0.5 * (groupBegin + groupEnd) * binWidth();
        candidate.power = peakPower;
        candidate.prominence = peakPower / noise;
        candidate.bandwidth = 0.0;
        candidate.peakBased = true;
        peakCandidates.push_back(candidate);
      }

      i = regionEnd + 1;
    }

    ++sequence;
  }
};

CarrierDetector::CarrierDetector(double sampleRate, int fftSize, int hopSize)
  : impl_ {new Impl(sampleRate, fftSize, hopSize)}
{
}

CarrierDetector::~CarrierDetector() = default;

void CarrierDetector::setSampleRate(double rate)
{
  if (std::abs(impl_->sampleRate - rate) > 0.01) {
    impl_->sampleRate = rate;
    impl_->reset();
  }
}

void CarrierDetector::setPassband(int lowHz, int highHz)
{
  if (lowHz < 0) lowHz = 0;
  if (highHz <= lowHz) highHz = lowHz + 1;
  highHz = std::min(highHz, static_cast<int>(impl_->sampleRate / 2.0));
  if (impl_->passLow != lowHz || impl_->passHigh != highHz) {
    impl_->passLow = lowHz;
    impl_->passHigh = highHz;
    impl_->reset();
  }
}

void CarrierDetector::setBandwidth(double widthHz)
{
  if (widthHz > 0.1 && std::abs(impl_->bandwidth - widthHz) > 0.01) {
    impl_->bandwidth = widthHz;
    impl_->reset();
  }
}

void CarrierDetector::setThresholdDb(double db)
{
  impl_->thresholdDb = db;
}

void CarrierDetector::reset()
{
  impl_->reset();
}

void CarrierDetector::process(int16_t const* samples, int count)
{
  if (!samples || count <= 0) return;

  for (int i = 0; i < count; ++i) {
    impl_->ring[static_cast<std::size_t>(impl_->ringPos)] =
      static_cast<float>(samples[i]) / 32768.0f;
    impl_->ringPos = (impl_->ringPos + 1) % impl_->fftSize;
    if (impl_->filled < impl_->fftSize) ++impl_->filled;
    ++impl_->totalSamples;
    ++impl_->sinceAnalysis;

    if (impl_->filled == impl_->fftSize &&
        impl_->sinceAnalysis >= impl_->hopSize) {
      impl_->sinceAnalysis = 0;
      impl_->analyse();
    }
  }
}

std::uint64_t CarrierDetector::sequence() const
{
  return impl_->sequence;
}

std::vector<CarrierCandidate> const& CarrierDetector::candidates() const
{
  return impl_->candidates;
}

bool CarrierDetector::peakInRange(double lowHz, double highHz,
                                  CarrierCandidate& result) const
{
  bool found = false;
  for (auto const& candidate : impl_->candidates) {
    if (candidate.frequency < lowHz || candidate.frequency > highHz) continue;
    if (!found || candidate.power > result.power) {
      result = candidate;
      found = true;
    }
  }
  return found;
}

std::vector<CarrierCandidate> CarrierDetector::detectAll(
  double minSeparationHz) const
{
  // Use a group centre for a lone PSK signal. Split only when the group
  // contains at least two strong peaks separated by a real channel spacing;
  // this avoids turning PSK sidebands into fake carriers while still finding
  // closely spaced stations.
  if (minSeparationHz < 1.0) minSeparationHz = 1.0;

  std::vector<CarrierCandidate> selected;
  for (auto const& group : impl_->candidates) {
    double const halfWidth = 0.5 * group.bandwidth + impl_->bandwidth;
    std::vector<CarrierCandidate> peaks;
    for (auto const& peak : impl_->peakCandidates) {
      if (std::abs(peak.frequency - group.frequency) <= halfWidth &&
          peak.power >= 0.75 * group.power) {
        peaks.push_back(peak);
      }
    }

    bool split = false;
    for (std::size_t i = 0; i < peaks.size() && !split; ++i) {
      for (std::size_t j = i + 1; j < peaks.size(); ++j) {
        if (std::abs(peaks[i].frequency - peaks[j].frequency) >=
            minSeparationHz) {
          split = true;
          break;
        }
      }
    }

    if (split) {
      selected.insert(selected.end(), peaks.begin(), peaks.end());
    } else {
      selected.push_back(group);
    }
  }

  std::sort(selected.begin(), selected.end(),
            [] (CarrierCandidate const& lhs, CarrierCandidate const& rhs) {
              return lhs.frequency < rhs.frequency;
            });

  // Frequency-ordered suppression keeps the outer carriers of a close pair
  // instead of letting an overlap peak in the middle win on raw power.
  std::vector<CarrierCandidate> accepted;
  for (auto const& candidate : selected) {
    if (!accepted.empty() &&
        std::abs(candidate.frequency - accepted.back().frequency) <
          minSeparationHz) {
      continue;
    }
    accepted.push_back(candidate);
  }
  return accepted;
}

} // namespace Psk
