#include <Wire.h>

#define I2C_SLAVE_ADDR 0x42  
const int ledPin = 2;  


void receiveEvent(int bytesReceived);
void requestEvent();

void setup() {
    Serial.begin(115200);
    Wire.begin(I2C_SLAVE_ADDR);  
    Wire.onReceive(receiveEvent); 
    Wire.onRequest(requestEvent); 
    
    pinMode(ledPin, OUTPUT);
  
    digitalWrite(ledPin, LOW);

    Serial.println("ESP32 I2C Slave Ready");
}

void loop() {
    delay(100);
}


void receiveEvent(int bytesReceived) {
    while (Wire.available()) {
        char command = Wire.read();
        Serial.print("Received Command: ");
        Serial.println(command);

        if (command == 'START') {
            digitalWrite(ledPin, HIGH);
        } 
        else if (command == 'STOP') {
            digitalWrite(ledPin, LOW);
        }
     
       
    }
}
void requestEvent() {
    Wire.write((uint8_t*)"ACK", 5);
}
