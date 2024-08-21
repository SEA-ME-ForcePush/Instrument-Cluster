cmake_minimum_required(VERSION 3.14)

project(GaugeApp VERSION 1.0 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core Gui Qml Quick REQUIRED)

add_executable(GaugeApp
    main.cpp
    speedcontroller.cpp
    qml.qrc
    speedcontroller.h
)

target_link_libraries(GaugeApp
    Qt5::Core
    Qt5::Gui
    Qt5::Qml
    Qt5::Quick
)

install(TARGETS GaugeApp
    BUNDLE DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
