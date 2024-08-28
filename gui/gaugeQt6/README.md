# Virtual CAN for testing
sudo apt-get install can-utils  
sudo modprobe vcan  
sudo ip link add dev vcan0 type vcan  
sudo ip link set up vcan0  
ip link show vcan0  
candump vcan0  
cansend vcan0 123#DEADBEEF  
cangen vcan0 -n 100  
cangen vcan0 -I 0x200 -g 100 -n 1000  

# Change CAN name in .cpp to real CAN
