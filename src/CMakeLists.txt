cmake_minimum_required(VERSION 3.10)

project(MazeAll)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra -pedantic -Werror)

if(CMAKE_BUILD_TYPE MATCHES "^Debug")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g")
else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -DNDEBUG")
endif()

set(BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(ADAPTER_DIR "${BASE_DIR}/source/adapter")
set(COMMON_DIR "${BASE_DIR}/source/common")
set(MODEL_DIR "${BASE_DIR}/source/model")
set(VIEW_DIR "${BASE_DIR}/source/view")
set(ASSETS_DIR "${BASE_DIR}/assets")

set(CAVE_DIR "${BASE_DIR}/source/model/cave")

set(HEADER_DIRS ${ADAPTER_DIR} ${COMMON_DIR} ${MODEL_DIR} ${VIEW_DIR})

file(GLOB_RECURSE MODEL_SOURCES "${MODEL_DIR}/*.cc" "${MODEL_DIR}/*.h")
file(GLOB_RECURSE VIEW_SOURCES "${VIEW_DIR}/*.cc" "${VIEW_DIR}/*.h" "${VIEW_DIR}/*.ui")
file(GLOB_RECURSE ADAPTER_SOURCES "${ADAPTER_DIR}/*.cc" "${ADAPTER_DIR}/*.h")
file(GLOB_RECURSE COMMON_SOURCES "${COMMON_DIR}/*.cc" "${COMMON_DIR}/*.h")

file(GLOB_RECURSE COMMON_SOURCES "${CAVE_DIR}/*.cc" "${CAVE_DIR}/*.h")


add_subdirectory(source)

enable_testing()
#add_subdirectorye(tests)
