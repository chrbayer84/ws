# CMake generated Testfile for 
# Source directory: /home/christian/temp/wsjtx/build/ws/tests
# Build directory: /home/christian/temp/wsjtx/build/ws/build/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_qt_helpers "test_qt_helpers")
set_tests_properties(test_qt_helpers PROPERTIES  _BACKTRACE_TRIPLES "/home/christian/temp/wsjtx/build/ws/tests/CMakeLists.txt;23;add_test;/home/christian/temp/wsjtx/build/ws/tests/CMakeLists.txt;0;")
add_test(test_tx_inhibit_logic "test_tx_inhibit_logic")
set_tests_properties(test_tx_inhibit_logic PROPERTIES  _BACKTRACE_TRIPLES "/home/christian/temp/wsjtx/build/ws/tests/CMakeLists.txt;27;add_test;/home/christian/temp/wsjtx/build/ws/tests/CMakeLists.txt;0;")
add_test(test_tx_inhibit_gate "test_tx_inhibit_gate")
set_tests_properties(test_tx_inhibit_gate PROPERTIES  _BACKTRACE_TRIPLES "/home/christian/temp/wsjtx/build/ws/tests/CMakeLists.txt;34;add_test;/home/christian/temp/wsjtx/build/ws/tests/CMakeLists.txt;0;")
subdirs("unit/rtty")
subdirs("unit/common")
