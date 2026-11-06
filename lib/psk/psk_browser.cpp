#include "psk_browser.hpp"

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <utility>

namespace Psk {

namespace
{
  int textQuality(std::string const& text)
  {
    int score = static_cast<int>(text.size());
    std::string word;
    auto finishWord = [&] {
      if (word.empty()) return;
      std::string upper;
      upper.reserve(word.size());
      bool hasDigit = false;
      bool hasLetter = false;
      for (unsigned char c : word) {
        if (c >= 'a' && c <= 'z') c = static_cast<unsigned char>(c - 'a' + 'A');
        if (c >= '0' && c <= '9') hasDigit = true;
        if (c >= 'A' && c <= 'Z') hasLetter = true;
        upper.push_back(static_cast<char>(c));
      }
      if (upper == "CQ" || upper == "DE" || upper == "QRZ") {
        score += 100;
      } else if (hasDigit && hasLetter && upper.size() >= 3 && upper.size() <= 11) {
        score += 50;
      }
      word.clear();
    };

    for (char c : text) {
      if (c == ' ' || c == '\t' || c == '\r' || c == '\n') {
        finishWord();
      } else {
        word.push_back(c);
      }
    }
    finishWord();
    return score;
  }

  int clampInt(int value, int low, int high)
  {
    return std::max(low, std::min(high, value));
  }

  std::vector<double> probeOffsets (bool dynamic)
  {
    double const limit = dynamic ? 6.0 : 2.0;
    std::vector<double> offsets;
    offsets.reserve (static_cast<std::size_t> (2.0 * limit / 0.5) + 1);
    for (double offset = -limit; offset <= limit + 0.01; offset += 0.5) {
      offsets.push_back (offset);
    }
    return offsets;
  }
}

PskBrowser::PskBrowser(double sampleRate)
  : sampleRate_ {sampleRate}
  , detector_ {sampleRate}
{
  channels_.resize(MAX_CHANNELS + 1);
  buildSlots();
  reset();
}

PskBrowser::~PskBrowser() = default;

void PskBrowser::configure(Config const& config)
{
  config_ = config;
  config_.channels = clampInt(config_.channels, 1, MAX_CHANNELS);
  config_.maxCarriers = clampInt(config_.maxCarriers, 1, MAX_CHANNELS);
  config_.lowFrequency = std::max(0, config_.lowFrequency);
  config_.highFrequency = std::max(config_.lowFrequency + 1, config_.highFrequency);
  config_.baud = std::max(1.0, config_.baud);
  config_.bandwidthHz = std::max(1.0, config_.bandwidthHz);
  config_.minSeparationHz = std::max(1.0, config_.minSeparationHz);
  config_.timeoutSeconds = std::max(0.25, config_.timeoutSeconds);
  config_.probeSeconds = std::max(0.25, config_.probeSeconds);

  detector_.setSampleRate(sampleRate_);
  detector_.setPassband(config_.lowFrequency, config_.highFrequency);
  detector_.setBandwidth(config_.bandwidthHz);
  detector_.setThresholdDb(config_.detectorThresholdDb);

  buildSlots();
  reset();
}

void PskBrowser::setEnabled(bool enabled)
{
  if (config_.enabled == enabled) return;
  config_.enabled = enabled;
  detector_.reset();
  lastDetectorSequence_ = detector_.sequence();
  retireBrowserChannels();
}

void PskBrowser::setMode(Mode mode)
{
  if (config_.mode == mode) return;
  config_.mode = mode;
  retireBrowserChannels();
  buildSlots();
  detector_.reset();
  lastDetectorSequence_ = detector_.sequence();
}

void PskBrowser::setCenterFrequency(double frequency)
{
  if (std::abs(config_.centerFrequency - frequency) <= 0.01) return;
  config_.centerFrequency = frequency;
  Channel& primary = channels_[PRIMARY_CHANNEL];
  primary.frequency = frequency;
  if (!primary.modem) primary.modem = makeModem(frequency);
  else {
    primary.modem->setFrequency(frequency);
    primary.modem->rxInit();
  }
  primary.peakMetric = 0.0;
  primary.lastOutputSample = -1;
}

void PskBrowser::setFrequencyRange(int lowHz, int highHz)
{
  if (lowHz < 0) lowHz = 0;
  if (highHz <= lowHz) highHz = lowHz + 1;
  highHz = std::min(highHz, static_cast<int>(sampleRate_ / 2.0));
  if (config_.lowFrequency == lowHz && config_.highFrequency == highHz) return;

  config_.lowFrequency = lowHz;
  config_.highFrequency = highHz;
  detector_.setPassband(lowHz, highHz);
  lastDetectorSequence_ = detector_.sequence();
  retireBrowserChannels();
  buildSlots();
}

void PskBrowser::setBaud(double baud)
{
  if (!(baud > 0.0) || std::abs(config_.baud - baud) <= 0.01) return;
  config_.baud = baud;
  config_.bandwidthHz = baud;
  detector_.setBandwidth(baud);
  reset();
}

void PskBrowser::setQpsk(bool qpsk)
{
  if (config_.qpsk == qpsk) return;
  config_.qpsk = qpsk;
  reset();
}

void PskBrowser::setReverse(bool reverse)
{
  config_.reverse = reverse;
  for (auto& channel : channels_) {
    if (channel.modem) channel.modem->setReverse(reverse);
    for (auto& probe : channel.probes) {
      if (probe.modem) probe.modem->setReverse(reverse);
    }
  }
}

void PskBrowser::setSquelch(double squelch)
{
  config_.squelch = squelch;
  for (auto& channel : channels_) {
    if (channel.modem) channel.modem->setSquelch(squelch);
    for (auto& probe : channel.probes) {
      if (probe.modem) probe.modem->setSquelch(squelch);
    }
  }
}

void PskBrowser::reset()
{
  for (int i = 0; i <= MAX_CHANNELS; ++i) channels_[i].id = i;
  detector_.reset();
  lastDetectorSequence_ = detector_.sequence();
  samplesProcessed_ = 0;
  pendingResults_.clear();

  for (auto& channel : channels_) {
    resetChannel(channel);
  }

  Channel& primary = channels_[PRIMARY_CHANNEL];
  primary.primary = true;
  primary.active = true;
  primary.frequency = config_.centerFrequency;
  primary.idleResetDone = false;
  primary.modem = makeModem(primary.frequency);
}

std::vector<PskBrowser::Result> PskBrowser::takeResults()
{
  std::vector<Result> result;
  result.swap(pendingResults_);
  return result;
}

void PskBrowser::process(int16_t const* samples, int count)
{
  if (!samples || count <= 0) return;

  std::int64_t const now = samplesProcessed_ + count;

  feedChannel(channels_[PRIMARY_CHANNEL], samples, count, now);
  for (int i = 1; i <= MAX_CHANNELS; ++i) {
    if (channels_[i].active) {
      feedChannel(channels_[i], samples, count, now);
    }
  }

  if (config_.enabled) {
    detector_.process(samples, count);
    if (detector_.sequence() != lastDetectorSequence_) {
      lastDetectorSequence_ = detector_.sequence();

      if (config_.mode == Mode::Dynamic) {
        discoverDynamic(now);
      } else {
        discoverFixed(now);
      }
    }
  }

  std::int64_t const timeoutSamples =
    static_cast<std::int64_t>(std::lround(config_.timeoutSeconds * sampleRate_));
  {
    Channel& primary = channels_[PRIMARY_CHANNEL];
    std::int64_t const primaryTimeout = std::max<std::int64_t>(
      static_cast<std::int64_t>(0.75 * sampleRate_),
      timeoutSamples - static_cast<std::int64_t>(0.5 * sampleRate_));
    if (!primary.idleResetDone && primary.lastOutputSample >= 0 &&
        now - primary.lastOutputSample > primaryTimeout) {
      resetPrimary(now);
    }
  }
  for (int i = 1; i <= MAX_CHANNELS; ++i) {
    Channel& channel = channels_[i];
    if (!channel.active || channel.probing) continue;
    std::int64_t const last = channel.lastOutputSample >= 0
      ? channel.lastOutputSample : channel.probeStartSample;
    if (now - last > timeoutSamples) {
      retireChannel(channel);
    }
  }

  samplesProcessed_ = now;
}

void PskBrowser::buildSlots()
{
  for (int i = 0; i <= MAX_CHANNELS; ++i) channels_[i].id = i;
  for (auto& channel : channels_) {
    channel.slotIndex = -1;
    channel.slotLow = 0.0;
    channel.slotHigh = 0.0;
  }

  int const range = config_.highFrequency - config_.lowFrequency;
  if (range <= 0) {
    slotCount_ = 0;
    return;
  }

  int count = config_.channels;
  if (config_.slotWidthHz > 0.0) {
    int const byWidth = static_cast<int>(
      std::ceil(range / config_.slotWidthHz));
    count = std::min(count, std::max(1, byWidth));
  }
  count = clampInt(count, 1, MAX_CHANNELS);
  slotCount_ = count;

  double const width = static_cast<double>(range) / count;
  for (int i = 0; i < count; ++i) {
    Channel& channel = channels_[i + 1];
    channel.slotIndex = i;
    channel.slotLow = config_.lowFrequency + i * width;
    channel.slotHigh = channel.slotLow + width;
  }
}

void PskBrowser::resetChannel(Channel& channel)
{
  channel.active = false;
  channel.probing = false;
  channel.idleResetDone = false;
  channel.frequency = 0.0;
  channel.candidateFrequency = 0.0;
  channel.peakMetric = 0.0;
  channel.probeStartSample = 0;
  channel.lastOutputSample = -1;
  channel.lastDetectSample = -1;
  channel.modem.reset();
  channel.probes.clear();
}

void PskBrowser::resetPrimary(std::int64_t now)
{
  Channel& primary = channels_[PRIMARY_CHANNEL];
  if (!primary.modem) primary.modem = makeModem(config_.centerFrequency);
  else {
    primary.modem->setFrequency(config_.centerFrequency);
    primary.modem->rxInit();
  }
  primary.frequency = config_.centerFrequency;
  primary.peakMetric = 0.0;
  primary.lastOutputSample = now;
  primary.idleResetDone = true;
}

void PskBrowser::retireChannel(Channel& channel)
{
  channel.active = false;
  channel.probing = false;
  channel.modem.reset();
  channel.probes.clear();
  channel.lastOutputSample = -1;
  channel.lastDetectSample = -1;
  channel.peakMetric = 0.0;
}

void PskBrowser::retireBrowserChannels()
{
  for (int i = 1; i <= MAX_CHANNELS; ++i) {
    retireChannel(channels_[i]);
  }
}

void PskBrowser::initModem(PskModem& modem, double frequency) const
{
  modem.setBaud(config_.baud);
  modem.setQpsk(config_.qpsk);
  modem.setFrequency(frequency);
  modem.setReverse(config_.reverse);
  modem.setSquelch(config_.squelch);
  modem.setAfc(true);
  modem.rxInit();
}

std::unique_ptr<PskModem> PskBrowser::makeModem(double frequency) const
{
  std::unique_ptr<PskModem> modem(new PskModem(sampleRate_, PskModem::SAMPLE_RATE_TX));
  initModem(*modem, frequency);
  return modem;
}

void PskBrowser::startProbes(Channel& channel, double frequency)
{
  channel.active = true;
  channel.probing = true;
  channel.frequency = frequency;
  channel.candidateFrequency = frequency;
  channel.peakMetric = 0.0;
  channel.probeStartSample = samplesProcessed_;
  channel.lastOutputSample = -1;
  channel.probes.clear();

  for (double offset : probeOffsets (config_.mode == Mode::Dynamic)) {
    double const probeFrequency = frequency + offset;
    if (probeFrequency < 20.0 ||
        probeFrequency > sampleRate_ / 2.0 - 20.0) {
      continue;
    }
    Probe probe;
    probe.frequency = probeFrequency;
    probe.modem = makeModem(probeFrequency);
    channel.probes.push_back(std::move(probe));
  }

  if (channel.probes.empty()) {
    Probe probe;
    probe.frequency = frequency;
    probe.modem = makeModem(frequency);
    channel.probes.push_back(std::move(probe));
  }
}

void PskBrowser::startCarrier(Channel& channel, double frequency)
{
  retireChannel(channel);
  startProbes(channel, frequency);
}

void PskBrowser::feedChannel(Channel& channel, int16_t const* samples, int count,
                             std::int64_t now)
{
  if (!channel.active) return;

  if (channel.probing) {
    for (auto& probe : channel.probes) {
      probe.modem->rxProcess(samples, count);
      probe.peakMetric = std::max(probe.peakMetric, probe.modem->metric());
      if (probe.modem->hasOutput()) {
        probe.text += probe.modem->takeOutput();
      }
    }

    std::int64_t const probeSamples = static_cast<std::int64_t>(
      std::lround(config_.probeSeconds * sampleRate_));
    if (now - channel.probeStartSample >= probeSamples) {
      selectProbe(channel, now);
    }
    return;
  }

  if (!channel.modem) return;
  channel.modem->rxProcess(samples, count);
  channel.peakMetric = std::max(channel.peakMetric, channel.modem->metric());
  emitOutput(channel, now);
}

void PskBrowser::selectProbe(Channel& channel, std::int64_t now)
{
  if (channel.probes.empty()) {
    retireChannel(channel);
    return;
  }

  std::size_t best = 0;
  int bestQuality = -1;
  for (std::size_t i = 0; i < channel.probes.size(); ++i) {
    Probe const& probe = channel.probes[i];
    int const quality = textQuality(probe.text);
    double const bestDistance =
      std::abs(channel.probes[best].frequency - channel.candidateFrequency);
    double const distance =
      std::abs(probe.frequency - channel.candidateFrequency);
    if (quality > bestQuality ||
        (quality == bestQuality &&
         (probe.peakMetric > channel.probes[best].peakMetric ||
          (probe.peakMetric == channel.probes[best].peakMetric &&
           distance < bestDistance)))) {
      best = i;
      bestQuality = quality;
    }
  }

  Probe& selected = channel.probes[best];
  std::string text = std::move(selected.text);
  channel.modem = std::move(selected.modem);
  channel.frequency = selected.frequency;
  channel.peakMetric = selected.peakMetric;
  channel.probing = false;
  channel.probes.clear();
  channel.lastOutputSample = now;

  if (!text.empty()) {
    addResult(channel, std::move(text), now);
  }
}

void PskBrowser::emitOutput(Channel& channel, std::int64_t now)
{
  if (!channel.modem || !channel.modem->hasOutput()) return;
  std::string text = channel.modem->takeOutput();
  if (text.empty()) return;
  channel.lastOutputSample = now;
  channel.idleResetDone = false;
  addResult(channel, std::move(text), now);
}

void PskBrowser::discoverFixed(std::int64_t now)
{
  for (int i = 1; i <= slotCount_; ++i) {
    Channel& channel = channels_[i];
    if (channel.active) continue;

    CarrierCandidate candidate;
    if (!detector_.peakInRange(channel.slotLow, channel.slotHigh, candidate)) {
      continue;
    }
    if (isNearPrimary(candidate.frequency)) continue;

    startCarrier(channel, candidate.frequency);
    channel.lastDetectSample = now;
  }
}

void PskBrowser::discoverDynamic(std::int64_t now)
{
  auto candidates = detector_.detectAll(config_.minSeparationHz);
  std::sort(candidates.begin(), candidates.end(),
            [] (CarrierCandidate const& lhs, CarrierCandidate const& rhs) {
              return lhs.frequency < rhs.frequency;
            });
  double const matchTolerance =
    std::max(8.0, config_.minSeparationHz * 0.7);

  for (auto const& candidate : candidates) {
    if (isNearPrimary(candidate)) continue;

    Channel* match = nullptr;
    for (int i = 1; i <= config_.maxCarriers; ++i) {
      Channel& channel = channels_[i];
      if (!channel.active) continue;
      if (std::abs(channel.candidateFrequency - candidate.frequency) <=
          matchTolerance) {
        match = &channel;
        break;
      }
    }

    if (match) {
      match->lastDetectSample = now;
      continue;
    }

    for (int i = 1; i <= config_.maxCarriers; ++i) {
      Channel& channel = channels_[i];
      if (channel.active) continue;
      startCarrier(channel, candidate.frequency);
      channel.lastDetectSample = now;
      break;
    }
  }
}

bool PskBrowser::isNearPrimary(double frequency) const
{
  return std::abs(frequency - config_.centerFrequency) < 2.0;
}

bool PskBrowser::isNearPrimary(CarrierCandidate const& candidate) const
{
  double const distance = std::abs(candidate.frequency - config_.centerFrequency);
  if (distance < 2.0) return true;
  if (candidate.peakBased) {
    // Sidebands of the selected-tone signal are local peaks, not independent
    // stations. Suppress them around the primary carrier.
    return distance < std::max(2.0, 0.7 * config_.bandwidthHz);
  }
  return false;
}

void PskBrowser::addResult(Channel const& channel, std::string text,
                           std::int64_t now)
{
  (void) now;
  Result result;
  result.channelId = channel.id;
  result.frequency = channel.frequency;
  result.text = std::move(text);
  result.snr = channel.peakMetric;
  pendingResults_.push_back(std::move(result));
}

} // namespace Psk
