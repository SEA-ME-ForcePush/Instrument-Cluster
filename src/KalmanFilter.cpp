#include "KalmanFilter.h"

KalmanFilter::KalmanFilter(float processNoise, float measurementNoise, float estimationError, float initialValue)
    : processNoise(processNoise),
    measurementNoise(measurementNoise),
    estimationErrorCovariance({{{estimationError, 0.0f}, {0.0f, estimationError}}}), // Correct initialization
    processNoiseCovariance({{{processNoise, 0.0f}, {0.0f, processNoise}}}), // Correct initialization
    kalmanGain({0.0f, 0.0f}),
    state({initialValue, 0.0f}), // Initial state: speed = initialValue, acceleration = 0
    lastUpdateTime(std::chrono::steady_clock::now()) // Initialize timestamp to the current time
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

float KalmanFilter::update(float measurement)
{
    // Get the current time and calculate deltaTime
    auto currentTime = std::chrono::steady_clock::now();
    std::chrono::duration<float> elapsedSeconds = currentTime - lastUpdateTime;
    float deltaTime = elapsedSeconds.count();

    // Store the current time as the last update time
    lastUpdateTime = currentTime;

    // Prediction update (assuming a constant acceleration model)
    estimationErrorCovariance[0][0] += deltaTime * (2 * estimationErrorCovariance[1][0] + deltaTime * estimationErrorCovariance[1][1] + processNoiseCovariance[0][0]);
    estimationErrorCovariance[0][1] += deltaTime * estimationErrorCovariance[1][1];
    estimationErrorCovariance[1][0] += deltaTime * estimationErrorCovariance[1][1];
    estimationErrorCovariance[1][1] += processNoiseCovariance[1][1];

    // Measurement update
    float y = measurement - state[0]; // Innovation or measurement residual
    float S = estimationErrorCovariance[0][0] + measurementNoise; // Innovation covariance
    kalmanGain[0] = estimationErrorCovariance[0][0] / S;
    kalmanGain[1] = estimationErrorCovariance[1][0] / S;

    // Update state estimate
    state[0] += kalmanGain[0] * y;
    state[1] += kalmanGain[1] * y;

    // Update error covariance
    estimationErrorCovariance[0][0] -= kalmanGain[0] * estimationErrorCovariance[0][0];
    estimationErrorCovariance[0][1] -= kalmanGain[0] * estimationErrorCovariance[0][1];
    estimationErrorCovariance[1][0] -= kalmanGain[1] * estimationErrorCovariance[0][0];
    estimationErrorCovariance[1][1] -= kalmanGain[1] * estimationErrorCovariance[0][1];

    return state[0]; // Return the filtered speed
}
