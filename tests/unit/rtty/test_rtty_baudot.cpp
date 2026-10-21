// test_rtty_baudot.cpp:
//
// Unit tests for RTTY Baudot ITA2 encoding and decoding
//
// This file is part of WSJT-X.
//==============================================================================

#include "lib/rtty/rtty_baudot.hpp"
#include <iostream>
#include <cassert>

void testBaudotEncodingAndDecoding()
{
  std::cout << "Running testBaudotEncodingAndDecoding..." << std::endl;

  // Letters
  auto encE = Rtty::Baudot::encode('E');
  assert(encE.valid);
  assert(encE.requiredShift == Rtty::ShiftState::Letters);
  assert(encE.code == 0x01);
  (void)encE;

  // Figures
  auto enc3 = Rtty::Baudot::encode('3');
  assert(enc3.valid);
  assert(enc3.requiredShift == Rtty::ShiftState::Figures);
  assert(enc3.code == 0x01);
  (void)enc3;

  // Space
  auto encSpace = Rtty::Baudot::encode(' ');
  assert(encSpace.valid);
  assert(encSpace.requiredShift == Rtty::ShiftState::Letters);
  assert(encSpace.code == Rtty::Baudot::SPACE_CODE);
  (void)encSpace;

  // Case shifting state-machine decoding
  Rtty::ShiftState rxState = Rtty::ShiftState::Letters;
  
  // Decodes LETTERS E
  char decE = Rtty::Baudot::decode(0x01, rxState, true);
  assert(decE == 'E');
  assert(rxState == Rtty::ShiftState::Letters);
  (void)decE;

  // Decodes FIGURES shift
  char decShift = Rtty::Baudot::decode(Rtty::Baudot::FIGS_CODE, rxState, true);
  assert(decShift == '\0');
  assert(rxState == Rtty::ShiftState::Figures);
  (void)decShift;

  // Decodes 3 under FIGURES shift
  char dec3 = Rtty::Baudot::decode(0x01, rxState, true);
  assert(dec3 == '3');
  assert(rxState == Rtty::ShiftState::Figures);
  (void)dec3;

  // Decodes SPACE under UOS (Unshift On Space)
  char decSpace = Rtty::Baudot::decode(Rtty::Baudot::SPACE_CODE, rxState, true);
  assert(decSpace == ' ');
  assert(rxState == Rtty::ShiftState::Letters); // UOS resets to Letters
  (void)decSpace;

  std::cout << "test_rtty_baudot: all checks passed" << std::endl;
}

int main()
{
  testBaudotEncodingAndDecoding();
  return 0;
}
