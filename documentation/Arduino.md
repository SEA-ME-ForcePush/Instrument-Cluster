# Arduino in the Instrument Cluster Project

## What is Arduino?

Arduino is an open-source electronics platform based on easy-to-use hardware and software. Arduino boards can read inputs (like light on a sensor or a finger on a button) and turn them into outputs (like activating a motor or turning on an LED). You control the board by sending instructions to the microcontroller using the Arduino programming language and Arduino Software (IDE).

In our project, we primarily used Arduino Uno and Nano boards, with the Nano being used mostly for testing purposes.

## Purpose of Arduino in this Project

Arduino serves as middleware in our instrument cluster project. It performs two key functions:

1. Reads speed data from a speed sensor attached to the PiRacer
2. Sends this speed data to a Raspberry Pi via CAN bus

## Project Structure

[Insert link to project structure diagram here]

## Connection and Explanation

Our Arduino setup consists of the following components:

1. Speed sensor: Connects to the Arduino to measure the PiRacer's speed
2. Arduino Uno: Processes the speed sensor data
3. CAN Bus Shield: Enables CAN communication between Arduino and Raspberry Pi

### Arduino Code Explanation

The main Arduino code [here](https://github.com/SEA-ME-ForcePush/Instrument-Cluster/blob/main/src/arduino/main_arduino_sender.ino) does the following:

1. Reads pulses from the speed sensor as the PiRacer moves
2. Calculates RPM based on pulse count and known pulses per revolution
3. Displays RPM on the serial monitor for debugging
4. Sends RPM data over the CAN bus

The code uses interrupt-based sensing for accurate pulse counting and includes error checking for CAN bus initialization.

### CAN Bus Shield vs MCP2515 CAN

We initially used the MCP2515 CAN controller but later switched to the CAN Bus Shield. The CAN Bus Shield combines the MCP2515 CAN controller and MCP2551 CAN transceiver on a single board, simplifying connections and reducing the number of cables needed.

## Testing CAN Bus Shield

To verify proper RPM data transmission, we set up a test using an Arduino Nano as a receiver. The receiver code can be found [here](https://github.com/SEA-ME-ForcePush/Instrument-Cluster/blob/main/src/arduino/arduino_reciever.ino).

## Resources

- [Arduino Getting Started Guide](https://docs.arduino.cc/learn/starting-guide/whats-arduino/)
- [Arduino CAN Bus Tutorial](https://www.youtube.com/watch?v=QYX_XOjjGOM)
