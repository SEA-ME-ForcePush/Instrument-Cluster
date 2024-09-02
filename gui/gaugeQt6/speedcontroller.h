#ifndef SPEEDCONTROLLER_H
#define SPEEDCONTROLLER_H

#include <QObject>
#include <QTimer>
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
    void updateSpeed();  // Slot to update speed periodically
    void updateSpeedWithFilter(); // Slot to update speed periodically with Kalman filter

private:
    double m_speed;
    QTimer m_timer;  // Timer to trigger updates
    KalmanFilter m_kalmanFilter; 
};

#endif // SPEEDCONTROLLER_H
