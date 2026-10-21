// test_rtty_modem.cpp:
//
// Unit tests for RttyModem loopback round-trip modulation/demodulation
//
// This file is part of WSJT-X.
//==============================================================================

#include "lib/rtty/rtty_modem.hpp"
#include <iostream>
#include <cassert>

void testModemLoopback()
{
  std::cout << "Running testModemLoopback..." << std::endl;

  Rtty::RttyModem modem(45.4545, 170.0, 12000.0, 48000.0);
  modem.setFrequency(1500.0);
  modem.rxInit();
  modem.txInit();

  std::string const testText = "CQ DE K1JT TEST RTTY";
  std::cout << "Input text: " << testText << std::endl;

  // Modulate text at 48000 Hz
  std::vector<int16_t> txWave = modem.modulateText(testText, 1500.0);
  std::cout << "Generated txWave size: " << txWave.size() << std::endl;
  std::cout << "Middle 10 txWave samples (around index 50000): ";
  for (int i = 50000; i < 50010 && i < (int)txWave.size(); ++i) {
    std::cout << txWave[i] << " ";
  }
  std::cout << std::endl;

  // Downsample/Convert the 48000 Hz TX samples to 12000 Hz RX samples.
  // We can do this simply by decimating 4:1 since 48000/12000 = 4.
  std::vector<int16_t> rxWave;
  rxWave.reserve(txWave.size() / 4);
  for (size_t i = 0; i < txWave.size(); i += 4) {
    rxWave.push_back(txWave[i]);
  }
  std::cout << "Decimated rxWave size: " << rxWave.size() << std::endl;
  std::cout << "Middle 10 rxWave samples (around index 12500): ";
  for (int i = 12500; i < 12510 && i < (int)rxWave.size(); ++i) {
    std::cout << rxWave[i] << " ";
  }
  std::cout << std::endl;

  // Feed the 12000 Hz samples to the receiver
  modem.rxProcess(rxWave.data(), static_cast<int>(rxWave.size()));

  // Retrieve decoded text
  std::string decodedText = modem.takeDecodedText();
  std::cout << "Decoded text: " << decodedText << std::endl;

  // We should expect a clean decode
  assert(!decodedText.empty());
  assert(decodedText.find("DE K1JT") != std::string::npos);

  std::cout << "test_rtty_modem: all checks passed" << std::endl;
}

int main()
{
  testModemLoopback();
  return 0;
}
