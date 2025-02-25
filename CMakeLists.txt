# cmake_minimum_required(VERSION 3.5)

# project(rtsp_player VERSION 0.1 LANGUAGES CXX)

# set(CMAKE_INCLUDE_CURRENT_DIR ON)
# set(CMAKE_AUTOUIC ON)
# set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTORCC ON)

# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find_package(Qt5 COMPONENTS Widgets Multimedia MultimediaWidgets REQUIRED)

# set(PROJECT_SOURCES
#     main.cpp
#     mainwindow.cpp
#     mainwindow.h
# )

# add_executable(rtsp_player
#     ${PROJECT_SOURCES}
# )

# target_link_libraries(rtsp_player PRIVATE Qt5::Widgets Qt5::Multimedia Qt5::MultimediaWidgets)



cmake_minimum_required(VERSION 3.5)

project(rtsp_player VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets Multimedia MultimediaWidgets WebEngineWidgets REQUIRED)

# Include Qt Resource file
qt5_add_resources(APP_RESOURCES resources.qrc)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
)

add_executable(rtsp_player
    ${PROJECT_SOURCES}
    ${APP_RESOURCES}
)

target_link_libraries(rtsp_player PRIVATE Qt5::Widgets Qt5::Multimedia Qt5::MultimediaWidgets Qt5::WebEngineWidgets)
