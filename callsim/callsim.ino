
#include <SoftwareSerial.h>
SoftwareSerial sim800l(7, 8); // RX, TX
void setup() {
  // put your setup code here, to run once:

Serial.begin(115200);
 sim800l.begin(115200);
 pinMode(2,OUTPUT);
 digitalWrite(2,0);
 delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println("Nothing Happened");  
sim800l.write("AT+CMGF=1");
delay(500);
sim800l.write("ATD+213796770812;");
delay(500);


}
