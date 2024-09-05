#ifndef SPEEDCONTROLLER_H
#define SPEEDCONTROLLER_H

#include <QObject>
#include "KalmanFilter.h"

class SpeedController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double speed READ speed WRITE setSpeed NOTIFY speedChanged)

public:
    explicit SpeedController(QObject *parent = nullptr);

    double speed() const;
    void setSpeed(double newSpeed);

signals:
    void speedChanged();

public slots:
    void onFrameReceived(int frameId, const QList<int> &payload); 

private:
    double m_speed;
    KalmanFilter    m_kalmanFilter;
};

#endif // SPEEDCONTROLLER_H
