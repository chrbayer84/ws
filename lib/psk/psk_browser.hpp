#ifndef PSK_BROWSER_HPP
#define PSK_BROWSER_HPP

#include "psk_carrier_detector.hpp"
#include "psk_modem.hpp"

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

namespace Psk {

// Sparse PSK passband decoder.
//
// FixedSlots is the fldigi-style first stage: search 100 Hz-class regions and
// create a demodulator only after a real carrier is detected. Dynamic is the
// phase-2 mode: detect all carriers, associate them across FFT frames and keep
// a bounded list of active demodulators. Neither mode allocates a dense grid.
class PskBrowser
{
public:
  static constexpr int MAX_CHANNELS = 64;
  static constexpr int PRIMARY_CHANNEL = 0;

  enum class Mode
  {
    FixedSlots,
    Dynamic
  };

  struct Config
  {
    bool enabled {true};
    Mode mode {Mode::FixedSlots};
    int channels {30};
    int maxCarriers {32};
    int lowFrequency {200};
    int highFrequency {2800};
    double centerFrequency {1500.0};
    double slotWidthHz {0.0};       // 0 = divide the passband equally
    double baud {31.25};
    double bandwidthHz {31.25};
    bool qpsk {false};
    bool reverse {false};
    double squelch {5.0};
    double minSeparationHz {25.0};
    double timeoutSeconds {2.0};
    double probeSeconds {3.0};
    double detectorThresholdDb {6.0};
  };

  struct Result
  {
    int channelId {0};
    double frequency {0.0};
    std::string text;
    double snr {0.0};
  };

  explicit PskBrowser(double sampleRate = PskModem::SAMPLE_RATE_RX);
  ~PskBrowser();

  PskBrowser(PskBrowser const&) = delete;
  PskBrowser& operator=(PskBrowser const&) = delete;

  void configure(Config const& config);
  Config const& config() const { return config_; }

  void setEnabled(bool enabled);
  void setMode(Mode mode);
  void setCenterFrequency(double frequency);
  void setFrequencyRange(int lowHz, int highHz);
  void setBaud(double baud);
  void setQpsk(bool qpsk);
  void setReverse(bool reverse);
  void setSquelch(double squelch);

  void reset();
  void process(int16_t const* samples, int count);
  std::vector<Result> takeResults();

private:
  struct Probe
  {
    double frequency {0.0};
    std::unique_ptr<PskModem> modem;
    std::string text;
    double peakMetric {0.0};
  };

  struct Channel
  {
    int id {-1};
    bool primary {false};
    bool active {false};
    bool probing {false};
    bool idleResetDone {false};
    int slotIndex {-1};
    double slotLow {0.0};
    double slotHigh {0.0};
    double frequency {0.0};
    double candidateFrequency {0.0};
    double peakMetric {0.0};
    std::int64_t probeStartSample {0};
    std::int64_t lastOutputSample {-1};
    std::int64_t lastDetectSample {-1};
    std::unique_ptr<PskModem> modem;
    std::vector<Probe> probes;
  };

  double sampleRate_;
  Config config_;
  CarrierDetector detector_;
  std::vector<Channel> channels_;
  std::vector<Result> pendingResults_;
  int slotCount_ {0};
  std::uint64_t lastDetectorSequence_ {0};
  std::int64_t samplesProcessed_ {0};

  void buildSlots();
  void resetChannel(Channel& channel);
  void resetPrimary(std::int64_t now);
  void retireChannel(Channel& channel);
  void retireBrowserChannels();
  void initModem(PskModem& modem, double frequency) const;
  std::unique_ptr<PskModem> makeModem(double frequency) const;
  void startProbes(Channel& channel, double frequency);
  void startCarrier(Channel& channel, double frequency);
  void feedChannel(Channel& channel, int16_t const* samples, int count,
                   std::int64_t now);
  void selectProbe(Channel& channel, std::int64_t now);
  void emitOutput(Channel& channel, std::int64_t now);
  void discoverFixed(std::int64_t now);
  void discoverDynamic(std::int64_t now);
  bool isNearPrimary(double frequency) const;
  bool isNearPrimary(CarrierCandidate const& candidate) const;
  void addResult(Channel const& channel, std::string text, std::int64_t now);
};

} // namespace Psk

#endif // PSK_BROWSER_HPP
