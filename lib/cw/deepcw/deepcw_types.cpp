#include "deepcw_types.hpp"

namespace Cw {
namespace DeepCw {

namespace {

const char* const kChars[] = {
    ",", ".", "/", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "?",
    "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N",
    "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", " "
};

const ModelSpec kStandard = {
    "standard", 65, 400.0, 1200.0, 41, 42, kChars
};

const ModelSpec kNarrow = {
    "narrow", 3, 787.5, 812.5, 41, 42, kChars
};

} // namespace

const ModelSpec& standard_spec() { return kStandard; }
const ModelSpec& narrow_spec() { return kNarrow; }

int space_index(const ModelSpec& spec) {
    for (int i = 0; i < spec.num_classes; ++i) {
        if (spec.chars[i] && spec.chars[i][0] == ' ' && spec.chars[i][1] == '\0') {
            return i;
        }
    }
    return -1;
}

} // namespace DeepCw
} // namespace Cw
