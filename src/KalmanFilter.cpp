#include "KalmanFilter.h"

/* Constructor */
KalmanFilter::KalmanFilter(double q, double r, double p, double initial_value) 
			: Q(q), R(r), P(p), X(initial_value) {}
/* Destructor */
KalmanFilter::~KalmanFilter() {}

/* Update member function */

double KalmanFilter::update(double measurement)
{
	// Prediction update
	P = P + Q;

	// Measurement update
	double K = P / (P + R); // Kalman gain
	X = X + K * (measurement - X);
	P = (1 - K) * P;

	return X;
}
