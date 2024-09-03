#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "CanHandler.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // Create the CanHandler instance using virtual CAN (vcan0)
//    CanHandler canHandler("vcan0");     //virtual CAN you have to setup first
    CanHandler canHandler("can0");      //actual CAN on vehicle

    // Attempt to connect to the CAN bus
    if (!canHandler.connectDevice()) {
        qWarning() << "Failed to connect to CAN bus";
    } else {
        // Expose CanHandler to QML
        engine.rootContext()->setContextProperty("canHandler", &canHandler);
    }

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    // Ensure that the QML was loaded successfully
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
