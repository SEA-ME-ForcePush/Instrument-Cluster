cmake_minimum_required(VERSION 3.14)

project(GaugeApp VERSION 1.0 LANGUAGES CXX)

# Enable automatic Qt processing
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required Qt modules
find_package(Qt6 COMPONENTS Core Gui Qml Quick QuickControls2 Network SerialBus REQUIRED)

# Add the executable and include all necessary files
add_executable(InstrumentCluster
    src/main.cpp
    src/qml.qrc
    src/CanHandler.h
    src/CanHandler.cpp  # Ensure consistent naming for the source file
    src/KalmanFilter.cpp
    src/KalmanFilter.h
)

# Link necessary Qt libraries
target_link_libraries(InstrumentCluster
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
    Qt6::QuickControls2
    Qt6::Network
    Qt6::SerialBus
)

# Installation rules
install(TARGETS InstrumentCluster
    BUNDLE DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}  # Ensure CMAKE_INSTALL_BINDIR is defined or adjust as needed
)
