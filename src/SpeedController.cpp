#include "SpeedController.h"
#include <QtMath>

SpeedController::SpeedController(QObject *parent)
    : QObject(parent), m_speed(0), m_kalmanFilter(0.1, 0.1, 1.0, 0.0), m_kalmanFilterEnabled(true), m_wheelDiameter(0.067) {}

double SpeedController::speed() const
{
    return m_speed;
}

void SpeedController::setSpeed(double newSpeed)
{
    if (qFuzzyCompare(m_speed, newSpeed))
        return;

    m_speed = newSpeed;
    emit speedChanged(); // Notify QML about the change
}

bool SpeedController::isKalmanFilterEnabled() const
{
    return m_kalmanFilterEnabled;
}

void SpeedController::setKalmanFilterEnabled(bool enabled)
{
    if (m_kalmanFilterEnabled != enabled) {
        m_kalmanFilterEnabled = enabled;
        emit kalmanFilterEnabledChanged();
    }
}

void SpeedController::setProcessNoise(float noise)
{
    m_kalmanFilter.setProcessNoise(noise);
}

void SpeedController::setMeasurementNoise(float noise)
{
    m_kalmanFilter.setMeasurementNoise(noise);
}

float SpeedController::wheelDiameter() const
{
    return m_wheelDiameter;
}

void SpeedController::setWheelDiameter(float diameter)
{
    if (!qFuzzyCompare(m_wheelDiameter, diameter)) {
        m_wheelDiameter = diameter;
        emit wheelDiameterChanged();
    }
}

void SpeedController::onFrameReceived(int frameId, const QList<int> &payload)
{
    // Assume that the speed data is contained in the first element of the payload
    if (!payload.isEmpty()) 
    {
        double rawRPM = static_cast<double>(payload[0]); // RPM from CAN data

        // Convert RPM to m/s
        double wheelCircumference = M_PI * m_wheelDiameter * 100; // M_PI is provided by QtMath
        double rawSpeed = (rawRPM / 60.0) * wheelCircumference; // Direct conversion without gear ratio

        // Check if the Kalman filter is enabled
        double filteredSpeed = rawSpeed;
        if (m_kalmanFilterEnabled) {
            // Apply Kalman filter
            filteredSpeed = m_kalmanFilter.update(rawSpeed);
        }

        // Update the speed using the filtered or raw value
        setSpeed(filteredSpeed);    
    }
}