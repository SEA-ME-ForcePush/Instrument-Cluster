#include "CanHandler.h"
#include "KalmanFilter.h"
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

    // Initialize KalmanFilter with chosen parameters
    kalmanFilter = new KalmanFilter(1.0, 1.0, 0.1, 0.0);  // Example initialization values
}

CanHandler::~CanHandler()
{
    if (canDevice) {
        disconnectDevice();
        delete canDevice;
    }
    delete kalmanFilter;  // Clean up KalmanFilter
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
            // Use the Kalman filter to process each byte of the payload
            int filteredValue = static_cast<int>(kalmanFilter->update(static_cast<float>(static_cast<unsigned char>(byte))));
            payloadList.append(filteredValue);
        }

        emit frameReceived(frame.frameId(), payloadList);
    }
}

