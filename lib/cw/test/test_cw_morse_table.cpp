#include "cw_morse_table.hpp"
#include <cassert>
#include <iostream>
#include <string>

using namespace Cw;

int main() {
    std::cout << "Testing CW Morse Table..." << std::endl;

    // Test encode_char
    assert(encode_char('A') == ".-");
    assert(encode_char('B') == "-...");
    assert(encode_char('Z') == "--..");
    assert(encode_char('0') == "-----");
    assert(encode_char('5') == ".....");
    assert(encode_char('.') == ".-.-.-");
    assert(encode_char(',') == "--..--");
    assert(encode_char('?') == "..--..");
    std::cout << "  encode_char: PASS" << std::endl;

    // Test encode_string
    assert(encode_string("SOS") == "... --- ...");
    assert(encode_string("CQ") == "-.-. --.-");
    assert(encode_string("HELLO WORLD") == ".... . .-.. .-.. ---   .-- --- .-. .-.. -..");
    std::cout << "  encode_string: PASS" << std::endl;

    // Test decode_morse
    assert(decode_morse(".-") == "A");
    assert(decode_morse("-...") == "B");
    assert(decode_morse("--..") == "Z");
    assert(decode_morse("-----") == "0");
    assert(decode_morse(".-.-.-") == ".");
    assert(decode_morse("-...-") == "<SK>");
    assert(decode_morse(".-.-") == "<AR>");
    assert(decode_morse("-.-.") == "<KN>");
    std::cout << "  decode_morse: PASS" << std::endl;

    // Test round-trip
    std::string original = "HELLO WORLD";
    std::string morse = encode_string(original);
    std::cout << "  Original: " << original << std::endl;
    std::cout << "  Morse: " << morse << std::endl;

    // Test prosigns
    assert(encode_string("<SK>") == "-...-");
    assert(encode_string("<AR>") == ".-.-");
    assert(encode_string("<KN>") == "-.-.");
    std::cout << "  prosigns: PASS" << std::endl;

    std::cout << "All tests PASSED!" << std::endl;
    return 0;
}