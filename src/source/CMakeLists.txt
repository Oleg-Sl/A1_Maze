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
    common/cell.h
    common/point2d.h
    adapter/adapter.cc
    adapter/adapter.h
    model/mazesolution.h
    model/mazesolution.cc
    ${MODEL_SOURCES}
)

target_include_directories(${PROJECT_NAME} PUBLIC "model/" "view/" "adapter/" "common/")

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets)
