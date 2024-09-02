#ifndef KALMAN_FILTER_H
#define KALMAN_FILTER_H

class KalmanFilter
{
	public:
		KalmanFilter(double q, double r, double p = 1.0, double initial_value = 0.0) ;
		~KalmanFilter();

		double update(double measurement);

	private:
		double Q;  // Process noise covariance
		double R;  // Measurement noise covariance
		double P;  // Error covariance
		double X;  // Estimated Value
};

#endif