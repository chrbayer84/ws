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
  : channels_(PskBrowser::MAX_CHANNELS + 1)
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

  browser_.reset();
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

void Decoder::configureBrowser(bool enabled, int channels, bool dynamic)
{
  auto config = browser_.config();
  config.enabled = enabled;
  config.channels = channels;
  config.maxCarriers = channels;
  config.mode = dynamic ? PskBrowser::Mode::Dynamic : PskBrowser::Mode::FixedSlots;
  browser_.configure(config);
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

  browser_.setBaud(baud);
  browser_.setQpsk(qpsk);
}

void Decoder::setReverse(bool rev)
{
  browser_.setReverse(rev);
}

void Decoder::setSquelch(double s)
{
  browser_.setSquelch(s);
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

  // Channel 0 always follows the selected RX tone. Browser results use
  // channels 1..N and only exist while a real carrier is being decoded.
  browser_.setCenterFrequency(centerFrequency);
  browser_.setFrequencyRange(lowFrequency, highFrequency);
  browser_.process(samples, count);

  auto decodes = browser_.takeResults();
  for (auto const& decode : decodes) {
    int const channelId = decode.channelId;
    if (channelId < 0 || channelId >= static_cast<int>(channels_.size ())) {
      continue;
    }
    auto& ch = channels_[channelId];
    ch.lastTextSample = now;
    flushChannelMessage(channelId, decode.frequency, decode.text, decode.snr, false);
  }

  for (int i = 0; i < static_cast<int>(channels_.size ()); ++i) {
    if (channels_[i].active && now - channels_[i].lastTextSample > idleSamples) {
      auto& ch = channels_[i];
      flushChannelMessage(i, ch.frequency, std::string {}, 0.0, true);
      if (i != PskBrowser::PRIMARY_CHANNEL) browser_.resetBrowserChannel(i);
    }
  }

  flushCompleted (now);

  nextRequiredSample_ = firstSample + count;
  return count; // Number of samples consumed
}

void Decoder::flushChannelMessage(int channelId, double frequency,
                                   std::string const& text, double snr,
                                   bool complete)
{
  if (channelId < 0 || channelId >= static_cast<int>(channels_.size ())) return;
  auto& ch = channels_[channelId];

  if (!complete && ch.active && ch.lastTextSample > 0
      && chunkStartSample_ - ch.lastTextSample > idleSamples) {
    flushChannelMessage(channelId, ch.frequency, std::string {}, ch.snr, true);
  }

  if (!ch.active && !complete) {
    ch.active = true;
    ch.messageId = generateMessageId(channelId);
    ch.startSeconds = chunkStartSample_ / 12000.0;
    ch.frequency = frequency;
    ch.text.clear();
  }
  if (!complete) {
    ch.text += QString::fromStdString(text);
    ch.idleFrames = 0;
    ch.snr = snr;
    ch.frequency = frequency;
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
      if (std::abs (completedBuffer_[j].frequency - completedBuffer_[i].frequency) >= 15.0) continue;
      // Only merge duplicate decodes produced around the same time by
      // overlapping channels. Two separate messages on the same frequency
      // (for example a long message followed quickly by a CQ) must both be
      // emitted.
      if (std::abs (completedBuffer_[j].sample - completedBuffer_[i].sample)
          > idleSamples / 2) continue;
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
