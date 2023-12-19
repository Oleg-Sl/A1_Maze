project(MazeTests)

enable_testing()
find_package(GTest REQUIRED)
include(GoogleTest)

file(GLOB TEST_SOURCES "*.cc")

add_executable(${PROJECT_NAME} ${MODEL_SOURCES} ${TEST_SOURCES} ${COMMON_HEADERS})

target_include_directories(${PROJECT_NAME} PUBLIC ${HEADER_DIRS})

target_link_libraries(${PROJECT_NAME} GTest::GTest GTest::Main)

gtest_discover_tests(${PROJECT_NAME})
