
int clr=4;
int clk=3;
int in=2;
boolean chkoupi[8]={1,0,0,0,1,1,0,0};
boolean tag=true;
byte state[8]={1,0,0,0,1,1,0,0};

void setup() {

pinMode(clk,OUTPUT);
pinMode(in,OUTPUT);
pinMode(clr,OUTPUT);

digitalWrite(clk,1);
Serial.begin(9600);
digitalWrite(clr,0);
digitalWrite(clr,1);

shiftOut(2,3,LSBFIRST,B00011100);

}

void loop() {

//    shiftOut(2,3,LSBFIRST,fen(2,2));
//    delay(10);
//    shiftOut(2,3,LSBFIRST,fen(0,0));
//    delay(10);
//    shiftOut(2,3,LSBFIRST,fen(1,1));
//    delay(10);

//for(byte i=0;i<3;i++){
//
//  for(byte j=0;j<3;j++){
//     shiftOut(2,3,LSBFIRST,fen(i,j));
//     delay(500);
//     
//  }
//}


}

byte fen(byte x,byte y){
byte sum=0;
if(x==0)sum+=pow(2,7);
else if (x==1)sum+=pow(2,6);
else if (x==2)sum+=pow(2,5);

if(y==0)sum+=12;
else if (y==1)sum+=20;
else if (y==2)sum+=24;

Serial.println(sum);
  return sum;
}
void writeShift(){

 for(int i=0;i<8;i++){
  
if(i<8)digitalWrite(in,chkoupi[i]);
pulsout();
 }
}
void pulsout()   {
  
  digitalWrite(clk,1);
  delayMicroseconds(10);
  digitalWrite(clk,0);
}

