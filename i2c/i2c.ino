#include <Wire.h>

int  error=1;
byte address=0x0B;

void setup() {
Serial.begin(9600);
pinMode(2,INPUT);
Wire.begin();
//Wire.setClock(500000);

}

void loop() {
  
  //Wire.beginTransmission(address);
  //Wire.write('c');
  //Wire.endTransmission();
  
  Wire.requestFrom(address, 1);
  while(Wire.available()){
 
  char c = Wire.read();
  //if(c!=-1)
  Serial.println(c);
  
  }
  delay(500);
}
