//==============================================================================
// rtty_baudot.cpp:
//
// Baudot (ITA2) character coding definitions and state machine for RTTY
//
// This file is part of WSJT-X.
//==============================================================================

#include "rtty_baudot.hpp"
#include <cctype>

namespace Rtty
{
  namespace
  {
    constexpr char kLetters[32] = {
      '\0', 'E',  '\n', 'A',  ' ',  'S',  'I',  'U',
      '\r', 'D',  'R',  'J',  'N',  'F',  'C',  'K',
      'T',  'Z',  'L',  'W',  'H',  'Y',  'P',  'Q',
      'O',  'B',  'G',  ' ',  'M',  'X',  'V',  ' '
    };

    constexpr char kFigures[32] = {
      '\0', '3',  '\n', '-',  ' ',  '\a', '8',  '7',
      '\r', '$',  '4',  '\'', ',',  '!',  ':',  '(',
      '5',  '"',  ')',  '2',  '#',  '6',  '0',  '1',
      '9',  '?',  '&',  ' ',  '.',  '/',  ';',  ' '
    };
  }

  char Baudot::letterChar(uint8_t index)
  {
    return kLetters[index & 0x1F];
  }

  char Baudot::figureChar(uint8_t index)
  {
    return kFigures[index & 0x1F];
  }

  EncodedBaudot Baudot::encode(char c)
  {
    EncodedBaudot result;
    if (c == '\r') {
      result.valid = true;
      result.requiredShift = ShiftState::Letters;
      result.code = CR_CODE;
      return result;
    }
    if (c == '\n') {
      result.valid = true;
      result.requiredShift = ShiftState::Letters;
      result.code = LF_CODE;
      return result;
    }
    if (c == ' ') {
      result.valid = true;
      result.requiredShift = ShiftState::Letters;
      result.code = SPACE_CODE;
      return result;
    }

    char const upper = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));

    for (uint8_t i = 0; i < 32; ++i) {
      if (kLetters[i] != '\0' && kLetters[i] == upper) {
        result.valid = true;
        result.requiredShift = ShiftState::Letters;
        result.code = i;
        return result;
      }
    }

    for (uint8_t i = 0; i < 32; ++i) {
      if (kFigures[i] != '\0' && kFigures[i] == upper) {
        result.valid = true;
        result.requiredShift = ShiftState::Figures;
        result.code = i;
        return result;
      }
    }

    return result;
  }

  char Baudot::decode(uint8_t data, ShiftState& state, bool uos)
  {
    data &= 0x1F;
    if (data == LTRS_CODE) {
      state = ShiftState::Letters;
      return '\0';
    }
    if (data == FIGS_CODE) {
      state = ShiftState::Figures;
      return '\0';
    }
    if (data == SPACE_CODE) {
      if (uos) state = ShiftState::Letters;
      return ' ';
    }
    if (state == ShiftState::Letters) {
      return kLetters[data];
    } else {
      return kFigures[data];
    }
  }
}
