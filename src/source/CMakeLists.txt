project(Maze)


find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

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

target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
