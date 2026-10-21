#ifndef RTTY_DECODER_HPP
#define RTTY_DECODER_HPP

#include "lib/rtty/rtty_modem.hpp"
#include "lib/rtty/rtty_multi_demod.hpp"
#include "JttyDecoder.hpp"
#include <QVector>
#include <QString>
#include <QDateTime>

namespace Rtty {

class Decoder
{
public:
  Decoder();
  ~Decoder();

  Decoder(Decoder const&) = delete;
  Decoder& operator=(Decoder const&) = delete;

  bool valid() const { return true; }

  void begin(qint64 sessionId, qint64 gridOrigin, qint64 firstSearch, int samplesPerSymbol = 264);

  int process(qint16 const * samples, int count, qint64 firstSample,
              qint64 stopSample, int maxSteps, int lowFrequency,
              int highFrequency, float centerFrequency, float tolerance);

  qint64 nextRequiredSample() const { return nextRequiredSample_; }
  qint64 nextSearchSample() const { return nextRequiredSample_; } // We process all available

  QVector<Jtty::ReceiveUpdate> takeUpdates();

private:
  qint64 sessionId_ {0};
  qint64 gridOrigin_ {0};
  qint64 nextRequiredSample_ {0};

  RttyModem qsoModem_;
  RttyMultiDemod multiDemod_;

  // State tracking for the QSO modem
  qint64 qsoMessageId_ {0};
  QString qsoText_;
  double qsoStartSeconds_ {0.0};
  bool qsoActive_ {false};
  int qsoIdleFrames_ {0};

  // State tracking for multi channels
  struct ChannelState {
    qint64 messageId {0};
    QString text;
    double startSeconds {0.0};
    bool active {false};
    int idleFrames {0};
  };
  std::vector<ChannelState> channels_;

  QVector<Jtty::ReceiveUpdate> pendingUpdates_;

  qint64 generateMessageId(int channelId);
  void flushQsoMessage(bool complete);
  void flushChannelMessage(int channelId, ChannelDecode const& decode, bool complete);
};

} // namespace Rtty

#endif // RTTY_DECODER_HPP
diff --git a/TxStartPolicy.hpp b/TxStartPolicy.hpp
