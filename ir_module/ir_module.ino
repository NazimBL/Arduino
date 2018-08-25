#include <IRremote.h>
#include <Servo.h>

IRrecv irrecv(11);
int val=90;
decode_results results;
long dec=0;
// droite 21A60ED0
//82829FBA

Servo myservo;
void setup()
{
  Serial.begin(9600);
  pinMode(12,OUTPUT);
  myservo.attach(9);
  irrecv.enableIRIn(); // Start the receiver
 // myservo.write(val);   
}

void loop() {
  
  
  if (irrecv.decode(&results)) {
    Serial.println(results.value,HEX);
    
   
    if(results.value==0x2028877){
   // digitalWrite(12,1);
      myservo.write(val+30);
    
    }
    else if(results.value==0x20208F7){
       myservo.write(val-30);
    }
    
//    else digitalWrite(12,0);
 
    irrecv.resume(); // Receive the next value
  }
 
  delay(100);
}

  
  
