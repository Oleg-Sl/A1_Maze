project(Maze)


if (NOT Qt6_FOUND)
    find_package(Qt5 COMPONENTS Widgets REQUIRED)
else()
    find_package(Qt6 COMPONENTS Widgets REQUIRED)
endif()

set(CMAKE_INCLUDE_CURRENT_DIR ON)


set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)


add_executable(${PROJECT_NAME}
    main.cc
    ${MODEL_SOURCES}
    ${CAVE_SOURCES}
    ${COMMON_SOURCES}
    ${VIEW_SOURCES}
    ${ADAPTER_SOURCES}
    ${VIEW_UIS}
)


target_include_directories(${PROJECT_NAME} PUBLIC ${HEADER_DIRS})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt::Widgets)
