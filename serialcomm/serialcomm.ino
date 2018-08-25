#include<SoftwareSerial.h>

SoftwareSerial mine(2,3);

boolean  SendExpect(char *command, char *response, int timeout = 400); 
byte SendCommand(char *command,char *response, int timeout = 400);
void setup() {
  
mine.begin(115200);  
Serial.begin(115200);
pinMode(13,OUTPUT);
pinMode(11,OUTPUT);
pinMode(10,OUTPUT);


}

void loop() {
Serial.flush();
byte n=0;
//n=SendCommand("AT\r","OK");
if(SendExpect("AT","OK"))mine.println("sucess");
else mine.println("fuck u");
if(n==0){
digitalWrite(13,1);
delay(500);
digitalWrite(13,0);
delay(500);

}else if(n==1){
  digitalWrite(11,1);
delay(500);
digitalWrite(11,0);
delay(500);
}else{
digitalWrite(10,1);
delay(500);
digitalWrite(10,0);
delay(500);
}
delay(1000);

}

