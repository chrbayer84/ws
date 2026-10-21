add_executable (test_tx_start_policy test_tx_start_policy.cpp)
target_include_directories (test_tx_start_policy PRIVATE )
target_link_libraries (test_tx_start_policy Qt5::Test)
add_test (NAME test_tx_start_policy COMMAND test_tx_start_policy)
set_tests_properties (test_tx_start_policy PROPERTIES
  PASS_REGULAR_EXPRESSION "Totals: .* passed, 0 failed"
)
