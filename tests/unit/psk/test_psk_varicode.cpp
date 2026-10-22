#include "psk_varicode.hpp"
#include <cstdio>
#include <cassert>
#include <cstring>

int main() {
    bool all_passed = true;

    // Test 1: Verify encoding produces valid strings for all 256 characters
    for (int c = 0; c < 256; c++) {
        const char* encoded = Psk::varicode_encode(static_cast<uint8_t>(c));
        if (!encoded || encoded[0] == '\0') {
            printf("FAIL: char %d has empty encoding\n", c);
            all_passed = false;
        }
        for (int i = 0; encoded[i]; i++) {
            if (encoded[i] != '0' && encoded[i] != '1') {
                printf("FAIL: char %d encoding contains invalid char: %s\n", c, encoded);
                all_passed = false;
                break;
            }
        }
    }

    // Test 2: Verify known standard PSK31 symbols decode correctly
    // Space = "1" -> symbol 1
    if (Psk::varicode_decode(1) != ' ') {
        printf("FAIL: space symbol 1 does not decode to ' '\n");
        all_passed = false;
    }

    // 'e' = "11" -> symbol 3
    if (Psk::varicode_decode(3) != 'e') {
        printf("FAIL: 'e' symbol 3 does not decode to 'e'\n");
        all_passed = false;
    }

    // 't' = "101" -> symbol 5
    if (Psk::varicode_decode(5) != 't') {
        printf("FAIL: 't' symbol 5 does not decode to 't'\n");
        all_passed = false;
    }

    // 'o' = "111" -> symbol 7
    if (Psk::varicode_decode(7) != 'o') {
        printf("FAIL: 'o' symbol 7 does not decode to 'o'\n");
        all_passed = false;
    }

    // 'a' = "1011" -> symbol 0x0B (11)
    if (Psk::varicode_decode(0x0B) != 'a') {
        printf("FAIL: 'a' symbol 0x0B does not decode to 'a'\n");
        all_passed = false;
    }

    // Test 3: Round-trip encode -> decode for all 256 characters
    for (int c = 0; c < 256; c++) {
        const char* enc = Psk::varicode_encode(static_cast<uint8_t>(c));
        uint32_t sym = 0;
        for (int i = 0; enc[i]; i++) {
            sym = (sym << 1) | (enc[i] - '0');
        }
        int dec = Psk::varicode_decode(sym);
        if (dec != c) {
            printf("FAIL: round-trip char %d ('%c'): encoded=%s, sym=0x%X, decoded=%d ('%c')\n",
                   c, (c >= 32 && c < 127) ? c : '?', enc, sym, dec, (dec >= 32 && dec < 127) ? dec : '?');
            all_passed = false;
        }
    }

    if (all_passed) {
        printf("test_psk_varicode: all checks passed\n");
        return 0;
    } else {
        return 1;
    }
}
