// test_cw_gt_demod.cpp:
//
// Unit tests for CwGtDemod (gridtracker decoder) loopback modulation/demodulation.
//
// This file is part of WSJT-X.

#include "cw_modem.hpp"
#include "cw_gtdemod.hpp"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cmath>

using namespace Cw;

void testGtDemodLoopback()
{
    std::cout << "Running test_cw_gt_demod..." << std::endl;

    // Generate CW test signal
    CwModem modem;
    modem.setWpm(20);
    modem.setToneFrequency(600.0f);

    const int max_samples = 12000 * 3; // 3 seconds at 12 kHz
    std::vector<float> tx_signal(max_samples);

    int generated = modem.tx_process(tx_signal.data(), max_samples, "SOS TEST");
    std::cout << "  Generated " << generated << " samples" << std::endl;
    assert(generated > 0);

    // Demodulate with gridtracker decoder
    CwGtDemod demod;
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
}

// Two stations on different audio frequencies must be decoded at the same
// time, each into its own channel.
void testGtMultiChannel()
{
    std::cout << "Running testGtMultiChannel..." << std::endl;

    CwModem modem_a;
    modem_a.setWpm(20);
    modem_a.setToneFrequency(500.0f);

    CwModem modem_b;
    modem_b.setWpm(20);
    modem_b.setToneFrequency(1100.0f);

    std::vector<float> sig_a(12000 * 10);
    std::vector<float> sig_b(12000 * 10);
    int gen_a = modem_a.tx_process(sig_a.data(), static_cast<int>(sig_a.size()), "CQ CQ DE");
    int gen_b = modem_b.tx_process(sig_b.data(), static_cast<int>(sig_b.size()), "TEST 599");
    assert(gen_a > 0 && gen_b > 0);

    const int gen = std::max(gen_a, gen_b);
    std::vector<float> rx;
    rx.reserve(12000 + gen + 12000 * 2);
    rx.insert(rx.end(), 12000, 0.0f);
    for (int i = 0; i < gen; ++i) {
        float a = (i < gen_a) ? sig_a[i] : 0.0f;
        float b = (i < gen_b) ? sig_b[i] : 0.0f;
        rx.push_back(0.5f * a + 0.5f * b);
    }
    rx.insert(rx.end(), 12000 * 2, 0.0f);

    CwGtDemod demod;
    demod.setWpm(20);
    demod.setBandwidth(50);
    demod.setSquelch(3.0f);
    demod.setAdaptive(true);
    demod.setRange(150, 2000);
    demod.rx_init();

    std::map<int, std::string> by_channel;
    for (size_t off = 0; off < rx.size(); off += 1024) {
        int n = static_cast<int>(std::min<size_t>(1024, rx.size() - off));
        demod.rx_process(rx.data() + off, n, 0.0f);
        for (const auto& r : demod.get_results()) {
            if (!r.text.empty()) by_channel[r.channel] += r.text;
        }
    }

    bool have_cq = false;
    bool have_test = false;
    for (const auto& kv : by_channel) {
        std::cout << "  Channel " << kv.first << ": '" << kv.second << "'" << std::endl;
        if (kv.second.find("CQ") != std::string::npos) have_cq = true;
        if (kv.second.find("TEST") != std::string::npos) have_test = true;
    }

    bool const ok = have_cq && have_test && by_channel.size() >= 2;
    std::cout << "  Multi-channel CQ=" << have_cq << " TEST=" << have_test
              << " channels=" << by_channel.size() << (ok ? " OK" : " FAIL") << std::endl;
    assert(ok);
    (void)ok;
}

int main()
{
    testGtDemodLoopback();
    testGtMultiChannel();
    std::cout << "test_cw_gt_demod: all checks passed" << std::endl;
    return 0;
}
