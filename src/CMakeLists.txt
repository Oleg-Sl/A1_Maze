# Указываем минимальную версию CMake
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra -pedantic -Werror)

# Находим все исходные файлы в директориях
file(GLOB MODEL_SOURCES "source/model/*.cc")
file(GLOB MODEL_HEADERS "source/model/*.h")

file(GLOB VIEW_SOURCES "source/view/*.cc")
file(GLOB VIEW_HEADERS "source/view/*.h")
file(GLOB VIEW_UIS "source/view/*.ui")

file(GLOB ADAPTER_SOURCES "source/adapter/*.cc")
file(GLOB ADAPTER_HEADERS "source/adapter/*.h")

file(GLOB COMMON_SOURCES "source/common/*.cc")
file(GLOB COMMON_HEADERS "source/common/*.h")

set(HEADER_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/source/adapter/" "${CMAKE_CURRENT_SOURCE_DIR}/source/common/" "${CMAKE_CURRENT_SOURCE_DIR}/source/model/" "${CMAKE_CURRENT_SOURCE_DIR}/source/view/")

add_subdirectory(tests)
add_subdirectory(source)