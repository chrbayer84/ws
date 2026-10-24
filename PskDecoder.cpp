#include "PskDecoder.hpp"
#include <QDateTime>
#include <cmath>

namespace Psk {

Decoder::Decoder()
  : channels_(PskMultiDemod::MAX_CHANNELS)
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

  multiDemod_.reset();

  for (auto& ch : channels_) ch = ChannelState {};
  pendingUpdates_.clear();
}

void Decoder::setSubmode(const QString& submode)
{
  double baud = 31.25;
  bool qpsk = false;
  if (submode == "PSK63") { baud = 62.5; qpsk = false; }
  else if (submode == "PSK125") { baud = 125.0; qpsk = false; }
  else if (submode == "PSK250") { baud = 250.0; qpsk = false; }
  else if (submode == "QPSK31") { baud = 31.25; qpsk = true; }
  else if (submode == "QPSK63") { baud = 62.5; qpsk = true; }
  else if (submode == "QPSK125") { baud = 125.0; qpsk = true; }
  else if (submode == "QPSK250") { baud = 250.0; qpsk = true; }
  else { baud = 31.25; qpsk = false; }

  multiDemod_.setBaud(baud);
  multiDemod_.setQpsk(qpsk);
}

void Decoder::setReverse(bool rev)
{
  multiDemod_.setReverse(rev);
}

void Decoder::setSquelch(double s)
{
  multiDemod_.setSquelch(s);
}

int Decoder::process(qint16 const * samples, int count, qint64 firstSample,
                     qint64 stopSample, int maxSteps, int lowFrequency,
                     int highFrequency, float centerFrequency, float tolerance)
{
  (void)stopSample;
  (void)maxSteps;
  (void)tolerance;
  if (!samples || count <= 0) return 0;

  // Multi-Demod: search the full passband, with Channel 0 locked onto centerFrequency
  multiDemod_.setCenterFrequency(centerFrequency);
  multiDemod_.setFrequencyRange(lowFrequency, highFrequency);
  multiDemod_.rxProcess(samples, count);

  qint64 const now = firstSample + count;
  auto decodes = multiDemod_.takeDecodes();
  for (auto const& decode : decodes) {
    auto& ch = channels_[decode.channelId];
    ch.lastTextSample = now;
    flushChannelMessage(decode.channelId, decode, false);
  }

  for (int i = 0; i < PskMultiDemod::MAX_CHANNELS; ++i) {
    if (channels_[i].active && now - channels_[i].lastTextSample > idleSamples) {
      PskMultiDemod::DecodeResult dummy;
      dummy.channelId = i;
      dummy.frequency = channels_[i].frequency;
      dummy.snr = 0;
      dummy.complete = true;
      flushChannelMessage(i, dummy, true);
    }
  }

  nextRequiredSample_ = now;
  return count; // Number of samples consumed
}

void Decoder::flushChannelMessage(int channelId, const PskMultiDemod::DecodeResult& decode, bool complete)
{
  if (channelId < 0 || channelId >= PskMultiDemod::MAX_CHANNELS) return;
  auto& ch = channels_[channelId];

  if (!ch.active && !complete) {
    // Suppress duplicate tracking if another channel is already actively decoding this frequency
    for (int j = 0; j < PskMultiDemod::MAX_CHANNELS; ++j) {
      if (j != channelId && channels_[j].active && std::abs(channels_[j].frequency - decode.frequency) < 15.0) {
        return;
      }
    }
    ch.active = true;
    ch.messageId = generateMessageId(channelId);
    ch.startSeconds = nextRequiredSample_ / 12000.0;
    ch.frequency = decode.frequency;
    ch.text.clear();
  }

  if (!complete) {
    ch.text += QString::fromStdString(decode.text);
    ch.idleFrames = 0;
    ch.snr = decode.snr;
  }

  if (ch.active) {
    // Normalize newlines and whitespace: keep each transmission on one clean line like FT8
    QString cleanText = ch.text;
    cleanText.replace(QLatin1Char{'\r'}, QLatin1Char{' '});
    cleanText.replace(QLatin1Char{'\n'}, QLatin1Char{' '});
    cleanText = cleanText.simplified();
    if (cleanText.length() >= 3) {
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
  qint64 ms = QDateTime::currentMSecsSinceEpoch();
  return (ms << 8) | (channelId & 0xFF);
}

QVector<Jtty::MessageUpdate> Decoder::takeUpdates()
{
  QVector<Jtty::MessageUpdate> ret = pendingUpdates_;
  pendingUpdates_.clear();
  return ret;
}

} // namespace Psk
