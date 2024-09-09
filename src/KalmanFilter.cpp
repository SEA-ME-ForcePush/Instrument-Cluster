#include "KalmanFilter.h"

KalmanFilter::KalmanFilter(float processNoise, float measurementNoise, float estimationError, float initialValue)
    : processNoise(processNoise), 
      measurementNoise(measurementNoise),
      estimationErrorCovariance({{{estimationError, 0.0f}, {0.0f, estimationError}}}), // Correct initialization
      processNoiseCovariance({{{processNoise, 0.0f}, {0.0f, processNoise}}}), // Correct initialization
      kalmanGain({0.0f, 0.0f}),
      state({initialValue, 0.0f}) // Initial state: speed = initialValue, acceleration = 0
{
}

/*Getters*/
float KalmanFilter::getProcessNoise() const
{
    return (this->processNoise);
}

float KalmanFilter::getMeasurementNoise() const
{
    return (this->measurementNoise);
}

float KalmanFilter::getSpeed() const 
{
    return state[0];
}

float KalmanFilter::getAcceleration() const 
{
    return state[1];
}


/*Setters*/
void KalmanFilter::setProcessNoise(float processNoise)
{
    this->processNoise = processNoise;
}

void KalmanFilter::setMeasurementNoise(float measurementNoise)
{
    this->measurementNoise = measurementNoise;
}

float KalmanFilter::update(float measurement, float deltaTime)
{
    // Predict Step
    state[0] = state[0] + deltaTime * state[1]; // speed = speed + acceleration * dt
    estimationErrorCovariance[0][0] += deltaTime * (estimationErrorCovariance[1][1] + processNoiseCovariance[0][0]);
    estimationErrorCovariance[0][1] += deltaTime * estimationErrorCovariance[1][1];
    estimationErrorCovariance[1][0] += deltaTime * estimationErrorCovariance[1][1];
    estimationErrorCovariance[1][1] += processNoiseCovariance[1][1];

    // Calculate Kalman Gain
    float S = estimationErrorCovariance[0][0] + measurementNoise; // Measurement variance
    kalmanGain[0] = estimationErrorCovariance[0][0] / S;
    kalmanGain[1] = estimationErrorCovariance[1][0] / S;

    // Update Step
    float residual = measurement - state[0];
    state[0] += kalmanGain[0] * residual;
    state[1] += kalmanGain[1] * residual;

    // Update error covariance matrix
    estimationErrorCovariance[0][0] *= (1.0 - kalmanGain[0]);
    estimationErrorCovariance[0][1] *= (1.0 - kalmanGain[0]);
    estimationErrorCovariance[1][0] -= kalmanGain[1] * estimationErrorCovariance[0][0];
    estimationErrorCovariance[1][1] -= kalmanGain[1] * estimationErrorCovariance[0][1];

    return state[0];
}

