#include "psk_varicode.hpp"
#include <cstdio>
#include <cassert>

int main() {
    bool all_passed = true;

    // Test 1: Verify encoding produces valid strings for all characters
    for (int c = 0; c < 256; c++) {
        const char* encoded = Psk::varicode_encode(c);
        if (!encoded || encoded[0] == '\0') {
            printf("FAIL: char %d has empty encoding\n", c);
            all_passed = false;
        }
        // Verify encoding string only contains '0' and '1'
        for (int i = 0; encoded[i]; i++) {
            if (encoded[i] != '0' && encoded[i] != '1') {
                printf("FAIL: char %d encoding contains invalid char: %s\n", c, encoded);
                all_passed = false;
                break;
            }
        }
    }

    // Test 2: Verify known symbols decode correctly
    // Space = "1" -> symbol 1
    int decoded = Psk::varicode_decode(1);
    if (decoded != ' ') {
        printf("FAIL: space symbol 1 decodes to %d, expected 32\n", decoded);
        all_passed = false;
    }

    // Test 3: Verify E/e both encode to same symbol and decode to canonical (E)
    const char* e_encoded = Psk::varicode_encode('E');
    uint32_t e_symbol = 0;
    for (int i = 0; e_encoded[i]; i++) {
        e_symbol = (e_symbol << 1) | (e_encoded[i] - '0');
    }
    if (e_symbol != 0x5D) {
        printf("FAIL: 'E' encodes to 0x%X, expected 0x5D\n", e_symbol);
        all_passed = false;
    }
    int e_decoded = Psk::varicode_decode(e_symbol);
    if (e_decoded != 'E') {
        printf("FAIL: symbol 0x5D decodes to %d ('%c'), expected 69 ('E')\n", e_decoded, e_decoded);
        all_passed = false;
    }

    const char* e_lower_encoded = Psk::varicode_encode('e');
    uint32_t e_lower_symbol = 0;
    for (int i = 0; e_lower_encoded[i]; i++) {
        e_lower_symbol = (e_lower_symbol << 1) | (e_lower_encoded[i] - '0');
    }
    if (e_lower_symbol != e_symbol) {
        printf("FAIL: 'e' encodes to 0x%X, expected same as 'E' (0x%X)\n", e_lower_symbol, e_symbol);
        all_passed = false;
    }

    // Test 4: Verify W/w/X/x all encode to same symbol
    const char* w_encoded = Psk::varicode_encode('W');
    uint32_t w_symbol = 0;
    for (int i = 0; w_encoded[i]; i++) {
        w_symbol = (w_symbol << 1) | (w_encoded[i] - '0');
    }
    const char* x_encoded = Psk::varicode_encode('X');
    uint32_t x_symbol = 0;
    for (int i = 0; x_encoded[i]; i++) {
        x_symbol = (x_symbol << 1) | (x_encoded[i] - '0');
    }
    if (w_symbol != x_symbol) {
        printf("FAIL: 'W' and 'X' encode to different symbols (0x%X vs 0x%X)\n", w_symbol, x_symbol);
        all_passed = false;
    }
    int w_decoded = Psk::varicode_decode(w_symbol);
    if (w_decoded != 'W') {
        printf("FAIL: W/X symbol 0x%X decodes to %d ('%c'), expected 87 ('W')\n", w_symbol, w_decoded, w_decoded);
        all_passed = false;
    }

    if (all_passed) {
        printf("test_psk_varicode: all checks passed\n");
        return 0;
    } else {
        return 1;
    }
}