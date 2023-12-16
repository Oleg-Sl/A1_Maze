project(Maze)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

add_executable(${PROJECT_NAME}
    main.cc
    view/mainwindow.cc
    view/mainwindow.h
    view/qgraphicscellitem.h
    view/qgraphicscellitem.cc
    view/mainwindow.ui
    view/mazecell.h
    adapter/adapter.cc
    ${MODEL_SOURCES}
)

target_include_directories(${PROJECT_NAME} PUBLIC "model/" "view/" "adapter/")

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets)
