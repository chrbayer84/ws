add_executable (test_callsign_reporter
  test_callsign_reporter.cpp
  ${CMAKE_SOURCE_DIR}/lib/conv/ConversationalCallsignReporter.cpp
  ${CMAKE_SOURCE_DIR}/Radio.cpp
)
set_target_properties (test_callsign_reporter PROPERTIES AUTOMOC FALSE)
target_include_directories (test_callsign_reporter PRIVATE ${CMAKE_SOURCE_DIR})
target_link_libraries (test_callsign_reporter PRIVATE Qt5::Core)
add_test (NAME test_callsign_reporter COMMAND test_callsign_reporter)
set_tests_properties (test_callsign_reporter PROPERTIES
  PASS_REGULAR_EXPRESSION "test_callsign_reporter: all checks passed"
)
