#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "CanHandler.h"
#include "SpeedController.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // Instantiate the CAN handler
    CanHandler canHandler("can0"); // Use the appropriate interface name

    // Instantiate the SpeedController
    SpeedController speedController;

    // Connect CanHandler's signal to SpeedController's slot
    QObject::connect(&canHandler, &CanHandler::frameReceived,
                     &speedController, &SpeedController::onFrameReceived);

    // Connect to the CAN device
    if (!canHandler.connectDevice()) {
        qWarning() << "Failed to connect to CAN bus.";
    }

    // Expose CanHandler and SpeedController objects to QML
    engine.rootContext()->setContextProperty("canHandler", &canHandler);
    engine.rootContext()->setContextProperty("speedController", &speedController);
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}

/*
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

*/