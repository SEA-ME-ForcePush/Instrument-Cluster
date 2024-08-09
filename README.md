# Instrument Cluster
## 01. Arduino - calculating rpm by speed sensor (7 August 2024) 
- rpm_sensor
: rpm_sensor made by arduino codes

#### Starting...
1. Install arduino IDE
2. You can check rpm rate by clicking the serialMonitor (Tool > serialMonitor) below.

#### Result
(stat : motor running), but still needs to flatten the data using the filter. (bonus part)
![serialMonitor](README/result.png)

## 02. Testing connection with arduinos (8 August 2024) 
`(computer 1 (sender) - arduino uno(connected with the speed sensor) - CAN SHIELD 1 - CAN SHIELD 2 - arduino nano(using bread board) - computer 2 (reciever))`
- We used `MCP2515 CAN Module` for the CAN SHIELD 
                                  
#### Basic Settings
- Download `Arduino IDE`.
- Set the correct board and the port that you're going to work on. (Used Arduino UNO & Arduino NANO)
- `Making speed sensor`: 
  - first, we have to handle the (speed sensor) wheel to move between the sensors. (later we have to attach the (speed sensor) wheel to the back wheel of our PiRacer, and also attach the actual sensor nearby.)
  - connect the voltcraft with the wheel motor and give the power. (need to be tested previously, connection with the male connector.)
  - attach the wheel to the motor. (we need to make the whole (of the wheel) bigger by drills.)
  - attach female connector to the D0, GRD, VCC port of the speed sensor and attach the other side of the connector to the arduino.(D0 specifies the port that we will going to use.)
 
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
- Have to install the 'CAN BUS SHIELD' library (Sketch > Include Library > Manage Libraries).
- (need to use an old version of bootloader, not the default one)
- program authorization -> sudo chmod a+rw [file directory/file name]

#### Stuggles
- if we want to use 5V, we need to use the VCC1 instead of VCC. (recommended)
- we should give the delays to make time to receive the data from the sender arduino. -> sender and the reciever arduino has to put the same delay time. (for our code, delay(1000)).

