byte clr=3;
byte clk=2;
byte d0=4,d1=5,d2=6,d3=7,d4=8;
boolean tag=true;
int i=0;

void setup() {

   pinMode(clr,OUTPUT);
   pinMode(clk,OUTPUT);
   pinMode(d0,OUTPUT);
   pinMode(d4,OUTPUT);
   digitalWrite(clk,1);
   Serial.begin(9600);
   digitalWrite(clr,0);
   digitalWrite(clr,1);
   turnArray(B01111111,d4);
   shiftOut(d0,clk,LSBFIRST,0);

}

void loop() {

// myShift(1);
//turnLed(0,0,0);
  
  turnArray(B10000000,d0);
 

//turnArray(B00011111,d0);

}

void turnArray(byte val,byte shift){
  shiftOut(shift,clk,LSBFIRST,val);
  delay(500);
}

void counter(){
  for(int i=0;i<256;i++){
  shiftOut(d0,clk,LSBFIRST,i);
  delay(500);
}
}
void turnLed(byte x,byte y,byte z){
  
  if(z==0){
    shiftOut(d0,clk,LSBFIRST,pow(2,(7-x)));
   //  shiftOut(d0,clk,LSBFIRST,64);
  }
  else if(z==1){
    if(x<3) shiftOut(d0,clk,LSBFIRST,pow(2,(2-x)));
    else {
      if(x==3)shiftOut(d1,clk,LSBFIRST,128);
      else if(x==4)shiftOut(d1,clk,LSBFIRST,64);
    }
  }
  else if(z==2){
    
  }
  else if(z==3){
    
  }
  else if(z==4){
    
  }
  byte cathode=0;
  cathode=31-pow(2,y);

  //shiftOut(d4,clk,LSBFIRST,B11111110);
  
  
}
void myShift(int i){
for(int j=0;j<8;j++){
  digitalWrite(clk,0);
  digitalWrite(d0,i);
  i=0;
  digitalWrite(clk,1);
  delay(500);
}
}

byte checkFloor(byte indice){

byte z=0;
if(indice<5)z=0;
else if(indice>4 && indice<10)z=1;
else if(indice>9 && indice<15)z=2;
else if(indice>14 && indice<20)z=3;
else if(indice>19 && indice<25)z=4;

  return z;
}

