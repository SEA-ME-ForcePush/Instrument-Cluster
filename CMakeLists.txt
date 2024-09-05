cmake_minimum_required(VERSION 3.14)

project(GaugeApp VERSION 1.0 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ensure Qt SerialBus is found
find_package(Qt5 COMPONENTS Core Gui Qml Quick SerialBus REQUIRED)

add_executable(InstrumentCluster
    src/main.cpp
    src/qml.qrc
    src/CanHandler.cpp
    src/CanHandler.h
    src/KalmanFilter.cpp   # Add KalmanFilter source file
    src/KalmanFilter.h     # Add KalmanFilter header file
    src/SpeedController.cpp
    src/SpeedController.h
)

# Link SerialBus to your application
target_link_libraries(InstrumentCluster
    Qt5::Core
    Qt5::Gui
    Qt5::Qml
    Qt5::Quick
    Qt5::SerialBus
)

install(TARGETS InstrumentCluster
    BUNDLE DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

