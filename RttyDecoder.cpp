#include "RttyDecoder.hpp"
#include <QDateTime>

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
  (void)highFrequency;
  (void)tolerance;
  if (!samples || count <= 0) return 0;

  qsoModem_.setFrequency(centerFrequency);
  qsoModem_.setSquelch(1.5); // Only decode valid looking signals (ratio 1.5)
  qsoModem_.rxProcess(samples, count);

  multiDemod_.setBandpass(lowFrequency, highFrequency);
  multiDemod_.setSquelch(1.5); // Require some SNR to start displaying on LH pane
  multiDemod_.rxProcess(samples, count);

  double currentSeconds = static_cast<double>(firstSample) / 12000.0;

  // Process QSO Modem (RH Pane)
  if (qsoModem_.hasDecodedText()) {
    std::string newText = qsoModem_.takeDecodedText();
    if (!newText.empty()) {
      if (!qsoActive_) {
        qsoActive_ = true;
        qsoMessageId_ = generateMessageId(-1);
        qsoStartSeconds_ = currentSeconds;
        qsoText_.clear();
      }
      qsoText_ += QString::fromStdString(newText);
      qsoIdleFrames_ = 0;
      
      Jtty::ReceiveUpdate update;
      update.messageId = qsoMessageId_;
      update.frequency = centerFrequency;
      update.text = qsoText_;
      update.startSeconds = qsoStartSeconds_;
      update.latestSeconds = currentSeconds;
      update.terminal = Jtty::ReceiveTerminal::Growing;
      update.snr = static_cast<int>(qsoModem_.lastSnr());
      pendingUpdates_.push_back(update);
    }
  } else if (qsoActive_) {
    qsoIdleFrames_++;
    // If no text for ~2 seconds (at 12000 Hz, count is typically small blocks, say 1024 samples)
    if (qsoIdleFrames_ > 20) {
      flushQsoMessage(true);
    }
  }

  // Process MultiDemod (LH Pane)
  auto decodes = multiDemod_.takeDecodes();
  for (auto const& decode : decodes) {
    flushChannelMessage(decode.channelId, decode, false);
  }

  // Check for idle multi channels
  for (int i = 0; i < RttyMultiDemod::MAX_CHANNELS; ++i) {
    bool found = false;
    for (auto const& decode : decodes) {
      if (decode.channelId == i) {
        found = true;
        break;
      }
    }
    if (!found && channels_[i].active) {
      channels_[i].idleFrames++;
      if (channels_[i].idleFrames > 20) {
        // Complete it
        ChannelDecode dummy;
        dummy.channelId = i;
        dummy.frequency = 0; // Not used for completion flush
        dummy.snr = 0;
        flushChannelMessage(i, dummy, true);
      }
    }
  }

  nextRequiredSample_ = firstSample + count;
  return count; // Number of samples consumed
}

void Decoder::flushQsoMessage(bool complete)
{
  if (!qsoActive_) return;
  Jtty::ReceiveUpdate update;
  update.messageId = qsoMessageId_;
  update.frequency = qsoModem_.frequency();
  update.text = qsoText_;
  update.startSeconds = qsoStartSeconds_;
  update.latestSeconds = qsoStartSeconds_ + 2.0; // Approximation
  update.terminal = complete ? Jtty::ReceiveTerminal::Complete : Jtty::ReceiveTerminal::Growing;
  update.snr = static_cast<int>(qsoModem_.lastSnr());
  pendingUpdates_.push_back(update);
  if (complete) {
    qsoActive_ = false;
    qsoText_.clear();
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
    ch.text.clear();
  }

  if (!complete) {
    ch.text += QString::fromStdString(decode.text);
    ch.idleFrames = 0;
  }

  if (ch.active) {
    Jtty::ReceiveUpdate update;
    update.messageId = ch.messageId;
    update.frequency = complete ? 0.0f : static_cast<float>(decode.frequency); // Just use decode freq when active
    update.text = ch.text;
    update.startSeconds = ch.startSeconds;
    update.latestSeconds = nextRequiredSample_ / 12000.0;
    update.terminal = complete ? Jtty::ReceiveTerminal::Complete : Jtty::ReceiveTerminal::Growing;
    update.snr = static_cast<int>(decode.snr);
    pendingUpdates_.push_back(update);
    
    if (complete) {
      ch.active = false;
      ch.text.clear();
    }
  }
}

qint64 Decoder::generateMessageId(int channelId)
{
  // Just use timestamp and channel for uniqueness
  qint64 ms = QDateTime::currentMSecsSinceEpoch();
  return (ms << 8) | (channelId & 0xFF);
}

QVector<Jtty::ReceiveUpdate> Decoder::takeUpdates()
{
  QVector<Jtty::ReceiveUpdate> ret = pendingUpdates_;
  pendingUpdates_.clear();
  return ret;
}

} // namespace Rtty
