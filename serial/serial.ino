#include <SoftwareSerial.h>

SoftwareSerial module(2, 3);

String ssbuff;
int i=0,j;

const String ssid = "Benh";
const String client = "8";
String data = "22";

int record[100];
int maxi;
int datavalue;

bool wifiStatus;
bool tcpStatus;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial) {}
  Serial.println("Initializing Loop");
  module.begin(9600);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  //generates Data
  datavalue=0;
  for (i=0;i<20;i++){
  maxi=0;
  for (j=0;j<100;j++) {
    int temp=analogRead(A0)-analogRead(A1);
    maxi=(temp>maxi)?temp:maxi;
    delay(1);
    }
  datavalue+=maxi;
  delay(10);
  }
  datavalue=datavalue/20;
  data=String(datavalue);
  //Saves Data to SD Card
  
  //checks Wifi Status
  wifiStatus = sendExpect("AT+CWJAP?", ssid);
  digitalWrite(4, wifiStatus);
  if (wifiStatus) {
  tcpStatus=sendHTTP();
  if (tcpStatus) {
    digitalWrite(5,LOW);
    delay(100);
    digitalWrite(5,HIGH);
    delay(100);
  }
  }
}

bool sendHTTP() {
  if (sendExpect("AT+CIPSTART=\"TCP\",\"138.68.74.186\",80", "OK")) {
    String getcommand = "GET http://138.68.74.186/submit.php?client_n=" + client + "&data=" + data;
    if (sendExpect("AT+CIPSEND=" + String(getcommand.length() + 2), ">")) {
      if (sendExpect(getcommand, "S")) {
        return true;
      }
    }
  }
return false;
}

bool sendExpect(String sendCMD, String expect) {
  module.flush();
  module.println(sendCMD);
  delay(200);
  if (module.available()) {
    while (module.available()) {
      ssbuff = module.readString();
      Serial.println("REC:" + ssbuff);
    }
  }
  if (ssbuff.indexOf(expect) > 0) {
    return true;
  } else return false;
}
