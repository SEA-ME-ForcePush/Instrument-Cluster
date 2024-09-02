# Instrument Cluster
## 01. Arduino - calculating rpm by speed sensor (7 August 2024) 
- rpm_sensor
: rpm_sensor made by arduino codes

#### Functions
You can check rpm rate by clicking the serialMonitor (Tool > serialMonitor) below.

#### Result
(stat: motor running), but still needs to flatten the data using the filter. (bonus part)
![serialMonitor](README/result.png)

## 02. Testing connection with arduinos (8 August 2024) 
`(computer 1 (sender) - arduino uno(connected with the speed sensor) - CAN SHIELD 1 - CAN SHIELD 2 - arduino nano(using bread board) - computer 2 (reciever))`
- We used `MCP2515 CAN Module` for the CAN SHIELD 
                                  
#### Basic Settings
- Download [`Arduino IDE`](https://www.arduino.cc/en/software).
- Set the correct board and the port that you're going to work on. (Used Arduino UNO & Arduino NANO)
- `Making speed sensor`: 
  - first, we have to handle the (speed sensor) wheel to move between the sensors. (later we have to attach the (speed sensor) wheel to the back wheel of our PiRacer, and also attach the actual sensor nearby.)
  - connect the voltcraft with the wheel motor and give the power. (need to be tested previously, connection with the male breakout wire.)
  - attach the wheel to the motor. (we need to make the whole (of the wheel) bigger by drills.)
  - attach female breakout wire to the D0, GRD, VCC port of the speed sensor and attach the other side of the breakout wire to the arduino.(D0 specifies the port that we will going to use.) (Usually we use the black breakout wire when we're going to connect the GRD, use the white one for the voltage.)

</br> // need pics of how to attach the arduino and the CAN SHEILD here!
 
#### Terms
- `MCP2515 CAN Module`
  - INT
  - SCK
  - SI
  - SO
  - CS
  - GND
  - VCC1
  - VCC

#### Code Settings
- Have to install the `CAN BUS SHIELD` library (Sketch > Include Library > Manage Libraries).
- (need to use an old version of bootloader, not the default one)
- program authorization -> `sudo chmod a+rw [file directory/file name]`

#### Stuggles
- if we want to use 5V, we need to use the `VCC1` instead of `VCC`. (recommended)
- we should give the delays to make time to receive the data from the sender arduino. -> sender and the reciever arduino has to put the same delay time. (for our code, `delay(1000)`).

## 0x. Implementation of the Kalman filter (2 September 2024)

The Kalman filter is an algorithm that provides an efficient computational means to estimate the state of a process in a way that minimizes the mean of the squared error. It is widely used in control systems, navigation, and time-series prediction due to its effectiveness in filtering out noise from measurements.

The Kalman filter assumes that the true state of the system is governed by a linear dynamic system model, which is described by:

- State Transition Model: This model predicts the next state of the system based on the current state.
- Measurement Model: This relates the state of the system to the measurements we observe.
  
The Kalman filter operates in two main steps:
- 1. Prediction Step:
  * Predict the next state of the system.
  * Predict the error covariance, which gives an estimate of the uncertainty.
- 2. Update Step:
  * Compute the Kalman Gain, which tells how much weight should be given to the new measurement versus the prediction.
  * Update the state estimate using the measurement.
  * Update the error covariance.
 
So the core of the Kalman filter class, that we implemented, is the member function 
``` 
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
```
with Q: process noise covariance, R: the measurement noise covariance, P: error covariance and X: estimated value.

The Kalman filter is used between the reading of the CAN data and the conversion from rounds per minute to speed.
