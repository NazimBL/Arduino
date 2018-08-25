/* this library is writing by  Cristian Steib.
 *      steibkhriz@gmail.com
 *  Designed to work with the GSM Sim800l,maybe work with SIM900L
 *  
 *     This library use SoftwareSerial, you can define de RX and TX pin
 *     in the header "Sim800l.h" ,by default the pin is RX=10 TX=11..
 *     be sure that gnd is attached to arduino too. 
 *     You can also change the other preferred RESET_PIN
 *    
 *     Esta libreria usa SoftwareSerial, se pueden cambiar los pines de RX y TX
 *     en el archivo header, "Sim800l.h", por defecto los pines vienen configurado en
 *     RX=10 TX=11.  
 *     Tambien se puede cambiar el RESET_PIN por otro que prefiera
 *     
 *    PINOUT: 
 *        _____________________________
 *       |  ARDUINO UNO >>>   SIM800L  |
 *        -----------------------------
 *            GND      >>>   GND
 *        RX  10       >>>   TX    
 *        TX  11       >>>   RX
 *       RESET 2       >>>   RST 
 *                 
 *   POWER SOURCE 4.2V >>> VCC
 *
 *    Created on: April 20, 2016
 *        Author: Cristian Steib
 *        
 *
*/

#include <Sim800l.h>
#include <SoftwareSerial.h> //is necesary for the library!! 
SoftwareSerial sim800l(7, 8);
Sim800l Sim800l;  //to declare the library
char* text;
char* number;
bool error; //to catch the response of sendSms
bool sms=true;


void setup(){
	Sim800l.begin(); // initializate the library. 
  pinMode(2,OUTPUT);
  Serial.begin(115200);
 digitalWrite(2,0);
	text="You bloody mad fucking genius !";  //text for the message. 
	number="+213796770812"; //change to a valid number.
	
	


}

void loop(){
  if(sms){
  error=Sim800l.sendSms(number,text); 
  sms=false  ; 
  }

Serial.println(error);
delay(500);
}
