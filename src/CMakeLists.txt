cmake_minimum_required(VERSION 3.10)

project(MazeAll)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra -pedantic -Werror)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g")

set(BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(ADAPTER_DIR "${BASE_DIR}/source/adapter")
set(COMMON_DIR "${BASE_DIR}/source/common")
set(MODEL_DIR "${BASE_DIR}/source/model")
set(VIEW_DIR "${BASE_DIR}/source/view")

set(HEADER_DIRS ${ADAPTER_DIR} ${COMMON_DIR} ${MODEL_DIR} ${VIEW_DIR})

file(GLOB_RECURSE MODEL_SOURCES "${MODEL_DIR}/*.cc" "${MODEL_DIR}/*.h")
file(GLOB_RECURSE VIEW_SOURCES "${VIEW_DIR}/*.cc" "${VIEW_DIR}/*.h" "${VIEW_DIR}/*.ui")
file(GLOB_RECURSE ADAPTER_SOURCES "${ADAPTER_DIR}/*.cc" "${ADAPTER_DIR}/*.h")
file(GLOB_RECURSE COMMON_SOURCES "${COMMON_DIR}/*.cc" "${COMMON_DIR}/*.h")

add_subdirectory(tests)
add_subdirectory(source)
