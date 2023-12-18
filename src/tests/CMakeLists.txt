project(MazeTests)

file(GLOB TEST_SOURCES "*.cc")

# Добавляем исполняемый файл с именем проекта и используемые исходные файлы, хедеры нужны для подсветки синтаксиса
add_executable(${PROJECT_NAME} ${MODEL_SOURCES} ${TEST_SOURCES} ${COMMON_HEADERS})

# Включаем папку с заголовочными файлами для проекта, чтобы не писать относительные пути
target_include_directories(${PROJECT_NAME} PUBLIC ${HEADER_DIRS})

# Линкуем Google Test с проектом
find_package(GTest REQUIRED)
target_link_libraries(${PROJECT_NAME} GTest::GTest GTest::Main)

# Добавляем модуль тестов в cmake
include(GoogleTest)
# Для запуска тестов через ctest
gtest_discover_tests(${PROJECT_NAME})
