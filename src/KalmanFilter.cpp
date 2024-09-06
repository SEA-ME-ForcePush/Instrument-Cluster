#include "KalmanFilter.h"

KalmanFilter::KalmanFilter(float processNoise, float measurementNoise, float estimationError, float initialValue)
    : processNoise(processNoise), measurementNoise(measurementNoise), estimationError(estimationError), currentEstimate(initialValue), lastEstimate(initialValue), kalmanGain(0.0)
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

float KalmanFilter::getEstimationError() const
{
    return (this->estimationError);    
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

