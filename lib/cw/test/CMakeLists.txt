cmake_minimum_required(VERSION 3.10)

project(cw_modem_tests LANGUAGES CXX)

enable_testing()

find_package(FFTW3 REQUIRED)

add_executable(test_cw_morse_table test_cw_morse_table.cpp)
target_link_libraries(test_cw_morse_table PRIVATE cw_modem ${FFTW3_LIBRARIES})
add_test(NAME test_cw_morse_table COMMAND test_cw_morse_table)

add_executable(test_cw_modem test_cw_modem.cpp)
target_link_libraries(test_cw_modem PRIVATE cw_modem ${FFTW3_LIBRARIES})
add_test(NAME test_cw_modem COMMAND test_cw_modem)

add_executable(test_cw_demod test_cw_demod.cpp)
target_link_libraries(test_cw_demod PRIVATE cw_modem ${FFTW3_LIBRARIES})
add_test(NAME test_cw_demod COMMAND test_cw_demod)

add_executable(test_cw_fldigi_demod test_cw_fldigi_demod.cpp)
target_link_libraries(test_cw_fldigi_demod PRIVATE cw_modem ${FFTW3_LIBRARIES})
add_test(NAME test_cw_fldigi_demod COMMAND test_cw_fldigi_demod)
set_tests_properties (test_cw_fldigi_demod PROPERTIES
  PASS_REGULAR_EXPRESSION "test_cw_fldigi_demod: all checks passed"
)

add_executable(test_cw_gt_demod test_cw_gt_demod.cpp)
target_link_libraries(test_cw_gt_demod PRIVATE cw_modem ${FFTW3_LIBRARIES})
add_test(NAME test_cw_gt_demod COMMAND test_cw_gt_demod)
set_tests_properties (test_cw_gt_demod PROPERTIES
  PASS_REGULAR_EXPRESSION "test_cw_gt_demod: all checks passed"
)

# New: Full alphabet (A-Z, 0-9) decode test at multiple WPM speeds
add_executable(test_cw_alphabet_full test_cw_alphabet_full.cpp)
target_link_libraries(test_cw_alphabet_full PRIVATE cw_modem ${FFTW3_LIBRARIES})
add_test(NAME test_cw_alphabet_full COMMAND test_cw_alphabet_full)
set_tests_properties (test_cw_alphabet_full PROPERTIES
  PASS_REGULAR_EXPRESSION "test_cw_alphabet_full: all checks passed"
)

if (TARGET deepcw)
  add_executable(test_deepcw test_deepcw.cpp)
  target_link_libraries(test_deepcw PRIVATE cw_modem deepcw ${FFTW3_LIBRARIES})
  target_compile_definitions(test_deepcw PRIVATE
    DEEPCW_MODEL_DIR="${CMAKE_SOURCE_DIR}/lib/cw/deepcw/models")
  add_test(NAME test_deepcw COMMAND test_deepcw)
  set_tests_properties (test_deepcw PROPERTIES
    PASS_REGULAR_EXPRESSION "test_deepcw: all checks passed"
  )
endif ()
