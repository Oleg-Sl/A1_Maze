# Указываем минимальную версию CMake
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra -pedantic -Werror)

# Находим все исходные файлы в директории source/model
file(GLOB MODEL_SOURCES "source/model/*.cc")
file(GLOB MODEL_HEADERS "source/model/*.h")

add_subdirectory(tests)
add_subdirectory(source)