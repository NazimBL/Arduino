int leds[3]={13,7,3};
boolean state[17][3]={0,0,0,
                      0,0,1,
                      0,1,0,
                      1,0,0,
                      0,0,0,
                      1,0,0,
                      0,1,0,
                      0,0,1,
                      0,0,0,
                      1,1,1,
                      1,1,0,
                      1,0,0,
                      0,0,0,
                      1,1,1,
                      0,1,1,
                      0,0,1,
                      0,0,0};     

void setup() {

  for(int i=0;i<3;i++) pinMode(leds[i],OUTPUT);
  turnOff();

}

void loop() {

   for(int i=0;i<17;i++){

    for(int j=0;j<3;j++){
      
      digitalWrite(leds[j],state[i][j]);
      }

    delay(400);
    }
  
}
void turnOff(){
  
 for(int i=0;i<3;i++){
  digitalWrite(leds[i],0);
  } 
  delay(500);
 }
