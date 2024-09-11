#include <SPI.h>
#include <mcp2515_can.h>

const int SPEED_SENSOR_PIN = 3;
const int CAN_CS_PIN = 9;
const unsigned long pulse_per_turn = 20; // number of holes

unsigned long oldtime = 0;
double rpm = 0;
unsigned long time;
unsigned long pulse = 0;

mcp2515_can CAN(CAN_CS_PIN); // Changed from MCP_CAN to mcp2515_can

void setup()
{
    Serial.begin(9600);
    attachInterrupt(digitalPinToInterrupt(SPEED_SENSOR_PIN), count, FALLING);

    while (CAN_OK != CAN.begin(CAN_500KBPS))
    {
        Serial.println("CAN BUS Shield init fail");
        Serial.println("Init CAN BUS Shield again");
        delay(100);
    }
    Serial.println("CAN BUS Shield init ok!");
}

void loop()
{
    detachInterrupt(digitalPinToInterrupt(SPEED_SENSOR_PIN));
    time = millis() - oldtime; // find time
    double round = (double)pulse / (double)pulse_per_turn;
    rpm = round * 60.0 * 1000.0 / time; // calculate rpm

    oldtime = millis(); // save current time
    pulse = 0;
    attachInterrupt(digitalPinToInterrupt(SPEED_SENSOR_PIN), count, FALLING);

    Serial.print("rpm : ");
    Serial.println(rpm);

    // Send RPM data over CAN
    unsigned char rpmData[4];
    memcpy(rpmData, &rpm, 4);
    CAN.sendMsgBuf(0x100, 0, 4, rpmData);

    delay(1000);
}

void count()
{
    pulse++;
}