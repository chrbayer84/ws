cmake_minimum_required(VERSION 3.10)

option(WSJT_DEEPCW "Build the DeepCW neural CW decoder" ON)
if (NOT WSJT_DEEPCW)
  return()
endif ()

find_package(FFTW3 COMPONENTS single REQUIRED)

# ONNX Runtime is a hard dependency when DeepCW is enabled. We vendor the C API
# header (pinned to ORT_API_VERSION 23) and link the runtime library.
set(_ort_root ${ONNXRUNTIME_ROOT} $ENV{ONNXRUNTIME_ROOT})

find_library(ONNXRUNTIME_LIBRARY
  NAMES onnxruntime
  HINTS ${_ort_root} /usr /usr/local
  PATH_SUFFIXES lib lib64 lib/x86_64-linux-gnu)
if (NOT ONNXRUNTIME_LIBRARY)
  file(GLOB _ort_candidates
    "${_ort_root}/lib/libonnxruntime.so*"
    "/usr/lib/*/libonnxruntime.so*"
    "/usr/lib/libonnxruntime.so*"
    "/usr/local/lib/libonnxruntime.so*")
  if (_ort_candidates)
    list(SORT _ort_candidates)
    list(GET _ort_candidates 0 ONNXRUNTIME_LIBRARY)
  endif ()
endif ()
if (NOT ONNXRUNTIME_LIBRARY)
  message(FATAL_ERROR
    "DeepCW: ONNX Runtime not found. Install libonnxruntime (>= 1.23) "
    "or set ONNXRUNTIME_ROOT, or configure with -DWSJT_DEEPCW=OFF.")
endif ()

message(STATUS "DeepCW: using ONNX Runtime ${ONNXRUNTIME_LIBRARY}")

add_library(deepcw STATIC
  deepcw_types.cpp
  deepcw_stft.cpp
  deepcw_spectrogram.cpp
  deepcw_ctc.cpp
  deepcw_stitch.cpp
  deepcw_session.cpp
  deepcw_decoder.cpp
)

target_include_directories(deepcw PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${FFTW3_INCLUDE_DIRS}
)

target_link_libraries(deepcw PUBLIC
  ${FFTW3_LIBRARIES}
  ${ONNXRUNTIME_LIBRARY}
  ${CMAKE_DL_LIBS}
)

target_compile_features(deepcw PUBLIC cxx_std_17)

# Development runs from the build tree find the models next to the executable;
# installed builds find them under share/wsjtx/models/deepcw.
set(DEEPCW_MODEL_FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/models/model.onnx
  ${CMAKE_CURRENT_SOURCE_DIR}/models/model.onnx.json
  ${CMAKE_CURRENT_SOURCE_DIR}/models/model_narrow.onnx
  ${CMAKE_CURRENT_SOURCE_DIR}/models/model_narrow.onnx.json
)
file(COPY ${DEEPCW_MODEL_FILES}
     DESTINATION "${CMAKE_BINARY_DIR}/models/deepcw")
install(FILES ${DEEPCW_MODEL_FILES}
        DESTINATION share/wsjtx/models/deepcw)
