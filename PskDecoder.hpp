#ifndef PSK_DECODER_HPP
#define PSK_DECODER_HPP

#include "lib/psk/psk_multi_demod.hpp"
#include "widgets/JttyMessages.hpp"
#include <QVector>
#include <QString>
#include <QDateTime>

namespace Psk {

class Decoder
{
public:
  static constexpr qint64 idleSamples = 18000; // 1.5 s at 12 kHz

  Decoder();
  ~Decoder();

  Decoder(Decoder const&) = delete;
  Decoder& operator=(Decoder const&) = delete;

  bool valid() const { return true; }

  void begin(qint64 sessionId, qint64 gridOrigin, qint64 firstSearch, int samplesPerSymbol = 384);

  int process(qint16 const * samples, int count, qint64 firstSample,
              qint64 stopSample, int maxSteps, int lowFrequency,
              int highFrequency, float centerFrequency, float tolerance);

  qint64 nextRequiredSample() const { return nextRequiredSample_; }
  qint64 nextSearchSample() const { return nextRequiredSample_; }

  QVector<Jtty::MessageUpdate> takeUpdates();

private:
  qint64 sessionId_ {0};
  qint64 gridOrigin_ {0};
  qint64 nextRequiredSample_ {0};

  PskMultiDemod multiDemod_;

  // State tracking for multi channels
  struct ChannelState {
    qint64 messageId {0};
    QString text;
    double startSeconds {0.0};
    double frequency {0.0};
    bool active {false};
    int idleFrames {0};
    qint64 lastTextSample {0};
    double snr {0.0};
  };
  std::vector<ChannelState> channels_;

  QVector<Jtty::MessageUpdate> pendingUpdates_;

  qint64 generateMessageId(int channelId);
  void flushChannelMessage(int channelId, const PskMultiDemod::DecodeResult& decode, bool complete);
};

} // namespace Psk

#endif // PSK_DECODER_HPP
