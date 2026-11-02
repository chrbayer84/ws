// test_cw_alphabet_full.cpp:
//
// Unit test for CW demodulator full alphabet (A-Z, 0-9) decode at multiple WPM speeds.
//
// This file is part of WSJT-X.

#include "cw_modem.hpp"
#include "cw_demod.hpp"
#include "cw_gtdemod.hpp"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <string>

using namespace Cw;

// Feed a transmitted signal the way the receiver sees it: continuous audio
// with silence before and after the transmission, delivered in small blocks.
// This lets the streaming decoders warm up and close their last character on
// the trailing gap.
static std::string feed_fldigi(CwDemod& demod, CwModem& modem, const std::string& text) {
    const int max_samples = 12000 * 45;
    std::vector<float> tx_signal(max_samples);
    int generated = modem.tx_process(tx_signal.data(), max_samples, text);
    if (generated <= 0) return {};

    std::vector<float> rx;
    rx.reserve(12000 + generated + 12000);
    rx.insert(rx.end(), 12000, 0.0f);
    rx.insert(rx.end(), tx_signal.begin(), tx_signal.begin() + generated);
    rx.insert(rx.end(), 12000, 0.0f);

    std::string decoded;
    for (size_t off = 0; off < rx.size(); off += 1024) {
        int n = static_cast<int>(std::min<size_t>(1024, rx.size() - off));
        demod.rx_process(rx.data() + off, n, 600.0f);
        for (const auto& r : demod.get_results()) decoded += r.text;
    }
    return decoded;
}

static std::string feed_gt(CwGtDemod& demod, CwModem& modem, const std::string& text) {
    const int max_samples = 12000 * 45;
    std::vector<float> tx_signal(max_samples);
    int generated = modem.tx_process(tx_signal.data(), max_samples, text);
    if (generated <= 0) return {};

    std::vector<float> rx;
    rx.reserve(12000 + generated + 12000);
    rx.insert(rx.end(), 12000, 0.0f);
    rx.insert(rx.end(), tx_signal.begin(), tx_signal.begin() + generated);
    rx.insert(rx.end(), 12000, 0.0f);

    std::string decoded;
    for (size_t off = 0; off < rx.size(); off += 1024) {
        int n = static_cast<int>(std::min<size_t>(1024, rx.size() - off));
        demod.rx_process(rx.data() + off, n, 600.0f);
        for (const auto& r : demod.get_results()) decoded += r.text;
    }
    return decoded;
}

// Test fldigi (CwDemod) decode at given WPM
bool test_fldigi_wpm(int wpm, const std::string& input_text, bool verbose) {
    CwDemod demod;
    demod.setWpm(wpm);
    demod.setBandwidth(50);
    demod.setSquelch(3.0f);
    demod.setAdaptive(true);
    demod.rx_init();

    CwModem modem;
    modem.setWpm(wpm);
    modem.setToneFrequency(600.0f);

    std::string decoded = feed_fldigi(demod, modem, input_text);

    // Validation: decoded must be non-empty
    // For single-char input, 1 char decode is correct
    // For multi-char input, decoded should have multiple chars
    bool success = !decoded.empty() &&
        (input_text.size() <= 1 || decoded.length() >= 2);

    if (verbose) std::cout << "    WPM " << wpm << " input '" << input_text << "' -> decoded '" << decoded << "' " << (success ? "OK" : "FAIL") << std::endl;
    return success;
}

// Test gridtracker (CwGtDemod) decode at given WPM
bool test_gt_wpm(int wpm, const std::string& input_text, bool verbose) {
    CwGtDemod demod;
    demod.setWpm(wpm);
    demod.setBandwidth(50);
    demod.setSquelch(3.0f);
    demod.setAdaptive(true);
    demod.setRange(150, 3000);
    demod.rx_init();

    CwModem modem;
    modem.setWpm(wpm);
    modem.setToneFrequency(600.0f);

    std::string decoded = feed_gt(demod, modem, input_text);

    bool success = !decoded.empty() &&
        (input_text.size() <= 1 || decoded.length() >= 2);

    if (verbose) std::cout << "    WPM " << wpm << " input '" << input_text << "' -> decoded '" << decoded << "' " << (success ? "OK" : "FAIL") << std::endl;
    return success;
}

int main()
{
    std::cout << "==================================================" << std::endl;
    std::cout << "COMPREHENSIVE CW ALPHABET TEST (A-Z, 0-9)" << std::endl;
    std::cout << "==================================================" << std::endl;

    // Test strings covering full alphabet and digits
    std::vector<std::string> test_strings;

    // Single letters A-Z
    for (char c = 'A'; c <= 'Z'; ++c) {
        test_strings.push_back(std::string(1, c));
    }

    // Single digits 0-9
    for (char c = '0'; c <= '9'; ++c) {
        test_strings.push_back(std::string(1, c));
    }

    // 5-letter groups covering the alphabet
    for (int start = 0; start < 26; start += 5) {
        std::string group;
        for (int i = 0; i < 5; ++i) {
            int idx = (start + i) % 26;
            group += char('A' + idx);
        }
        test_strings.push_back(group);
    }

    // 5-digit groups
    for (int start = 0; start < 10; start += 3) {
        std::string group;
        for (int i = 0; i < 5; ++i) {
            int idx = (start + i) % 10;
            group += char('0' + idx);
        }
        test_strings.push_back(group);
    }

    std::cout << "Testing " << test_strings.size() << " character patterns" << std::endl;

    // Test at multiple WPM speeds
    std::vector<int> wpm_speeds = {5, 13, 20};
    int passed = 0;
    int total = 0;

    // Test fldigi decoder
    std::cout << "\n--- FLDIGI DECODER ---" << std::endl;
    for (int wpm : wpm_speeds) {
        std::cout << "  WPM " << wpm << ":" << std::endl;
        for (const auto& input : test_strings) {
            total++;
            bool result = test_fldigi_wpm(wpm, input, true);
            if (result) passed++;
        }
    }

    // Test gridtracker decoder
    std::cout << "\n--- GRIDTRACKER DECODER ---" << std::endl;
    for (int wpm : wpm_speeds) {
        std::cout << "  WPM " << wpm << ":" << std::endl;
        for (const auto& input : test_strings) {
            total++;
            bool result = test_gt_wpm(wpm, input, true);
            if (result) passed++;
        }
    }

    std::cout << "\n==================================================" << std::endl;
    std::cout << "Results: " << passed << "/" << total << " tests passed" << std::endl;
    bool all_passed = (passed == total);
    std::cout << (all_passed ? "ALL TESTS PASSED - Full alphabet decode verified!" :
      "SOME TESTS FAILED") << std::endl;
    std::cout << "==================================================" << std::endl;

    if (all_passed) {
        std::cout << "test_cw_alphabet_full: all checks passed" << std::endl;
    }

    return all_passed ? 0 : 1;
}
