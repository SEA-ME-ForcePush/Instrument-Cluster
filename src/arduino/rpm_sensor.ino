#include <SPI.h>
#include <mcp2515_can.h>

const int SPEED_SENSOR_PIN = 2;
unsigned long oldtime = 0;

double rpm = 0;
unsigned long time;
unsigned long pulse;
const unsigned long pulse_per_turn = 20; // number of holes

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
    pulse = 0;
    attachInterrupt(digitalPinToInterrupt(SPEED_SENSOR_PIN), count, FALLING);
}

void loop()
{
    // put your main code here, to run repeatedly:

    detachInterrupt(digitalPinToInterrupt(SPEED_SENSOR_PIN));
    time = millis() - oldtime; // find time
    double round = (double)pulse / (double)pulse_per_turn;
    rpm = round * 60.0 * 1000.0 / time; // calculate rpm

    oldtime = millis(); // save current time
    pulse = 0;
    attachInterrupt(digitalPinToInterrupt(SPEED_SENSOR_PIN), count, FALLING);

    Serial.print("rpm : ");
    Serial.println(rpm);
    delay(500);
}

void count()
{
    pulse++;
}