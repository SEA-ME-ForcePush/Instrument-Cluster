#ifndef KALMANFILTER_H
#define KALMANFILTER_H

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
};

#endif // KALMANFILTER_H

