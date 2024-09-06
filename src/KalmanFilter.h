#ifndef KALMANFILTER_H
#define KALMANFILTER_H

class KalmanFilter
{
public:
    KalmanFilter(float processNoise, float measurementNoise, float estimationError, float initialValue);
    float update(float measurement);

    float getProcessNoise() const;
    float getMeasurementNoise() const;
    float getEstimationError() const;

    void setProcessNoise (float processNoise);
    void setMeasurementNoise(float measurementNoise);
private:
    float processNoise;         // Process noise covariance
    float measurementNoise;     // Measurement noise covariance
    float estimationError;      // Estimation error covariance
    float currentEstimate;      // Current state estimate
    float lastEstimate;         // Last state estimate
    float kalmanGain;           // Kalman gain
};

#endif // KALMANFILTER_H

