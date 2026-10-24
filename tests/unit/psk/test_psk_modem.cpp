#include "psk_modem.hpp"
#include "psk_varicode.hpp"
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

    // Test 3b: Direct Encoder -> Viterbi codec test
    {
        Psk::Encoder enc;
        Psk::Viterbi dec;
        std::vector<int> testBits = {1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1,
                                     0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0};
        // Add 64 flush zeros
        for (int i = 0; i < 64; ++i) testBits.push_back(0);

        std::vector<int> outBits;
        for (int b : testBits) {
            int symVal = enc.encode(b);
            uint8_t sym[2];
            sym[0] = (symVal & 1) ? 255 : 0;
            sym[1] = (symVal & 2) ? 255 : 0;
            int c = dec.decode(sym);
            if (c != -1) {
                for (int bitPos = 7; bitPos >= 0; --bitPos) {
                    outBits.push_back((c >> bitPos) & 1);
                }
            }
        }
        // Viterbi has 60 symbols traceback delay (53 to 60 bit offset)
        bool matched = false;
        for (size_t offset = 48; offset <= 64; ++offset) {
            bool ok = true;
            for (size_t i = 0; i < 32; ++i) {
                if (offset + i >= outBits.size() || outBits[offset + i] != testBits[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                matched = true;
                break;
            }
        }
        if (!matched) {
            printf("FAIL: Direct Encoder -> Viterbi codec test failed\n");
            all_passed = false;
        } else {
            printf("SUCCESS: Direct Encoder -> Viterbi codec test passed\n");
        }
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

    // Test 7: PSK63 (62.5 baud) loopback
    Psk::PskModem modem63;
    modem63.setBaud(62.5);
    std::string const msg63 = "HELLO FROM PSK63";
    std::vector<int16_t> tx63 = modem63.modulateText(msg63, 1500.0);
    std::vector<int16_t> rx63;
    rx63.reserve(tx63.size() / 4);
    for (size_t i = 0; i < tx63.size(); i += 4) {
        rx63.push_back(tx63[i]);
    }
    modem63.rxInit();
    for (size_t offset = 0; offset < rx63.size(); offset += chunkSize) {
        size_t count = std::min(chunkSize, rx63.size() - offset);
        modem63.rxProcess(rx63.data() + offset, static_cast<int>(count));
    }
    std::string dec63 = modem63.takeOutput();
    printf("INFO: PSK63 decoded text: '%s'\n", dec63.c_str());
    if (dec63.find(msg63) == std::string::npos) {
        printf("FAIL: PSK63 decoded text does not contain '%s'\n", msg63.c_str());
        all_passed = false;
    } else {
        printf("SUCCESS: Decoded exact PSK63 message '%s'\n", msg63.c_str());
    }

    // Test 8: QPSK31 (31.25 baud QPSK with Viterbi FEC) loopback
    Psk::PskModem modemQ31;
    modemQ31.setBaud(31.25);
    modemQ31.setQpsk(true);
    modemQ31.setAfc(false);
    std::string const msgQ31 = "HELLO QPSK31";

    std::vector<int16_t> txQ31 = modemQ31.modulateText(msgQ31, 1500.0);
    std::vector<int16_t> rxQ31;
    rxQ31.reserve(txQ31.size() / 4);
    for (size_t i = 0; i < txQ31.size(); i += 4) {
        rxQ31.push_back(txQ31[i]);
    }
    modemQ31.rxInit();
    modemQ31.setAfc(false);
    for (size_t offset = 0; offset < rxQ31.size(); offset += chunkSize) {
        size_t count = std::min(chunkSize, rxQ31.size() - offset);
        modemQ31.rxProcess(rxQ31.data() + offset, static_cast<int>(count));
    }
    std::string decQ31 = modemQ31.takeOutput();
    printf("INFO: QPSK31 decoded text: '%s'\n", decQ31.c_str());
    if (decQ31.find(msgQ31) == std::string::npos) {
        printf("FAIL: QPSK31 decoded text does not contain '%s'\n", msgQ31.c_str());
        all_passed = false;
    } else {
        printf("SUCCESS: Decoded exact QPSK31 message '%s'\n", msgQ31.c_str());
    }

    // Test 9: QPSK63 (62.5 baud QPSK with Viterbi FEC) loopback
    Psk::PskModem modemQ63;
    modemQ63.setBaud(62.5);
    modemQ63.setQpsk(true);
    std::string const msgQ63 = "QPSK63 TEST OK";
    std::vector<int16_t> txQ63 = modemQ63.modulateText(msgQ63, 1500.0);
    std::vector<int16_t> rxQ63;
    rxQ63.reserve(txQ63.size() / 4);
    for (size_t i = 0; i < txQ63.size(); i += 4) {
        rxQ63.push_back(txQ63[i]);
    }
    modemQ63.rxInit();
    for (size_t offset = 0; offset < rxQ63.size(); offset += chunkSize) {
        size_t count = std::min(chunkSize, rxQ63.size() - offset);
        modemQ63.rxProcess(rxQ63.data() + offset, static_cast<int>(count));
    }
    std::string decQ63 = modemQ63.takeOutput();
    printf("INFO: QPSK63 decoded text: '%s'\n", decQ63.c_str());
    if (decQ63.find(msgQ63) == std::string::npos) {
        printf("FAIL: QPSK63 decoded text does not contain '%s'\n", msgQ63.c_str());
        all_passed = false;
    } else {
        printf("SUCCESS: Decoded exact QPSK63 message '%s'\n", msgQ63.c_str());
    }

    if (all_passed) {
        printf("test_psk_modem: all checks passed\n");
        return 0;
    } else {
        return 1;
    }
}
