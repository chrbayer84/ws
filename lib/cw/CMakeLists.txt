cmake_minimum_required(VERSION 3.10)

project(cw_modem LANGUAGES CXX)

set(CW_SOURCES
    cw_modem.cpp
    cw_demod.cpp
    cw_multi_demod.cpp
    cw_morse_table.cpp
)

add_library(cw_modem STATIC ${CW_SOURCES})

target_include_directories(cw_modem PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
)

target_compile_features(cw_modem PUBLIC cxx_std_17)

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