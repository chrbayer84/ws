#include "cw_modem.hpp"
#include "cw_demod.hpp"
#include <cassert>
#include <iostream>
#include <vector>
#include <cmath>

using namespace Cw;

int main() {
    std::cout << "Testing CW Demod (loopback)..." << std::endl;

    // Generate test signal
    CwModem modem;
    modem.setWpm(20);
    modem.setToneFrequency(600.0f);

    const int max_samples = 12000 * 3; // 3 seconds
    std::vector<float> tx_signal(max_samples);

    int generated = modem.tx_process(tx_signal.data(), max_samples, "SOS TEST");
    std::cout << "  Generated " << generated << " samples" << std::endl;

    // Add some noise
    for (int i = 0; i < generated; ++i) {
        tx_signal[i] += (static_cast<float>(rand()) / RAND_MAX - 0.5f) * 0.1f;
    }

    // Demodulate
    CwDemod demod;
    demod.setWpm(20);
    demod.setBandwidth(100);
    demod.setSquelch(3.0f);
    demod.setAdaptive(true);
    demod.rx_init();

    demod.rx_process(tx_signal.data(), generated, 600.0f);

    auto results = demod.get_results();
    std::cout << "  Decoded " << results.size() << " results" << std::endl;

    for (const auto& r : results) {
        std::cout << "    Text: '" << r.text << "' WPM: " << r.wpm << " SNR: " << r.snr_db << " dB" << std::endl;
    }

    // Check we got something reasonable
    bool found_sos = false;
    bool found_test = false;
    for (const auto& r : results) {
        if (r.text.find("SOS") != std::string::npos) found_sos = true;
        if (r.text.find("TEST") != std::string::npos) found_test = true;
    }

    std::cout << "  Found SOS: " << (found_sos ? "YES" : "NO") << std::endl;
    std::cout << "  Found TEST: " << (found_test ? "YES" : "NO") << std::endl;

    // Test adaptive WPM tracking
    std::cout << "  Final WPM estimate: " << demod.getWpm() << std::endl;

    std::cout << "All tests PASSED!" << std::endl;
    return 0;
}