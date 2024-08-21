#include "CanHandler.h"
#include <QCanBus>
#include <QDebug>

CanHandler::CanHandler(const QString &interfaceName, QObject *parent)
    : QObject(parent), canDevice(nullptr)
{
    canDevice = QCanBus::instance()->createDevice("socketcan", interfaceName, this);
}

CanHandler::~CanHandler()
{
    if (canDevice) {
        disconnectDevice();
        delete canDevice;
    }
}

bool CanHandler::connectDevice()
{
    if (canDevice) {
        // Connect the framesReceived signal to processFrames slot
        connect(canDevice, &QCanBusDevice::framesReceived, this, &CanHandler::processFrames);

        // Try to connect to the CAN device
        if (canDevice->connectDevice()) {
            qDebug() << "Connected to CAN bus on" << canDevice->interfaceName();
            return true;
        } else {
            qWarning() << "Failed to connect to CAN bus:" << canDevice->errorString();
        }
    }
    return false;
}

void CanHandler::disconnectDevice()
{
    if (canDevice) {
        canDevice->disconnectDevice();
        qDebug() << "Disconnected from CAN bus";
    }
}

void CanHandler::sendFrame(const QCanBusFrame &frame)
{
    if (canDevice && canDevice->writeFrame(frame)) {
        qDebug() << "Frame sent:" << frame.toString();
    } else {
        qWarning() << "Failed to send frame:" << canDevice->errorString();
    }
}

void CanHandler::processFrames()
{
    while (canDevice->framesAvailable()) {
        QCanBusFrame frame = canDevice->readFrame();
        qDebug() << "Received CAN frame:" << frame.toString();
        emit frameReceived(frame); // Emit a signal if needed
    }
}

