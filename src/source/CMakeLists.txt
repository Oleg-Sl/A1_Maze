project(Maze)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)


add_executable(${PROJECT_NAME}
    main.cc
    ${MODEL_SOURCES}
    ${MODEL_HEADERS}
    ${COMMON_SOURCES}
    ${COMMON_HEADERS}
    ${VIEW_SOURCES}
    ${VIEW_HEADERS}
    ${ADAPTER_SOURCES}
    ${ADAPTER_HEADERS}
    ${VIEW_UIS}
)


target_include_directories(${PROJECT_NAME} PUBLIC ${HEADER_DIRS})



target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets)
