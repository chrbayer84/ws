// test_cw_fldigi_demod.cpp:
//
// Unit tests for CwDemod (fldigi decoder) loopback modulation/demodulation.
//
// This file is part of WSJT-X.

#include "cw_modem.hpp"
#include "cw_demod.hpp"
#include <cassert>
#include <iostream>
#include <vector>
#include <cmath>

using namespace Cw;

void testFldigiDemodLoopback()
{
    std::cout << "Running test_cw_fldigi_demod..." << std::endl;

    // Generate CW test signal
    CwModem modem;
    modem.setWpm(20);
    modem.setToneFrequency(600.0f);

    const int max_samples = 12000 * 3; // 3 seconds at 12 kHz
    std::vector<float> tx_signal(max_samples);

    int generated = modem.tx_process(tx_signal.data(), max_samples, "SOS TEST");
    std::cout << "  Generated " << generated << " samples" << std::endl;
    assert(generated > 0);

    // Demodulate with fldigi decoder
    CwDemod demod;
    demod.setWpm(20);
    demod.setBandwidth(100);
    demod.setSquelch(3.0f);
    demod.setAdaptive(true);
    demod.rx_init();

    demod.rx_process(tx_signal.data(), generated, 600.0f);

    auto results = demod.get_results();
    std::cout << "  Decoded " << results.size() << " results" << std::endl;

    // Check we decoded something reasonable
    std::string all_text;
    for (const auto& r : results) {
        std::cout << "    Text: '" << r.text << "' WPM: " << r.wpm << " SNR: " << r.snr_db << " dB" << std::endl;
        all_text += r.text;
    }

    assert(!all_text.empty());
    std::cout << "  Combined text: '" << all_text << "'" << std::endl;

    std::cout << "test_cw_fldigi_demod: all checks passed" << std::endl;
}

int main()
{
    testFldigiDemodLoopback();
    return 0;
}
