#include "speedcontroller.h"

SpeedController::SpeedController(QObject *parent)
    : QObject(parent), m_speed(0)
{
    // Set up the timer to call updateSpeed every 100 ms (10 times per second)
    connect(&m_timer, &QTimer::timeout, this, &SpeedController::updateSpeed);
    m_timer.start(100); // 100 ms interval
}

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

void SpeedController::updateSpeed()
{
    // Update the speed value continuously
    double newSpeed = m_speed + 1; // For example, increment speed by 1 each time
    if (newSpeed > 250) {
        newSpeed = 0; // Reset to 0 if it exceeds the maximum value
    }
    setSpeed(newSpeed); // This will emit speedChanged and update the gauge
}
