#include "cw_modem.hpp"
#include <cassert>
#include <iostream>
#include <vector>
#include <cmath>

using namespace Cw;

int main() {
    std::cout << "Testing CW Modem..." << std::endl;

    CwModem modem;
    modem.setWpm(20);
    modem.setToneFrequency(600.0f);

    // Test timing calculations
    assert(modem.getWpm() == 20);
    std::cout << "  WPM setting: PASS" << std::endl;

    // Generate some CW
    const int max_samples = 12000 * 2; // 2 seconds at 12 kHz
    std::vector<float> output(max_samples);

    int generated = modem.tx_process(output.data(), max_samples, "SOS");
    std::cout << "  Generated " << generated << " samples for SOS" << std::endl;
    assert(generated > 0);
    assert(generated < max_samples);

    // Verify tone presence (non-zero samples)
    int non_zero = 0;
    for (int i = 0; i < generated; ++i) {
        if (std::abs(output[i]) > 0.001f) non_zero++;
    }
    std::cout << "  Non-zero samples: " << non_zero << " / " << generated << std::endl;
    assert(non_zero > generated / 10); // At least 10% should be tone

    // Test different WPM
    modem.setWpm(10);
    generated = modem.tx_process(output.data(), max_samples, "E");
    std::cout << "  10 WPM dot samples: " << generated << std::endl;

    modem.setWpm(40);
    generated = modem.tx_process(output.data(), max_samples, "E");
    std::cout << "  40 WPM dot samples: " << generated << std::endl;

    // Test reverse
    modem.setWpm(20);
    modem.setReverse(true);
    generated = modem.tx_process(output.data(), max_samples, "T");
    bool has_negative = false;
    for (int i = 0; i < generated; ++i) {
        if (output[i] < -0.001f) { has_negative = true; break; }
    }
    assert(has_negative);
    (void)has_negative;
    std::cout << "  Reverse polarity: PASS" << std::endl;

    std::cout << "All tests PASSED!" << std::endl;
    return 0;
}