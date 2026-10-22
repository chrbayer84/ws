#include "PskDecoder.hpp"
#include <QDateTime>

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

  qsoModem_.rxInit();
  multiDemod_.reset();

  qsoCenterFrequency_ = 0.0;
  qsoMessageId_ = 0;
  qsoText_.clear();
  qsoActive_ = false;
  qsoIdleFrames_ = 0;

  for (auto& ch : channels_) {
    ch.messageId = 0;
    ch.text.clear();
    ch.active = false;
    ch.idleFrames = 0;
  }
}

int Decoder::process(qint16 const * samples, int count, qint64 firstSample,
                     qint64 stopSample, int maxSteps, int lowFrequency,
                     int highFrequency, float centerFrequency, float tolerance)
{
  (void)stopSample;
  (void)maxSteps;
  (void)tolerance;
  if (!samples || count <= 0) return 0;

  // QSO Modem (RH Pane): Only decode at the RX frequency +/- tolerance
  if (std::abs(centerFrequency - qsoCenterFrequency_) > 1.0) {
    qsoCenterFrequency_ = centerFrequency;
    qsoModem_.setFrequency(centerFrequency);
  }
  qsoModem_.setSquelch(5.0);
  qsoModem_.rxProcess(samples, count);

  // Multi-Demod (LH Pane): Scan the FULL passband (lowFrequency to highFrequency)
  multiDemod_.setFrequencyRange(lowFrequency, highFrequency);
  multiDemod_.setSquelch(5.0);
  multiDemod_.rxProcess(samples, count);

  double currentSeconds = static_cast<double>(firstSample) / 12000.0;

  // Process QSO Modem (RH Pane)
  if (qsoModem_.hasOutput()) {
    std::string newText = qsoModem_.takeOutput();
    if (!newText.empty()) {
      if (!qsoActive_) {
        qsoActive_ = true;
        qsoMessageId_ = generateMessageId(-1);
        qsoStartSeconds_ = currentSeconds;
        qsoText_.clear();
      }
      qsoText_ += QString::fromStdString(newText);
      qsoIdleFrames_ = 0;

      Jtty::MessageUpdate update;
      update.messageId = qsoMessageId_;
      update.frequency = centerFrequency;
      update.text = qsoText_;
      update.sequenceStart = qsoStartSeconds_;
      update.complete = false;
      update.snr = static_cast<int>(qsoModem_.getSNR());
      pendingUpdates_.push_back(update);
    }
  } else if (qsoActive_) {
    qsoIdleFrames_++;
    // If no text for ~250ms (squelch closed), flush completed message
    if (qsoIdleFrames_ > 6) {
      flushQsoMessage(true);
    }
  }

  // Process MultiDemod (LH Pane)
  auto decodes = multiDemod_.takeDecodes();
  for (size_t i = 0; i < decodes.size(); ++i) {
    flushChannelMessage(static_cast<int>(i), decodes[i], false);
  }

  // Check for idle multi channels
  for (int i = 0; i < PskMultiDemod::MAX_CHANNELS; ++i) {
    if (channels_[i].active) {
      channels_[i].idleFrames++;
      if (channels_[i].idleFrames > 6) {
        // Complete it
        PskMultiDemod::DecodeResult dummy;
        dummy.channelId = i;
        dummy.frequency = channels_[i].frequency;
        dummy.snr = 0;
        dummy.complete = true;
        flushChannelMessage(i, dummy, true);
      }
    }
  }

  nextRequiredSample_ = firstSample + count;
  return count;
}

void Decoder::flushQsoMessage(bool complete)
{
  if (!qsoActive_) return;
  QString const cleanText = qsoText_.trimmed();
  if (!cleanText.isEmpty() && (!complete || cleanText.length() >= 3)) {
    Jtty::MessageUpdate update;
    update.messageId = qsoMessageId_;
    update.frequency = static_cast<float>(qsoModem_.getFrequency());
    update.text = cleanText;
    update.sequenceStart = qsoStartSeconds_;
    update.complete = complete;
    update.snr = static_cast<int>(qsoModem_.getSNR());
    pendingUpdates_.push_back(update);
  }
  if (complete) {
    qsoActive_ = false;
    qsoText_.clear();
    qsoIdleFrames_ = 0;
  }
}

void Decoder::flushChannelMessage(int channelId, const PskMultiDemod::DecodeResult& decode, bool complete)
{
  if (channelId < 0 || channelId >= PskMultiDemod::MAX_CHANNELS) return;
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
  }

  if (ch.active) {
    QString const cleanText = ch.text.trimmed();
    if (!cleanText.isEmpty() && (!complete || cleanText.length() >= 3)) {
      Jtty::MessageUpdate update;
      update.messageId = ch.messageId;
      update.frequency = static_cast<float>(ch.frequency);
      update.text = cleanText;
      update.sequenceStart = ch.startSeconds;
      update.complete = complete;
      update.snr = static_cast<int>(decode.snr);
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