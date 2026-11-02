cmake_minimum_required(VERSION 3.10)

project(cw_modem LANGUAGES C CXX)

set(CW_SOURCES
    cw_modem.cpp
    cw_demod.cpp
    cw_multi_demod.cpp
    cw_morse_table.cpp
    cw_gtdemod.cpp
    # GridTracker2 CW decoder DSP core (BSD-3-Clause kissFFT included)
    gt/gt_cwdecoder.c
    gt/kissfft/kiss_fft.c
    gt/kissfft/kiss_fftr.c
)

add_library(cw_modem STATIC ${CW_SOURCES})

target_include_directories(cw_modem PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/gt
    ${CMAKE_CURRENT_SOURCE_DIR}/gt/kissfft
)

target_compile_features(cw_modem PUBLIC cxx_std_17)

# kissFFT is plain C; keep it warning-quiet from the C++ build flags.
if (CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
  set_source_files_properties(
      gt/gt_cwdecoder.c
      gt/kissfft/kiss_fft.c
      gt/kissfft/kiss_fftr.c
      PROPERTIES COMPILE_FLAGS "-Wno-unused-parameter -Wno-sign-compare")
endif()

if (WSJT_GENERATE_DOCS)
    target_sources(cw_modem PRIVATE
        cw_modem.hpp
        cw_demod.hpp
        cw_multi_demod.hpp
        cw_morse_table.hpp
    )
endif()

# Unit tests
enable_testing()
add_subdirectory(test)
