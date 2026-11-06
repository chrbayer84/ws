#ifndef PSK_CARRIER_DETECTOR_HPP
#define PSK_CARRIER_DETECTOR_HPP

#include <cstdint>
#include <memory>
#include <vector>

namespace Psk {

struct CarrierCandidate
{
  double frequency {0.0};
  double power {0.0};
  double prominence {0.0};
};

// FFT-based carrier detector. It is deliberately independent of Qt and of
// PskModem: expensive demodulators are only created for real candidates.
class CarrierDetector
{
public:
  explicit CarrierDetector(double sampleRate = 12000.0,
                           int fftSize = 8192,
                           int hopSize = 2048);
  ~CarrierDetector();

  CarrierDetector(CarrierDetector const&) = delete;
  CarrierDetector& operator=(CarrierDetector const&) = delete;

  void setSampleRate(double rate);
  void setPassband(int lowHz, int highHz);
  void setBandwidth(double widthHz);
  void setThresholdDb(double db);
  void reset();

  void process(int16_t const* samples, int count);

  std::uint64_t sequence() const;
  std::vector<CarrierCandidate> const& candidates() const;

  // Finds the strongest candidate whose estimated centre lies in the range.
  bool peakInRange(double lowHz, double highHz, CarrierCandidate& result) const;

  // Applies non-maximum suppression for the dynamic tracker.
  std::vector<CarrierCandidate> detectAll(double minSeparationHz) const;

private:
  struct Impl;
  std::unique_ptr<Impl> impl_;
};

} // namespace Psk

#endif // PSK_CARRIER_DETECTOR_HPP
