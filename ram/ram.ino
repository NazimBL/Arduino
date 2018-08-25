
#include "LedControl.h"

int din=4,clk=2,cs=3,i=0;
LedControl display=LedControl(din,clk,cs,2);
int x=2,y=2;
int column=0;
int obstacle[7]={63,159,207,231,243,249,252};
boolean gameover=false;

void setup() {

Serial.begin(9600);

display.shutdown(0,false);
display.shutdown(1,false);
display.setLed(1,1,1,true);

}

void loop() {

while(!gameover){

display.clearDisplay(0);
display.clearDisplay(1);
display.setLed(0,x,y,true);
x++;
jump();
randomObstacle(i);
display.setColumn(1,column,(byte)obstacle[i]);
delay(200);
if(y==7)
{
  
  //y=0;
}
if(x==8)x=0;
if(column<0){
  column=7;
  i=random(0,6);
}
}
display.shutdown(0,true);

}

void jump(){
if(Serial.available()>0){

  if((char)Serial.read()=='c') {
    display.setLed(0,x,y,false);
    x=x-3;
  }
}
}
void loseCheck(){
  
  }

void randomObstacle(int r){
  display.setColumn(0,column,(byte)obstacle[r]);
  column--;
  
  }
