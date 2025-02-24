#include <Wire.h>
#include <Arduino.h>
#include <ui.h>


#define I2C_ADDRESS 0x10  // Address of the external ESP32

void sendCommand(const char *command) {
    Wire.beginTransmission(I2C_ADDRESS);
    Wire.write((uint8_t*)command, strlen(command)); 
    Wire.endTransmission();
}

void start(lv_event_t * e)
{
    sendCommand("START");
}

void stop(lv_event_t * e)
{
    sendCommand("STOP");
}
