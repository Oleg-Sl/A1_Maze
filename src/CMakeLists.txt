cmake_minimum_required(VERSION 3.10)

project(MazeAll)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra -pedantic -Werror)

if(CMAKE_BUILD_TYPE MATCHES "^Debug")
  add_compile_options(-g -O0)
else()
  add_compile_options(-O3 -DNDEBUG)
endif()

set(BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(ADAPTER_DIR "${BASE_DIR}/source/adapter")
set(COMMON_DIR "${BASE_DIR}/source/common")
set(MODEL_DIR "${BASE_DIR}/source/model")
set(VIEW_DIR "${BASE_DIR}/source/view")
set(ASSETS_DIR "${BASE_DIR}/assets")

set(HEADER_DIRS "${BASE_DIR}/source")

file(GLOB_RECURSE MODEL_SOURCES "${MODEL_DIR}/*.cc" "${MODEL_DIR}/*.h")
file(GLOB_RECURSE VIEW_SOURCES "${VIEW_DIR}/*.cc" "${VIEW_DIR}/*.h" "${VIEW_DIR}/*.ui")
file(GLOB_RECURSE ADAPTER_SOURCES "${ADAPTER_DIR}/*.cc" "${ADAPTER_DIR}/*.h")
file(GLOB_RECURSE COMMON_SOURCES "${COMMON_DIR}/*.cc" "${COMMON_DIR}/*.h")
file(GLOB_RECURSE ALL_SOURCES "${BASE_DIR}/*.cc" "${BASE_DIR}/*.h")

add_custom_target(format
    COMMAND clang-format --style=Google -i --verbose ${ALL_SOURCES}
)

add_custom_target(stylecheck
    COMMAND clang-format --style=Google -n --verbose ${ALL_SOURCES}
)

add_custom_target(cppcheck
    COMMAND cppcheck --enable=all --suppress=missingInclude ${ALL_SOURCES}
)

add_subdirectory(source)

enable_testing()
add_subdirectory(tests)
