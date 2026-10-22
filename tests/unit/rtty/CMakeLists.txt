add_executable (test_rtty_baudot
  test_rtty_baudot.cpp
  ${CMAKE_SOURCE_DIR}/lib/rtty/rtty_baudot.cpp
)
target_include_directories (test_rtty_baudot PRIVATE ${CMAKE_SOURCE_DIR})
add_test (NAME test_rtty_baudot COMMAND test_rtty_baudot)
set_tests_properties (test_rtty_baudot PROPERTIES
  PASS_REGULAR_EXPRESSION "test_rtty_baudot: all checks passed"
)

add_executable (test_rtty_modem
  test_rtty_modem.cpp
  ${CMAKE_SOURCE_DIR}/lib/rtty/rtty_filters.cpp
  ${CMAKE_SOURCE_DIR}/lib/rtty/rtty_fftfilt.cpp
  ${CMAKE_SOURCE_DIR}/lib/rtty/rtty_baudot.cpp
  ${CMAKE_SOURCE_DIR}/lib/rtty/rtty_shaper.cpp
  ${CMAKE_SOURCE_DIR}/lib/rtty/rtty_modem.cpp
)
target_include_directories (test_rtty_modem PRIVATE ${CMAKE_SOURCE_DIR} ${FFTW3_INCLUDE_DIRS})
target_link_libraries (test_rtty_modem PRIVATE ${FFTW3_LIBRARIES})
add_test (NAME test_rtty_modem COMMAND test_rtty_modem)
set_tests_properties (test_rtty_modem PROPERTIES
  PASS_REGULAR_EXPRESSION "test_rtty_modem: all checks passed"
)
