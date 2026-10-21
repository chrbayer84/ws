# CMake generated Testfile for 
# Source directory: /home/christian/temp/wsjtx/build/ws/tests/unit/rtty
# Build directory: /home/christian/temp/wsjtx/build/ws/build/tests/unit/rtty
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_rtty_baudot "/home/christian/temp/wsjtx/build/ws/build/tests/unit/rtty/test_rtty_baudot")
set_tests_properties(test_rtty_baudot PROPERTIES  PASS_REGULAR_EXPRESSION "test_rtty_baudot: all checks passed" _BACKTRACE_TRIPLES "/home/christian/temp/wsjtx/build/ws/tests/unit/rtty/CMakeLists.txt;6;add_test;/home/christian/temp/wsjtx/build/ws/tests/unit/rtty/CMakeLists.txt;0;")
add_test(test_rtty_modem "/home/christian/temp/wsjtx/build/ws/build/tests/unit/rtty/test_rtty_modem")
set_tests_properties(test_rtty_modem PROPERTIES  PASS_REGULAR_EXPRESSION "test_rtty_modem: all checks passed" _BACKTRACE_TRIPLES "/home/christian/temp/wsjtx/build/ws/tests/unit/rtty/CMakeLists.txt;21;add_test;/home/christian/temp/wsjtx/build/ws/tests/unit/rtty/CMakeLists.txt;0;")
