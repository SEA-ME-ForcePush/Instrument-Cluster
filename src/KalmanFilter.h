#ifndef KALMANFILTER_H
#define KALMANFILTER_H

#include <array>
#include <chrono>

/*
class KalmanFilter
{
public:
    KalmanFilter(float processNoise, float measurementNoise, float estimationError, float initialValue);
    float update(float measurement);

private:
    float processNoise;         // Process noise covariance
    float measurementNoise;     // Measurement noise covariance
    float estimationError;      // Estimation error covariance
    float currentEstimate;      // Current state estimate
    float lastEstimate;         // Last state estimate
    float kalmanGain;           // Kalman gain
}; */

class KalmanFilter
{
public:
    KalmanFilter(float processNoise, float measurementNoise, float estimationError, float initialValue);
    float update(float measurement);

    float getSpeed() const;
    float getAcceleration() const;
    float getProcessNoise() const;
    float getMeasurementNoise() const;

    void setProcessNoise (float processNoise);
    void setMeasurementNoise(float measurementNoise);
private:
    std::array<float, 2>                    state;    // [speed, acceleration]
    std::array<std::array<float, 2>, 2>     estimationErrorCovariance; // Error covariance matrix P
    float                                   processNoise;         // Process noise covariance
    float                                   measurementNoise;     // Measurement noise covariance
    float                                   currentEstimate;      // Current state estimate
    std::array<std::array<float, 2>, 2>     processNoiseCovariance;    // Process noise matrix Q
    std::array<float, 2>                    kalmanGain;   // Kalman gain
    std::chrono::steady_clock::time_point   lastUpdateTime; // Timestamp of the last update
};

#endif // KALMANFILTER_H

