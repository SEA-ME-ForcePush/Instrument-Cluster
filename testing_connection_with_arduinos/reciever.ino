#include <SPI.h>
#include <mcp2515_can.h>
const int SPI_CS_PIN = 10;
mcp2515_can CAN(SPI_CS_PIN); // Use mcp2515_can instead of MCP_CAN
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
    //  Serial.println(CAN_MSGAVAIL);
    delay(1000);
    if (CAN_MSGAVAIL == CAN.checkReceive())
    {
        CAN.readMsgBuf(&len, buf);
        unsigned long canId = CAN.getCanId();
        // Serial.print("CANid : ");
        // Serial.println(canId);
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