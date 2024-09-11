#ifndef CANHANDLER_H
#define CANHANDLER_H

#include <QObject>
#include <QCanBusDevice>
#include <QCanBusFrame>
#include "KalmanFilter.h"  // Include KalmanFilter header

class CanHandler : public QObject
{
    Q_OBJECT

public:
    explicit CanHandler(const QString &interfaceName, QObject *parent = nullptr);
    ~CanHandler();

    bool connectDevice();
    void disconnectDevice();
    void sendFrame(const QCanBusFrame &frame);

signals:
    void frameReceived(uint frameId, float speed);

private slots:
    void processFrames();

private:
    QCanBusDevice *canDevice;
    KalmanFilter *kalmanFilter;  // Add KalmanFilter as a member
};

#endif // CANHANDLER_H

