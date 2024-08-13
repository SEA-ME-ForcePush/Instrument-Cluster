# Working Note
- GUI is working as a prototype! App runs a test script.  
- You can pass data to the speed gauge with the command: setSpeed(newSpeed);  
- Example: setSpeed(200); passes speed 200 to the gauge and updates display.  

# ToDo
- Add QCanBus with functionality  
- Calculate cm/s from rpm  
- Pass cm/s to the gauge  
- Cross-compile (or alternative) to run Qt App on RPi  

# GUI for the Instrument Cluster
For this project we want to implement a Gauge that is presenting the PiRacer Sped. For this we create a Qt Application that we run on the RaspberryPi. Speed data is obtained from the speed sensor and communicated via CAN Bus.  

# Approach to create the Gauge in GUI
- We use CircularGauge QML  


# Obtaining CAN Bus Data for Gauge representation
- QCanBus?  

# Cross-compiling
Cross-compilation is the process of compiling code on one computer system (called the host) to create executable code that runs on a different system (called the target). This process is useful in embedded systems as the target device has limited resources and cannot host a compiler or development environment, such as microcontrollers or IoT devices.  
- Qtrpi?  

# Ressources (CircularGauge)
https://doc.qt.io/qt-5/styling-gauge.html  
https://doc.qt.io/qt-5/qml-qtquick-controls-styles-circulargaugestyle.html  
https://qthub.com/static/doc/qt5/qtquickextras/qml-qtquick-extras-circulargauge.html#  
https://github.com/zchydem/qt-examples/tree/master  
https://github.com/hadjTahar/Qt-custom-gauge-widget  
https://github.com/Qt-Widgets/Qt-custom-gauge-widget-BEST-dial-meter-ruler-speedometer-LCD-Switch-Toggle-Compass?tab=readme-ov-file  

#Ressources (Qt CAN)
https://www.youtube.com/watch?v=A-34xHva6SM  
https://www.qt.io/blog/qt-can-bus-api-extensions  
https://doc.qt.io/qt-5/qtserialbus-can-example.html  
https://doc.qt.io/qt-5/qcanbus.html?search=QCanBus

# Ressources (Cross-Compile)
https://github.com/SEA-ME-Team4/DES_Instrument-Cluster/blob/main/Documents/CrossCompile.md  
https://www.kampis-elektroecke.de/raspberry-pi/qt/ https://wiki.qt.io/Qtrpi
https://github.com/neuronalmotion/qtrpi
https://wiki.qt.io/Qtrpi
https://www.youtube.com/watch?v=YFFLzhKRFak ( [2023] Cross Compile QT 5.15 for Raspberry Pi 4 )
https://www.youtube.com/watch?v=8kpHgNKPooc ( Cross compilation of Qt6.5.1 for Rpi 64-bit step by step (With Qt Creator)  
https://www.youtube.com/watch?v=TmtN3Rmx9Rk ( Qt for Raspberry Pi - Qt 5.14.2 cross compilation for Raspberry Pi 4 model B - Run Qt on Raspberry )
https://www.youtube.com/watch?v=oWpomXg9yj0 ( Qt6 for Raspberry pi 4 - Cross Compilation with Cmake using Ubuntu VM - Qt6.3.0 Base - Part I )
https://www.youtube.com/watch?v=YYOjdwT5UuQ ( Cross-compile Qt applications for your Raspberry Pi 3 - 1. Install QtRpi from scratch )
https://www.youtube.com/watch?v=eCdPfnR8iI0 ( Qt for Raspberry pi - Qt 5 Cross Compilation and installation ubuntu )
https://github.com/UvinduW/Cross-Compiling-Qt-for-Raspberry-Pi-4
