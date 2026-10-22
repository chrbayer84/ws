#include "psk_modem.hpp"
#include <cstdio>
#include <cmath>
#include <vector>

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

    // Test 3: TX init and text modulation
    modem.txInit();
    std::vector<int16_t> txAudio = modem.modulateText("TEST", 1500.0);
    if (txAudio.empty()) {
        printf("FAIL: TX audio buffer empty\n");
        all_passed = false;
    } else {
        printf("INFO: Generated %zu samples for TX\n", txAudio.size());
    }

    // Test 4: RX init
    modem.rxInit();
    if (modem.isDCD()) {
        printf("FAIL: DCD should be false after init\n");
        all_passed = false;
    }

    // Test 5: Process some silence (should not produce output)
    std::vector<int16_t> silence(480, 0);
    int symbols = modem.rxProcess(silence.data(), silence.size());
    if (symbols < 0) {
        printf("FAIL: rxProcess returned negative\n");
        all_passed = false;
    }

    if (all_passed) {
        printf("test_psk_modem: all checks passed\n");
        return 0;
    } else {
        return 1;
    }
}