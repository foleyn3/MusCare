// Specify an option for the aREST library
// Only return value of a variable when we read from the board
#define LIGHTWEIGHT 1
// Import required libraries
#include <SPI.h>
#include <Adafruit_BLE_UART.h>
#include "Adafruit_BLE_UART.h"
#include <aREST.h>
// Pins
// Note: We don't define SPI pins of the BLUE module because they are defined in the module's libray
#define ADAFRUITBLE_REQ 10
#define ADAFRUITBLE_RDY 2 // interrupt pin
#define ADAFRUITBLE_RST 9
// Create aREST instance
aREST rest = aREST();
// BLE instance
Adafruit_BLE_UART BTLEserial = Adafruit_BLE_UART(ADAFRUITBLE_REQ, ADAFRUITBLE_RDY, ADAFRUITBLE_RST);

int voltageThreshold = 400; // any reading higher will trigger an action
char data = 0;            //Variable for storing received data

void setup(){
    // Start Serial 
    Serial.begin(9600); 
    Serial.println(F("Adafruit Bluefruit Low Energy nRF8001 Print echo demo"));
    // Start BLE 
    BTLEserial.begin();
    Serial.println(F("Start BLE"));
    // Give name and ID to device 
    rest.set_id("001"); 
    char whatever [] = "my_arduino";
    rest.set_name(whatever); 
    } 
    aci_evt_opcode_t laststatus = ACI_EVT_DISCONNECTED;
    void loop(){
      int currentVoltage = analogRead(A0); // store the incoming voltage 
          BTLEserial.write(currentVoltage);
          delay(600);
       
//      Serial.println(currentVoltage);       // prints voltage to monitor



        // Tell the nRF8001 to do whatever it should do 
        BTLEserial.pollACI();
        // Ask what is our current status 
        aci_evt_opcode_t status = BTLEserial.getState();
        if (status != laststatus)
        {
            //print it out 
            if(status == ACI_EVT_DEVICE_STARTED){
            Serial.println(F("* Advertising started"));
        }
        if (status == ACI_EVT_CONNECTED)
        {
            Serial.println(F("* Connected!"));
        }
        if (status == ACI_EVT_DISCONNECTED)
        {
            Serial.println(F("* Disconnected or advertising timed out"));
        }
        // Set the last status 
        laststatus = status; 
        }
        // Handle REST calls 
        if(status == ACI_EVT_CONNECTED){
        rest.handle(BTLEserial);
    }
}
