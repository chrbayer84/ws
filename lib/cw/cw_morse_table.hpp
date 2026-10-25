#ifndef CW_MORSE_TABLE_HPP
#define CW_MORSE_TABLE_HPP

#include <array>
#include <string>
#include <unordered_map>
#include <vector>

namespace Cw {

struct MorseSymbol {
    std::string representation;
    std::vector<float> weights;
};

const std::vector<MorseSymbol>& get_morse_table();

const std::unordered_map<std::string, std::string>& get_encode_map();
const std::unordered_map<std::string, std::string>& get_decode_map();

inline std::string encode_char(char c) {
    std::string s(1, std::toupper(c));
    auto it = get_encode_map().find(s);
    if (it != get_encode_map().end()) return it->second;
    return "";
}

inline std::string encode_string(const std::string& text) {
    std::string result;
    for (size_t i = 0; i < text.size(); ++i) {
        if (text[i] == '<') {
            size_t end = text.find('>', i);
            if (end != std::string::npos) {
                std::string prosign = text.substr(i, end - i + 1);
                auto it = get_encode_map().find(prosign);
                if (it != get_encode_map().end()) {
                    if (!result.empty()) result += " ";
                    result += it->second;
                    i = end;
                    continue;
                }
            }
        }
        std::string morse = encode_char(text[i]);
        if (!morse.empty()) {
            if (!result.empty()) result += " ";
            result += morse;
        }
    }
    return result;
}

inline std::string decode_morse(const std::string& morse_pattern) {
    auto it = get_decode_map().find(morse_pattern);
    if (it != get_decode_map().end()) return it->second;
    return "?";
}

} // namespace Cw

#endif // CW_MORSE_TABLE_HPP