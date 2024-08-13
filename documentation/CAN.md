# What is CAN?
CAN (Controller Area Network) bus is a robust communication protocol designed for efficient data exchange between electronic control units (ECUs) in vehicles and other systems.   

# What is the primary purpose of CAN?
To allow any ECU (Electronic Control Unit) to communicate with the entire system without causing an overload to the controller computer.  

# How does CAN work? 
-

# What does a CAN message look like?
![image](https://github.com/user-attachments/assets/7bccfbae-da65-49b5-9c2a-9898a2512945)
![Screenshot from 2024-08-07 20-11-31](https://github.com/user-attachments/assets/0017b124-60a7-46e5-b466-9d0362739c88)

SOF: The Start of Frame is a 'dominant 0' to tell the other nodes (ECUs) that a CAN node intends to talk (send a message)  
**ID**: The CAN-ID is the frame identifier - lower values have higher priority. It contains the message priority as well as a functional address (e.g. RPM, wheel speed, ...)  
RTR: The Remote Transmission Request indicates whether a node sends data or requests dedicated data from another node. In other words it allows ECUs to request messages from other ECUs.  
**Control**: The Control contains the Identifier Extension Bit (IDE) which is a 'dominant 0' for 11-bit. It also contains the 4 bit Data Length Code (DLC) that specifies the length of the data bytes to be transmitted (0 to 8 bytes)  
**Data**: The Data contains the data bytes aka payload, which includes CAN signals that can be decoded for information  
CRC: The Cyclic Redundancy Check is used to ensure data integrity  
ACK: The ACK slot indicates if the node has acknowledged and received the data correctly  
EOF: The EOF marks the end of the CAN frame  

# Further stadards how to work with CAN?
SEA J1939 - Standard in-vehicle network for heavy-duty vehicles (buses, trucks, ...). All messages rely on the extended 29 bits CAN identifier. (https://www.csselectronics.com/pages/j1939-explained-simple-intro-tutorial?_pos=4&_sid=1f43b9b8e&_ss=r)  
OBD-II - On-board diagnostics (https://www.csselectronics.com/pages/obd2-explained-simple-intro?_pos=4&_sid=c478f5894&_ss=r)  
CANopen (https://www.csselectronics.com/pages/canopen-tutorial-simple-intro?_pos=2&_sid=9ffa89ee5&_ss=r)  

# Ressources
https://www.csselectronics.com/pages/can-bus-simple-intro-tutorial  
https://www.youtube.com/watch?v=FqLDpHsxvf8  
https://www.youtube.com/watch?v=oYps7vT708E&t=0s

# ToDo (Further ressources for better understanding and improving documentation)
https://www.youtube.com/watch?v=DonsJ5cW55I ( Tesla CAN Bus Raspberry Pi )  
https://www.youtube.com/watch?v=62txKc7EtCA ( Tesla CAN Bus - Quick Exploration )  
https://www.youtube.com/watch?v=YBrU_eZM110 ( CAN Bus: A Beginners Guide Part 1 )  
https://www.youtube.com/watch?v=z5CVljiLhvc ( CAN Bus: A Beginners Guide Part 2 )  
https://www.youtube.com/watch?v=YbF3idCk4EQ ( CAN Bus Communication Explained (Part 1) )  
https://www.youtube.com/watch?v=mNjISEK5VMg ( CAN Bus Wiring and Protocol Explained (Part 2) )  
https://www.youtube.com/watch?v=7AAiP3Ryh2o ( CAN Bus Troubleshooting and Diagnosis Explained (Part 3) )  
https://www.youtube.com/watch?v=JZSCzRT9TTo ( CAN Bus: Serial Communication - How It Works? )  
https://www.youtube.com/watch?v=cAAzXM5vsi0 ( How to hack your car | Part 1 - The basics of the CAN bus )  
https://www.youtube.com/watch?v=ZhYc95b6WoU ( How to hack your car | Part 2 - CAN Sniffer app )  
