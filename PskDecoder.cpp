#include "PskDecoder.hpp"
#include <QDateTime>
#include <cmath>
#include <algorithm>

namespace
{
  int text_quality (QString const& text)
  {
    int score = text.size ();
    for (auto const& word : text.toUpper ().split (QLatin1Char (' '))) {
      if (word.isEmpty ()) continue;
      if (word == QLatin1String ("CQ") || word == QLatin1String ("DE")
          || word == QLatin1String ("QRZ")) {
        score += 100;
        continue;
      }
      bool has_digit = false;
      bool has_letter = false;
      for (auto const character : word) {
        has_digit = has_digit || character.isDigit ();
        has_letter = has_letter || character.isLetter ();
      }
      if (has_digit && has_letter && word.size () >= 3 && word.size () <= 11) {
        score += 50;
      }
    }
    return score;
  }
}

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
  sampleBase_ = 0;
  chunkStartSample_ = firstSearch;

  multiDemod_.reset();
  completedBuffer_.clear ();
  lastCompletionSample_ = -1;

  for (auto& ch : channels_) ch = ChannelState {};
  pendingUpdates_.clear();
}

void Decoder::rewind(qint64 firstSearch)
{
  sampleBase_ += nextRequiredSample_;
  nextRequiredSample_ = firstSearch;
  chunkStartSample_ = sampleBase_ + firstSearch;
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

  chunkStartSample_ = sampleBase_ + firstSample;
  qint64 const now = chunkStartSample_ + count;

  // Multi-Demod: Channel 0 is locked onto centerFrequency; the remaining
  // channels cover the narrow bank passed by the caller.
  multiDemod_.setCenterFrequency(centerFrequency);
  multiDemod_.setFrequencyRange(lowFrequency, highFrequency);
  multiDemod_.rxProcess(samples, count);

  auto decodes = multiDemod_.takeDecodes();
  // Prefer the strongest channel when several channels see the same signal.
  std::sort(decodes.begin(), decodes.end(),
            [] (PskMultiDemod::DecodeResult const& lhs,
                PskMultiDemod::DecodeResult const& rhs) {
              return lhs.snr > rhs.snr;
            });

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

  flushCompleted (now);

  nextRequiredSample_ = firstSample + count;
  return count; // Number of samples consumed
}

void Decoder::flushChannelMessage(int channelId, const PskMultiDemod::DecodeResult& decode, bool complete)
{
  if (channelId < 0 || channelId >= PskMultiDemod::MAX_CHANNELS) return;
  auto& ch = channels_[channelId];

  if (!ch.active && !complete) {
    ch.active = true;
    ch.messageId = generateMessageId(channelId);
    ch.startSeconds = chunkStartSample_ / 12000.0;
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
    if (complete) {
      if (cleanText.length() >= 3) {
        BufferedCompletion completion;
        completion.messageId = ch.messageId;
        completion.frequency = ch.frequency;
        completion.sequenceStart = ch.startSeconds;
        completion.snr = static_cast<int>(std::lround(ch.snr));
        completion.text = cleanText;
        completion.sample = chunkStartSample_;
        completion.quality = text_quality(cleanText);
        completedBuffer_.push_back(completion);
        lastCompletionSample_ = chunkStartSample_;
      }
      ch.active = false;
      ch.text.clear();
      ch.idleFrames = 0;
    } else if (cleanText.length() >= 3) {
      Jtty::MessageUpdate update;
      update.messageId = ch.messageId;
      update.frequency = static_cast<float>(ch.frequency);
      update.text = cleanText;
      update.sequenceStart = ch.startSeconds;
      update.complete = false;
      update.snr = static_cast<int>(std::lround(ch.snr));
      pendingUpdates_.push_back(update);
    }
  }
}

qint64 Decoder::generateMessageId(int channelId)
{
  qint64 ms = QDateTime::currentMSecsSinceEpoch();
  return (ms << 8) | (channelId & 0xFF);
}

void Decoder::flushCompleted (qint64 now)
{
  if (completedBuffer_.empty ()) return;
  if (lastCompletionSample_ >= 0 && now - lastCompletionSample_ < idleSamples) return;

  std::vector<bool> used (completedBuffer_.size (), false);
  for (std::size_t i = 0; i < completedBuffer_.size (); ++i) {
    if (used[i]) continue;
    std::size_t best = i;
    for (std::size_t j = i + 1; j < completedBuffer_.size (); ++j) {
      if (used[j]) continue;
      if (std::abs (completedBuffer_[j].frequency - completedBuffer_[i].frequency) >= 30.0) continue;
      BufferedCompletion const& candidate = completedBuffer_[j];
      BufferedCompletion const& current = completedBuffer_[best];
      if (candidate.quality > current.quality
          || (candidate.quality == current.quality && candidate.text.size () > current.text.size ())
          || (candidate.quality == current.quality && candidate.text.size () == current.text.size ()
              && candidate.snr > current.snr)) {
        best = j;
      }
      used[j] = true;
    }
    used[i] = true;

    BufferedCompletion const& chosen = completedBuffer_[best];
    Jtty::MessageUpdate update;
    update.messageId = chosen.messageId;
    update.frequency = static_cast<float>(chosen.frequency);
    update.text = chosen.text;
    update.sequenceStart = static_cast<float>(chosen.sequenceStart);
    update.complete = true;
    update.snr = chosen.snr;
    pendingUpdates_.push_back(update);
  }
  completedBuffer_.clear ();
  lastCompletionSample_ = -1;
}

QVector<Jtty::MessageUpdate> Decoder::takeUpdates()
{
  QVector<Jtty::MessageUpdate> ret = pendingUpdates_;
  pendingUpdates_.clear();
  return ret;
}

} // namespace Psk
