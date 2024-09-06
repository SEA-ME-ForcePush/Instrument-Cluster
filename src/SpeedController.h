#ifndef SPEEDCONTROLLER_H
#define SPEEDCONTROLLER_H

#include <QObject>
#include "KalmanFilter.h"

class SpeedController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double speed READ speed WRITE setSpeed NOTIFY speedChanged)
    Q_PROPERTY(bool kalmanFilterEnabled READ isKalmanFilterEnabled WRITE setKalmanFilterEnabled NOTIFY kalmanFilterEnabledChanged)
    Q_PROPERTY(float wheelDiameter READ wheelDiameter WRITE setWheelDiameter NOTIFY wheelDiameterChanged) // Updated

public:
    explicit SpeedController(QObject *parent = nullptr);

    double speed() const;
    void setSpeed(double newSpeed);
    bool isKalmanFilterEnabled() const;
    void setKalmanFilterEnabled(bool enabled);
    
    Q_INVOKABLE void setProcessNoise(float noise);
    Q_INVOKABLE void setMeasurementNoise(float noise);

    float wheelDiameter() const;
    void setWheelDiameter(float diameter);

signals:
    void speedChanged();
    void kalmanFilterEnabledChanged();
    void wheelDiameterChanged();

public slots:
    void onFrameReceived(int frameId, const QList<int> &payload); 

private:
    double m_speed;
    bool m_kalmanFilterEnabled;
    KalmanFilter    m_kalmanFilter;
    float m_wheelDiameter;
};

#endif // SPEEDCONTROLLER_H
