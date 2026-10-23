#include "RttyDecoder.hpp"
#include <QDateTime>
#include <cmath>

namespace Rtty {

Decoder::Decoder()
  : channels_(RttyMultiDemod::MAX_CHANNELS)
{
}

Decoder::~Decoder() = default;

void Decoder::begin(qint64 sessionId, qint64 gridOrigin, qint64 firstSearch, int samplesPerSymbol)
{
  (void)gridOrigin;
  (void)samplesPerSymbol;
  sessionId_ = sessionId;
  gridOrigin_ = gridOrigin;
  nextRequiredSample_ = firstSearch;

  qsoModem_.rxInit();
  multiDemod_.reset();

  qsoCenterFrequency_ = 0.0;
  qsoMessageId_ = 0;
  qsoText_.clear();
  qsoActive_ = false;
  qsoIdleFrames_ = 0;

  for (auto& ch : channels_) ch = ChannelState {};
  pendingUpdates_.clear();
}

int Decoder::process(qint16 const * samples, int count, qint64 firstSample,
                     qint64 stopSample, int maxSteps, int lowFrequency,
                     int highFrequency, float centerFrequency, float tolerance)
{
  (void)stopSample;
  (void)maxSteps;
  (void)tolerance;
  if (!samples || count <= 0) return 0;

  (void)centerFrequency;
  // N6NU: no separate QSO modem at the Rx frequency. Its squelch compared the
  // tones with the power of the whole band and closed in a busy band, and it put
  // every message near Rx into the QSO pane twice. WS fills the QSO pane from
  // these updates by frequency (Jtty::shouldApplyToQsoHistory), as for JTTY.

  // Multi-Demod: search the full passband (lowFrequency to highFrequency)
  multiDemod_.setBandpass(lowFrequency, highFrequency);
  multiDemod_.setSquelch(5.0);   // tone-pair detection threshold, dB over the noise per bin
  multiDemod_.rxProcess(samples, count);

  // N6NU: a message ends after idleSamples without new text, measured in samples.
  // Counting process() calls instead made it depend on the block size: with
  // WS's small blocks every gap between two characters ended the message.
  qint64 const now = firstSample + count;
  auto decodes = multiDemod_.takeDecodes();
  for (auto const& decode : decodes) {
    auto& ch = channels_[decode.channelId];
    int const generation = multiDemod_.generation(decode.channelId);
    if (ch.active && ch.generation != generation) {
      flushChannelMessage(decode.channelId, decode, true);   // the channel now follows another signal
    }
    ch.generation = generation;
    ch.lastTextSample = now;
    flushChannelMessage(decode.channelId, decode, false);
  }

  for (int i = 0; i < RttyMultiDemod::MAX_CHANNELS; ++i) {
    if (channels_[i].active && now - channels_[i].lastTextSample > idleSamples) {
      ChannelDecode dummy;
      dummy.channelId = i;
      dummy.frequency = channels_[i].frequency;
      flushChannelMessage(i, dummy, true);
    }
  }

  nextRequiredSample_ = now;
  return count; // Number of samples consumed
}

void Decoder::flushQsoMessage(bool complete)
{
  if (!qsoActive_) return;
  QString const cleanText = qsoText_.trimmed();
  if (!cleanText.isEmpty() && (!complete || cleanText.length() >= 3)) {
    Jtty::MessageUpdate update;
    update.messageId = qsoMessageId_;
    update.frequency = qsoModem_.frequency();
    update.text = cleanText;
    update.sequenceStart = qsoStartSeconds_;
    update.complete = complete;
    update.snr = static_cast<int>(qsoModem_.lastSnr());
    pendingUpdates_.push_back(update);
  }
  if (complete) {
    qsoActive_ = false;
    qsoText_.clear();
    qsoIdleFrames_ = 0;
  }
}

void Decoder::flushChannelMessage(int channelId, ChannelDecode const& decode, bool complete)
{
  if (channelId < 0 || channelId >= RttyMultiDemod::MAX_CHANNELS) return;
  auto& ch = channels_[channelId];

  if (!ch.active && !complete) {
    ch.active = true;
    ch.messageId = generateMessageId(channelId);
    ch.startSeconds = nextRequiredSample_ / 12000.0;
    ch.frequency = decode.frequency;
    ch.text.clear();
  }

  if (!complete) {
    ch.text += QString::fromStdString(decode.text);
    ch.idleFrames = 0;
    ch.snr = decode.snr;      // the completing call carries no SNR of its own
  }

  if (ch.active) {
    // Normalize newlines and whitespace: replace internal \r/\n with space and collapse spaces,
    // keeping the entire transmission on one clean line like FT8
    QString cleanText = ch.text;
    cleanText.replace(QLatin1Char{'\r'}, QLatin1Char{' '});
    cleanText.replace(QLatin1Char{'\n'}, QLatin1Char{' '});
    cleanText = cleanText.simplified();
    if (cleanText.length() >= 3) {   // N6NU: one or two characters are mostly noise, shown or not
      Jtty::MessageUpdate update;
      update.messageId = ch.messageId;
      update.frequency = static_cast<float>(ch.frequency);
      update.text = cleanText;
      update.sequenceStart = ch.startSeconds;
      update.complete = complete;
      update.snr = static_cast<int>(std::lround(ch.snr));
      pendingUpdates_.push_back(update);
    }

    if (complete) {
      ch.active = false;
      ch.text.clear();
      ch.idleFrames = 0;
    }
  }
}

qint64 Decoder::generateMessageId(int channelId)
{
  // Just use timestamp and channel for uniqueness
  qint64 ms = QDateTime::currentMSecsSinceEpoch();
  return (ms << 8) | (channelId & 0xFF);
}

QVector<Jtty::MessageUpdate> Decoder::takeUpdates()
{
  QVector<Jtty::MessageUpdate> ret = pendingUpdates_;
  pendingUpdates_.clear();
  return ret;
}

} // namespace Rtty
