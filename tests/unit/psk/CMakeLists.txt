add_executable (test_psk_varicode
  test_psk_varicode.cpp
  ${CMAKE_SOURCE_DIR}/lib/psk/psk_varicode.cpp
)
set_target_properties(test_psk_varicode PROPERTIES AUTOMOC FALSE)
target_include_directories (test_psk_varicode PRIVATE ${CMAKE_SOURCE_DIR}/lib/psk ${CMAKE_SOURCE_DIR})
add_test (NAME test_psk_varicode COMMAND test_psk_varicode)
set_tests_properties (test_psk_varicode PROPERTIES
  PASS_REGULAR_EXPRESSION "test_psk_varicode: all checks passed"
)

add_executable (test_psk_modem
  test_psk_modem.cpp
  ${CMAKE_SOURCE_DIR}/lib/psk/psk_varicode.cpp
  ${CMAKE_SOURCE_DIR}/lib/psk/psk_viterbi.cpp
  ${CMAKE_SOURCE_DIR}/lib/psk/psk_modem.cpp
)
set_target_properties(test_psk_modem PROPERTIES AUTOMOC FALSE)
target_include_directories (test_psk_modem PRIVATE ${CMAKE_SOURCE_DIR}/lib/psk ${CMAKE_SOURCE_DIR})
add_test (NAME test_psk_modem COMMAND test_psk_modem)
set_tests_properties (test_psk_modem PROPERTIES
  PASS_REGULAR_EXPRESSION "test_psk_modem: all checks passed"
)
add_executable (test_psk_decoder
  test_psk_decoder.cpp
  ${CMAKE_SOURCE_DIR}/PskDecoder.cpp
  ${CMAKE_SOURCE_DIR}/lib/psk/psk_carrier_detector.cpp
  ${CMAKE_SOURCE_DIR}/lib/psk/psk_browser.cpp
  ${CMAKE_SOURCE_DIR}/lib/psk/psk_modem.cpp
  ${CMAKE_SOURCE_DIR}/lib/psk/psk_varicode.cpp
  ${CMAKE_SOURCE_DIR}/lib/psk/psk_viterbi.cpp
)
set_target_properties (test_psk_decoder PROPERTIES AUTOMOC FALSE)
target_include_directories (test_psk_decoder PRIVATE ${CMAKE_SOURCE_DIR}/lib/psk ${CMAKE_SOURCE_DIR} ${FFTW3_INCLUDE_DIRS})
target_link_libraries (test_psk_decoder PRIVATE Qt5::Core ${FFTW3_LIBRARIES})
add_test (NAME test_psk_decoder COMMAND test_psk_decoder)
set_tests_properties (test_psk_decoder PROPERTIES
  PASS_REGULAR_EXPRESSION "test_psk_decoder: all checks passed"
)

add_executable (test_psk_multichannel
  test_psk_multichannel.cpp
  ${CMAKE_SOURCE_DIR}/PskDecoder.cpp
  ${CMAKE_SOURCE_DIR}/lib/psk/psk_carrier_detector.cpp
  ${CMAKE_SOURCE_DIR}/lib/psk/psk_browser.cpp
  ${CMAKE_SOURCE_DIR}/lib/psk/psk_modem.cpp
  ${CMAKE_SOURCE_DIR}/lib/psk/psk_varicode.cpp
  ${CMAKE_SOURCE_DIR}/lib/psk/psk_viterbi.cpp
)
set_target_properties(test_psk_multichannel PROPERTIES AUTOMOC FALSE)
target_include_directories (test_psk_multichannel PRIVATE ${CMAKE_SOURCE_DIR}/lib/psk ${CMAKE_SOURCE_DIR} ${FFTW3_INCLUDE_DIRS})
target_link_libraries (test_psk_multichannel PRIVATE Qt5::Core ${FFTW3_LIBRARIES})
add_test (NAME test_psk_multichannel COMMAND test_psk_multichannel)
set_tests_properties (test_psk_multichannel PROPERTIES
  PASS_REGULAR_EXPRESSION "test_psk_multichannel: all checks passed"
)
