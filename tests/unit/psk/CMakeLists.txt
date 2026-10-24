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