#include "psk_modem.hpp"
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <cassert>

int main() {
    bool all_passed = true;

    // Test 1: Modem construction
    Psk::PskModem modem;
    if (modem.getFrequency() != 1500.0) {
        printf("FAIL: Default frequency not 1500 Hz\n");
        all_passed = false;
    }

    // Test 2: Frequency setting
    modem.setFrequency(1000.0);
    if (std::abs(modem.getFrequency() - 1000.0) > 0.01) {
        printf("FAIL: Frequency not set correctly\n");
        all_passed = false;
    }

    // Test 3: RX init
    modem.setFrequency(1500.0);
    modem.rxInit();
    if (modem.isDCD()) {
        printf("FAIL: DCD should be false after init\n");
        all_passed = false;
    }

    // Test 4: Process silence (should not produce false characters)
    std::vector<int16_t> silence(4800, 0);
    modem.rxProcess(silence.data(), silence.size());
    if (modem.hasOutput()) {
        printf("FAIL: Silence produced output: '%s'\n", modem.takeOutput().c_str());
        all_passed = false;
    }

    // Test 5: Full loopback round-trip test (48 kHz TX -> 4:1 decimate -> 12 kHz RX)
    std::string const testText = "CQ CQ DE K1JT TEST 123";
    std::vector<int16_t> txAudio = modem.modulateText(testText, 1500.0);
    if (txAudio.empty()) {
        printf("FAIL: TX audio buffer empty\n");
        all_passed = false;
    } else {
        printf("INFO: Generated %zu samples for TX (48 kHz)\n", txAudio.size());
    }

    // Decimate 4:1 to 12 kHz
    std::vector<int16_t> rxAudio;
    rxAudio.reserve(txAudio.size() / 4);
    for (size_t i = 0; i < txAudio.size(); i += 4) {
        rxAudio.push_back(txAudio[i]);
    }
    printf("INFO: Decimated to %zu samples for RX (12 kHz)\n", rxAudio.size());

    // Feed in chunks to simulate incoming audio stream
    modem.rxInit();
    size_t const chunkSize = 480; // 40ms at 12 kHz
    for (size_t offset = 0; offset < rxAudio.size(); offset += chunkSize) {
        size_t count = std::min(chunkSize, rxAudio.size() - offset);
        modem.rxProcess(rxAudio.data() + offset, static_cast<int>(count));
    }

    std::string decoded = modem.takeOutput();
    printf("INFO: Decoded text: '%s'\n", decoded.c_str());

    if (decoded.find(testText) == std::string::npos) {
        printf("FAIL: Decoded text does not contain expected '%s'\n", testText.c_str());
        all_passed = false;
    } else {
        printf("SUCCESS: Decoded exact message '%s'\n", testText.c_str());
    }

    // Test 6: Short message round-trip ("CQ WA4YA CQ")
    std::string const shortMsg = "CQ WA4YA CQ";
    std::vector<int16_t> shortTx = modem.modulateText(shortMsg, 1500.0);
    std::vector<int16_t> shortRx;
    shortRx.reserve(shortTx.size() / 4);
    for (size_t i = 0; i < shortTx.size(); i += 4) {
        shortRx.push_back(shortTx[i]);
    }
    modem.rxInit();
    for (size_t offset = 0; offset < shortRx.size(); offset += chunkSize) {
        size_t count = std::min(chunkSize, shortRx.size() - offset);
        modem.rxProcess(shortRx.data() + offset, static_cast<int>(count));
    }
    std::string shortDecoded = modem.takeOutput();
    printf("INFO: Short message decoded text: '%s'\n", shortDecoded.c_str());
    if (shortDecoded.find(shortMsg) == std::string::npos) {
        printf("FAIL: Short message decoded text does not contain '%s'\n", shortMsg.c_str());
        all_passed = false;
    } else {
        printf("SUCCESS: Decoded exact short message '%s'\n", shortMsg.c_str());
    }

    if (all_passed) {
        printf("test_psk_modem: all checks passed\n");
        return 0;
    } else {
        return 1;
    }
}
