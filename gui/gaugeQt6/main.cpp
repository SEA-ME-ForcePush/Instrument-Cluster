#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "speedcontroller.h"

int main(int argc, char *argv[])
{
//    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);  //only for Qt5 needed
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    SpeedController speedController;
    speedController.setSpeed(50); // Set the initial speed to a value other than 0

    engine.rootContext()->setContextProperty("speedController", &speedController);
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}
