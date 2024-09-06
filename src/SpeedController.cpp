#include "SpeedController.h"

SpeedController::SpeedController(QObject *parent)
    : QObject(parent), m_speed(0), m_kalmanFilter(0.1, 0.1, 1.0, 0.0) {}

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

void SpeedController::onFrameReceived(int frameId, const QList<int> &payload)
{
    // Assume that the speed data is contained in the first element of the payload
    if (!payload.isEmpty()) {
        double rawSpeed = static_cast<double>(payload[0]); // Use the first byte as the speed data

        // Apply Kalman filter to smooth the speed data
        double filteredSpeed = m_kalmanFilter.update(rawSpeed);

        // Update the speed using the filtered value
        setSpeed(filteredSpeed); // This will emit speedChanged and update the gauge
    }
}