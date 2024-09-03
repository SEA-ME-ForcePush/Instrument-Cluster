#ifndef CANHANDLER_H
#define CANHANDLER_H

#include <QObject>
#include <QCanBusDevice>
#include <QCanBusFrame>

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
    void frameReceived(uint frameId, QList<int> payload);


private slots:
    void processFrames();

private:
    QCanBusDevice *canDevice;
};

#endif // CANHANDLER_H

