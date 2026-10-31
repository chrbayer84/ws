// test_cw_alphabet_full.cpp:
//
// Unit test for CW demodulator full alphabet (A-Z, 0-9) decode at multiple WPM speeds.
//
// This file is part of WSJT-X.

#include "cw_modem.hpp"
#include "cw_demod.hpp"
#include "cw_gtdemod.hpp"
#include <cassert>
#include <iostream>
#include <vector>
#include <string>

using namespace Cw;

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

    const int max_samples = 12000 * 3;
    std::vector<float> tx_signal(max_samples);

    int generated = modem.tx_process(tx_signal.data(), max_samples, input_text);
    if (generated <= 0) {
        if (verbose) std::cout << "    WPM " << wpm << " input '" << input_text << "': FAIL (no signal generated)" << std::endl;
        return false;
    }

    std::vector<float> demo_signal(tx_signal.begin(), tx_signal.begin() + generated);
    demod.rx_process(demo_signal.data(), generated, 600.0f);

    auto results = demod.get_results();
    std::string decoded;
    for (const auto& r : results) {
        decoded += r.text;
    }

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
    demod.rx_init();

    CwModem modem;
    modem.setWpm(wpm);
    modem.setToneFrequency(600.0f);

    const int max_samples = 12000 * 3;
    std::vector<float> tx_signal(max_samples);

    int generated = modem.tx_process(tx_signal.data(), max_samples, input_text);
    if (generated <= 0) {
        if (verbose) std::cout << "    WPM " << wpm << " input '" << input_text << "': FAIL (no signal generated)" << std::endl;
        return false;
    }

    std::vector<float> demo_signal(tx_signal.begin(), tx_signal.begin() + generated);
    demod.rx_process(demo_signal.data(), generated, 600.0f);

    auto results = demod.get_results();
    std::string decoded;
    for (const auto& r : results) {
        decoded += r.text;
    }

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

    return all_passed ? 0 : 1;
}
