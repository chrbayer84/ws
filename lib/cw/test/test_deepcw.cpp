// test_deepcw.cpp:
//
// Loopback test for the DeepCW neural decoder: CwModem -> DeepCw::Decoder.

#include "cw_modem.hpp"
#include "deepcw_decoder.hpp"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace Cw;

namespace {

std::string decode_text(int wpm, std::string const& text, double tone,
                        std::string& error) {
    CwModem modem;
    modem.setWpm(wpm);
    modem.setToneFrequency(static_cast<float>(tone));

    std::vector<float> tx(12000 * 20);
    const int generated = modem.tx_process(tx.data(), static_cast<int>(tx.size()), text);
    if (generated <= 0) {
        error = "modem produced no samples";
        return {};
    }

    std::vector<float> rx;
    rx.reserve(12000 + generated + 12000);
    rx.insert(rx.end(), 12000, 0.0f);
    rx.insert(rx.end(), tx.begin(), tx.begin() + generated);
    rx.insert(rx.end(), 12000, 0.0f);

    DeepCw::Settings settings;
    settings.model_path = std::string(DEEPCW_MODEL_DIR) + "/model.onnx";
    settings.max_segment_seconds = 12;
    settings.intra_threads = 2;

    DeepCw::Decoder decoder;
    if (!decoder.start(settings, error)) return {};

    std::vector<DeepCw::DecodeResult> results;
    const bool ok = decoder.decode_all(rx.data(), static_cast<int>(rx.size()),
                                       tone, results, error);
    decoder.stop();
    if (!ok) return {};

    std::string decoded;
    for (DeepCw::DecodeResult const& result : results) decoded += result.text;
    return decoded;
}

} // namespace

int main() {
    std::string error;
    bool ok = true;

    for (int wpm : {20, 30}) {
        const std::string decoded = decode_text(wpm, "CQ CQ DE N0CALL", 600.0, error);
        const bool pass = decoded.find("CQ") != std::string::npos
            && decoded.find("DE") != std::string::npos
            && decoded.find("N0CALL") != std::string::npos;
        std::cout << "  WPM " << wpm << " -> '" << decoded << "' " << (pass ? "OK" : "FAIL");
        if (!error.empty()) std::cout << " [" << error << "]";
        std::cout << std::endl;
        ok = ok && pass;
        error.clear();
    }

    if (!ok) {
        std::cout << "test_deepcw: FAILED" << std::endl;
        return 1;
    }
    std::cout << "test_deepcw: all checks passed" << std::endl;
    return 0;
}
