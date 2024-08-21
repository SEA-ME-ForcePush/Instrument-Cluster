#include "canhandler.h"
#include <QCanBus>
#include <QDebug>
#include <QList>

CanHandler::CanHandler(const QString &interfaceName, QObject *parent)
    : QObject(parent), canDevice(nullptr)
{
    QString errorString;
    canDevice = QCanBus::instance()->createDevice("socketcan", interfaceName, &errorString);

    if (!canDevice) {
        qWarning() << "Failed to create CAN device:" << errorString;
    }
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
            qDebug() << "Connected to CAN bus.";
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

        // Convert QByteArray to QList<int>
        QList<int> payloadList;
        QByteArray payload = frame.payload();
        for (char byte : payload) {
            payloadList.append(static_cast<int>(static_cast<unsigned char>(byte)));
        }

        emit frameReceived(frame.frameId(), payloadList);
    }
}
