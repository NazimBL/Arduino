int leds[3]={13,7,3};
void setup() {

 for(int i=0;i<3;i++){
     pinMode(leds[i],OUTPUT);  
  
  }
  
  turnOff();
}

void loop() {
 turnOff();
leftWave(1);
 turnOff();
 rightWave(1);
 turnOn();
 leftWave(0);
 turnOn();
 rightWave(0);
 
}
void leftWave(int dig){
for(int i=0;i<3;i++){
  digitalWrite(leds[i],dig);
 delay(500);
  }  
  }
void rightWave(int dig){
for(int i=2;i>=0;i--){
  digitalWrite(leds[i],dig);
 delay(500);
  }  
  }
void turnOn(){
  
for(int i=0;i<3;i++)digitalWrite(leds[i],1);
 
 delay(500);
  }

void turnOff(){
  
for(int i=0;i<3;i++)digitalWrite(leds[i],0);
 
 delay(500);
  }
