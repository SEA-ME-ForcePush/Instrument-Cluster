#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "CanHandler.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // Instantiate the CAN handler
    CanHandler canHandler("can0"); // Use the appropriate interface name

    // Connect to the CAN device
    if (!canHandler.connectDevice()) {
        qWarning() << "Failed to connect to CAN bus.";
    }

    // Expose CanHandler object to QML
    engine.rootContext()->setContextProperty("canHandler", &canHandler);
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}
