project(Maze)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

add_executable(${PROJECT_NAME}
    view/main.cc
    view/mainwindow.cc
    view/mainwindow.h
    view/mainwindow.ui
    ${MODEL_SOURCES}
)

target_include_directories(${PROJECT_NAME} PUBLIC "model/")

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets)
