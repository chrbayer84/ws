#ifndef PSK_DECODER_HPP
#define PSK_DECODER_HPP

#include "lib/psk/psk_browser.hpp"
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

  // Continue the existing demodulator state after the audio buffer's sample
  // index wraps at a decode-period boundary.
  void rewind(qint64 firstSearch = 0);

  void configureBrowser(bool enabled, int channels = 30, bool dynamic = false);
  void setSubmode(const QString& submode);
  void setReverse(bool rev);
  void setSquelch(double s);

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
  qint64 sampleBase_ {0};
  qint64 chunkStartSample_ {0};

  PskBrowser browser_;

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
  void flushChannelMessage(int channelId, double frequency,
                           std::string const& text, double snr, bool complete);

  struct BufferedCompletion
  {
    qint64 messageId {0};
    double frequency {0.0};
    double sequenceStart {0.0};
    int snr {0};
    QString text;
    qint64 sample {0};
    int quality {0};
  };
  std::vector<BufferedCompletion> completedBuffer_;
  qint64 lastCompletionSample_ {-1};
  void flushCompleted (qint64 now);
};

} // namespace Psk

#endif // PSK_DECODER_HPP
