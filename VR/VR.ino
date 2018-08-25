#include <SoftwareSerial.h>

SoftwareSerial esp(7, 8);
String getCredit(String ussd);
//String ay="+CIFSR:APIP,\"192.168.4.1\"+CIFSR:APMAC,\"62:01:94:52:0b:ea\"+CIFSR:STAIP,\"172.20.13.41\"+CIFSR:STAMAC,\"60:01:94:52:0b:ea\"";
bool sendHTTP(bool stat = false);
void split(String NMEA,char splitChar,String data[],byte dataSize);
bool sendExpect(String sendCMD, String expect,int timeout=400);
String resp="";
bool tag=false;
char c;
long Time= millis();

void setup() {
  
  Serial.begin(9600);
  while (!Serial); 
  Serial.println("Hola");
  esp.begin(115200);
  esp.println("ESP Hola");
  pinMode(13,OUTPUT);
  sendExpect("AT+CIPMUX=1","OK",1000);

}


//esp has to be set in station mode and we have to use the station ip on unity
//so set it connect to wifi , set mode 3 etc..
void loop() {
digitalWrite(13,0);
digitalWrite(12,0);


if(!tag ){
 
  sendExpect("AT+CIPSERVER=1,80","OK",400);
  tag=true;

}

  if(esp.available()){
        
        String received=esp.readString();
        int state=(contains(received,":"))?received.indexOf(":"):0;
        c=received.charAt(state+1);
        
        if(c=='4'){
         tag=false;
        digitalWrite(13,1);
        delay(1000); 
        }else if(c=='1'){
           tag=false;
           digitalWrite(12,1);
           delay(1000);                                                                                           
        }
         digitalWrite(12,0);
         digitalWrite(13,0);
      }
     
      
}
  

bool sendExpect(String sendCMD, String expect,int timeout=400) {
  esp.flush();
  esp.println(sendCMD);
  String response;
  delay(timeout);
  response= esp.readString();
  Serial.println(response);
  return contains(response,expect);
}

void CheckCollision(){
  
  
  }
