int pos[5]={2,3,4,5,6};
int neg[5]={7,8,9,10,11};
void setup() {

Serial.begin(9600);
  for(int i=2;i<7;i++){
    pinMode(i,OUTPUT);
    digitalWrite(i,0);
  }
  for(int i=7;i<12;i++){
    pinMode(i,OUTPUT);
     digitalWrite(i,1);
  }
  
}
void turnLed(int x,int y){

digitalWrite(pos[x],1);
digitalWrite(neg[y],0);

digitalWrite(pos[x],0);
digitalWrite(neg[y],1);
  
  }
void loop() {
  
turnLed(0,4);
turnLed(0,1);
turnLed(0,3);


}


