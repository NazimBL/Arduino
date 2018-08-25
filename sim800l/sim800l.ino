#include <SoftwareSerial.h>
SoftwareSerial sim800l(2, 3); // RX, TX

void setup() {
 Serial.begin(115200);
 while(!Serial);
 Serial.println("Serial is ready");
 sim800l.begin(115200);
 delay(1000);
 Serial.println("Sim800l is ready to com");


}

void loop(){

 
//if sim has something to say , write it in serial 

 if (sim800l.available())
 {
  Serial.write(sim800l.read());
   
 }

 //if we tape somthing in serial , write it to sim

 if (Serial.available()) {

 sim800l.write(Serial.read());
 
 }
}
