#include<SoftwareSerial.h>
SoftwareSerial debug(2,3);
#include <EEPROM.h>;
byte p[5]={0,1,2,3,4};
byte conf=0;
char *phone="104";
bool tag=true;
bool SendExpect(char *cmd,char *response,int timeout=800,byte op=0);
bool sendTCP(String request);

void setup() {
  
Serial.begin(115200);
pinMode(13,OUTPUT);
pinMode(2,OUTPUT);
//debug.begin(115200);   

}

void loop() {
  turnOn();
  delay(5000);
  SendExpect("AT+CPOF","OK");
  delay(3000);
    
}

void WriteData(char *value){
   for (byte i=0;i<10;i++)Serial.print(*value++);
   Serial.print('\n');   
}


