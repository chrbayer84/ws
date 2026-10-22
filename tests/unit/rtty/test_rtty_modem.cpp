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

  // Modulate preamble and text at 48000 Hz (matching real transmission)
  std::vector<int16_t> pre = modem.modulatePreamble(8, 1500.0);
  std::vector<int16_t> textWave = modem.modulateText(testText, 1500.0);
  std::vector<int16_t> post = modem.modulatePostamble(1500.0);
  std::vector<int16_t> txWave;
  txWave.insert(txWave.end(), pre.begin(), pre.end());
  txWave.insert(txWave.end(), textWave.begin(), textWave.end());
  txWave.insert(txWave.end(), post.begin(), post.end());
  txWave.insert(txWave.end(), 4800, 0); // 100ms silence
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

  // Test short message ("CQ WA4YA CQ")
  std::string const shortText = "CQ WA4YA CQ";
  std::vector<int16_t> shortPre = modem.modulatePreamble(8, 1500.0);
  std::vector<int16_t> shortTxt = modem.modulateText(shortText, 1500.0);
  std::vector<int16_t> shortPost = modem.modulatePostamble(1500.0);
  std::vector<int16_t> shortTx;
  shortTx.insert(shortTx.end(), shortPre.begin(), shortPre.end());
  shortTx.insert(shortTx.end(), shortTxt.begin(), shortTxt.end());
  shortTx.insert(shortTx.end(), shortPost.begin(), shortPost.end());
  shortTx.insert(shortTx.end(), 4800, 0);

  std::vector<int16_t> shortRx;
  shortRx.reserve(shortTx.size() / 4);
  for (size_t i = 0; i < shortTx.size(); i += 4) {
    shortRx.push_back(shortTx[i]);
  }

  modem.rxInit();
  for (size_t offset = 0; offset < shortRx.size(); offset += 480) {
    size_t count = std::min((size_t)480, shortRx.size() - offset);
    modem.rxProcess(shortRx.data() + offset, static_cast<int>(count));
  }
  std::string shortDecoded = modem.takeDecodedText();
  std::cout << "Short message decoded: " << shortDecoded << std::endl;
  assert(!shortDecoded.empty());
  assert(shortDecoded.find("WA4YA") != std::string::npos);

  std::cout << "test_rtty_modem: all checks passed" << std::endl;
}

int main()
{
  testModemLoopback();
  return 0;
}
