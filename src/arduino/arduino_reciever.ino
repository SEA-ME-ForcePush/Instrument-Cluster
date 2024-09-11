#include <SPI.h>
#include <mcp2515_can.h>

const int SPI_CS_PIN = 9;

mcp2515_can CAN(SPI_CS_PIN);

void setup()
{
    Serial.begin(9600);
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
    unsigned char len = 0;
    unsigned char buf[8];

    delay(1000);
    if (CAN_MSGAVAIL == CAN.checkReceive())
    {
        CAN.readMsgBuf(&len, buf);
        unsigned long canId = CAN.getCanId();

        if (canId == 0x100 && len == 4)
        {
            double receivedRpm;
            memcpy(&receivedRpm, buf, sizeof(receivedRpm));
            Serial.print("Received RPM: ");
            Serial.println(receivedRpm);
        }
    }
    else if (CAN_NOMSG == CAN.checkReceive())
    {
        Serial.println("No data received");
    }
}