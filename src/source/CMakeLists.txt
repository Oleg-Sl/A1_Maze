project(Maze)

find_package(Qt6 COMPONENTS Widgets REQUIRED)
if (NOT Qt6_FOUND)
    find_package(Qt5 COMPONENTS Widgets REQUIRED)
endif()

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

target_link_libraries(${PROJECT_NAME} PRIVATE Qt::Widgets)
