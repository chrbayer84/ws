//==============================================================================
// rtty_baudot.hpp:
//
// Baudot (ITA2) character coding definitions and state machine for RTTY
//
// This file is part of WSJT-X.
//==============================================================================

#ifndef RTTY_BAUDOT_HPP
#define RTTY_BAUDOT_HPP

#include <cstdint>
#include <string>

namespace Rtty
{
  enum class ShiftState : uint8_t
  {
    Letters = 0,
    Figures = 1
  };

  struct EncodedBaudot
  {
    bool valid {false};
    ShiftState requiredShift {ShiftState::Letters};
    uint8_t code {0};
  };

  class Baudot
  {
  public:
    static constexpr uint8_t LTRS_CODE = 0x1F;
    static constexpr uint8_t FIGS_CODE = 0x1B;
    static constexpr uint8_t SPACE_CODE = 0x04;
    static constexpr uint8_t CR_CODE = 0x08;
    static constexpr uint8_t LF_CODE = 0x02;
    static constexpr uint8_t BLANK_CODE = 0x00;

    static EncodedBaudot encode(char c);
    static char decode(uint8_t data, ShiftState& state, bool uos = true);

    static char letterChar(uint8_t index);
    static char figureChar(uint8_t index);
  };
}

#endif // RTTY_BAUDOT_HPP
