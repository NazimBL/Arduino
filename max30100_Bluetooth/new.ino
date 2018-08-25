#include <Wire.h>
#include "MAX30100_PulseOximeter.h"
 
#define REPORTING_PERIOD_MS     500
 
// PulseOximeter is the higher level interface to the sensor
// it offers:
//  * beat detection reporting
//  * heart rate calculation
//  * SpO2 (oxidation level) calculation
PulseOximeter pox;
uint32_t tsLastReport = 0;
int val1=0,val2=0;

char reception='v';
 
// Callback (registered below) fired when a pulse is detected
void onBeatDetected()
{
   // Serial.println("Beat!");
}
 
void setup()
{
    Serial.begin(9600);
 
    //Serial.print("Initializing pulse oximeter..");
 
    // Initialize the PulseOximeter instance
    // Failures are generally due to an improper I2C wiring, missing power supply
    // or wrong target chip
   pox.begin();
   delay(500);
   pox.setOnBeatDetectedCallback(onBeatDetected);
}
 
void loop()
{
    
    
    // Make sure to call update as fast as possible
    
    pox.update();
 
    // Asynchronously dump heart rate and oxidation levels to the serial
    // For both, a value of 0 means "invalid"
    if (millis() - tsLastReport > REPORTING_PERIOD_MS) {
        
        val1=pox.getHeartRate();
        //val2=pox.getSpO2();
        tsLastReport = millis();   
        
    }
    
   
    if(Serial.available() && val1!=0){
    
    reception=(char)Serial.read();
    if(reception=='1')Serial.write((int)val1);
     else if(reception=='2')Serial.write((int)val2);
       
    }
    
    
    
}
