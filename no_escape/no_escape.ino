/*
  Done by Bellabaci Nazim on 10/07/2017
  GooglePlay : Nazim_BL
  email: nazim@braniac.dz
*/
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#include <SoftwareSerial.h>
SoftwareSerial sim900(7, 8);
void(* resetFunc) (void) = 0;
int stg1[40];
int temp, i, j, avg;
String id = "1";
float power, current;
bool sendExpect(String sendCMD, String expect, int timeout = 400);
String tcp_cmd = "AT+CIPSTART=\"TCP\",\"178.62.50.10\",\"80\"";

String tcp_start = "CONNECT";
String apn = "\"djezzy.internet\"";
bool config_tag = false;
bool apn_tag = true;

long timeStamp = 5000;
float data;
String command ="GET /api/insert.php?id="+id+"&value="+data; 


void setup() {
  sbi(ADCSRA, ADPS2);
  cbi(ADCSRA, ADPS1);
  cbi(ADCSRA, ADPS0);
  Serial.begin(115200);
  while (!Serial);
  sim900.begin(9600);
  pinMode(9, OUTPUT);
}

void loop() {

  Serial.println("Yo !");
  send_by_force();
  if (sendExpect("AT+CPIN?", "OK")) {
    Serial.println("Sim Ready");
    int c = creg();
    if (c == 1) {
      Serial.println("Configuring...");
      sendExpect("AT+CIPMODE=1", "OK");
      sendExpect("AT+CIPMUX=0", "OK");
      if (sendExpect("AT+CGATT=1","OK",4000)) {
        Serial.println("Gprs Up");
        if (sendExpect("AT+CSTT=" + apn, "OK")) {
          if (sendExpect("AT+CIICR", "OK", 10000)) {
            delay(2000);
            sendExpect("AT+CIFSR", "1", 5000);
            while (creg() == 1 || creg()==2) {
              if (sendExpect(tcp_cmd, tcp_start, 4000)) {
                Serial.println("Connected !");
                delay(500);
                //sim900.flush();
                float data = measure();
                Serial.println("Sending...");
                //sim900.println(command+String(data));
                //delay(timeStamp);
                if (sendExpect(command + String(data), "Done", timeStamp)) {
                  Serial.println("Sent");
                }
                else {
                  Serial.println("request error");
                  break;
                }

              } else {
                Serial.println("Socket error");
                break;
              }
            }
          }
          else {
            Serial.println("Couldn't connect to Apn...");
          }
        }

      }
      else {
        Serial.println("Couldn't activate Gprs");
        //reset();
      }
//    } else if (c == 2) {
//      Serial.println("Searching...");
//      delay(8000);
    } else {
      Serial.println("Client not registered...reseting module..");
      reset();
    }
  } else {
    Serial.println("No sim card conneceted");
  }
  delay(500);
}
