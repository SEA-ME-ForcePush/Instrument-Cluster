#include "KalmanFilter.h"

KalmanFilter::KalmanFilter(float processNoise, float measurementNoise, float estimationError, float initialValue)
    : processNoise(processNoise), measurementNoise(measurementNoise), estimationError(estimationError), currentEstimate(initialValue), lastEstimate(initialValue), kalmanGain(0.0)
{
}

float KalmanFilter::update(float measurement)
{
    // Prediction update
    estimationError += processNoise;

    // Measurement update
    kalmanGain = estimationError / (estimationError + measurementNoise);
    currentEstimate = lastEstimate + kalmanGain * (measurement - lastEstimate);
    estimationError = (1.0 - kalmanGain) * estimationError;

    // Save estimate for next iteration
    lastEstimate = currentEstimate;

    return currentEstimate;
}

