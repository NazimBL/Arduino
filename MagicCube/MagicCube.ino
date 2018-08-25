
byte in=2,latch1=3,latch2=4,latch3=5,sclk=6,clr=7,oe=9;
byte d=8,clk=10;
byte latch4=11;
byte i=0;
boolean tag=true;//to repeat once
boolean a[5]={1,0,1,0,1};
byte anods[5]={1,2,4,8,16};
byte cathods[5]={1,2,4,8,16};
byte clear_cathode=248;
byte clear_anodes=0;
char program_code='1';//to change scheme
bool b[5]={1,0,0,0,1};
bool g[5]={0,1,0,1,0};
bool f[5]={0,0,1,0,0};


void setup() {
  
for(byte i=2;i<12;i++){
  pinMode(i,OUTPUT);  
}

digitalWrite(latch1,0);
digitalWrite(latch2,0);
digitalWrite(latch3,0);
digitalWrite(latch4,0);
digitalWrite(sclk,0);
digitalWrite(clk,0);
digitalWrite(clr,0);
digitalWrite(clr,1);
digitalWrite(oe,0);

initialize();

Serial.begin(9600);

}

void loop() {

if(Serial.available()){

  program_code=Serial.read();
}

if(program_code=='0')fix();
if(program_code=='1')myRain();
if(program_code=='2')leftRain();
//v();
delay(5000);
//douda();
//myRain();
  
if(tag){
 
tag=false;
}
}
void clearAnode(){
  digitalWrite(latch4,0);
shiftOut(d,clk,MSBFIRST,0);
digitalWrite(latch4,1);
}

void douda(){

  clearAnode();
  for(byte i=0;i<5;i++){
  for(byte j=0;j<5;j++){
digitalWrite(latch4,0);
shift_bit(0);
digitalWrite(latch4,1);
shiftOut(d,clk,MSBFIRST,anods[j]);
shift_bit(1);
delay(30);
digitalWrite(latch4,1);
    
  }
  }
}

void leftRain(){

clearAnode();
for(byte j=0;j<5;j++){
digitalWrite(latch4,0);
shiftOut(d,clk,MSBFIRST,anods[j]);

  for(byte i=0;i<5;i++){
 randomRow(a);
 shift_floor(a);
    
  }
  digitalWrite(latch4,1);
  delay(30);
}
}
void myRain(){
clearAnode();
randomRow(a);
for(byte i=0;i<5;i++){
  digitalWrite(latch4,0);
shiftOut(d,clk,MSBFIRST,anods[i]);
digitalWrite(latch4,1);
     shift_floor(a); 
     delay(100);
}
  
}
void horizentalRain(byte cathod){
digitalWrite(latch4,0);
shiftOut(d,clk,MSBFIRST,cathod);
digitalWrite(latch4,1);
for(byte i=0;i<5;i++){
  randomRow(a);
  shift_floor(a); 
}
  
}
void arrayTransform(bool b[]){
     a[0]=b[0];
    for(byte i=1;i<5;i++)a[i]=0;
}
void fix(){
  digitalWrite(latch1,0);
digitalWrite(latch2,0);
digitalWrite(latch3,0);
}
void verticalRain(){
for(byte i=0;i<5;i++){

   randomRow(a);
   RainDrop(a,cathods[i]);
   delay(50);
}
  
}

void RainDrop(bool b[],byte cathod){
digitalWrite(latch4,0);
shiftOut(d,clk,MSBFIRST,cathod);
digitalWrite(latch4,1);

shift_floor(b);
shift_floor(b);

digitalWrite(latch1,1);
digitalWrite(latch2,1);
digitalWrite(latch3,1);
  
}
void shift_floor(bool b[]){
digitalWrite(latch1,0);
digitalWrite(latch2,0);
digitalWrite(latch3,0);

for(int i=0;i<5;i++){
shift_bit(b[i]);

}
digitalWrite(latch1,1);
digitalWrite(latch2,1);
digitalWrite(latch3,1);

}
void initialize(){
digitalWrite(latch1,0);
digitalWrite(latch2,0);
digitalWrite(latch3,0);

for(int i=0;i<25;i++){
shift_bit(1);

}
digitalWrite(latch1,1);
digitalWrite(latch2,1);
digitalWrite(latch3,1);

}

void shift_bit(bool b){
digitalWrite(sclk,0);
digitalWrite(in,b);
digitalWrite(sclk,1); 
}
void randomRow(bool b[]){

for(byte i=0;i<5;i++){
int r=(int)random(0,6);
  if(r%2==0)b[i]=1;
  else b[i]=0;
}

  
}
void displayArray(bool a[]){

  for(byte i=0;i<5;i++){

    
  }
}
void test(){
  digitalWrite(latch4,0);
  shiftOut(d,clk,MSBFIRST,16);
  digitalWrite(latch4,1);
  shift_floor(a);
  
}
void letter(){
  byte let[5][5] = {B10011,B10110};
  }

 void v(){
digitalWrite(latch1,0);
digitalWrite(latch2,0);
digitalWrite(latch3,0);
byte j=0;
digitalWrite(latch4,0);
shift_floor(b);
digitalWrite(latch4,1);
shiftOut(d,clk,MSBFIRST,anods[j]);
j++;
  
digitalWrite(latch4,0);
shift_floor(g);
digitalWrite(latch4,1);
shiftOut(d,clk,MSBFIRST,anods[j]);
j++;

digitalWrite(latch4,0);
shift_floor(g);
digitalWrite(latch4,1);
shiftOut(d,clk,MSBFIRST,anods[j]);
j++;

digitalWrite(latch4,0);
shift_floor(f);
digitalWrite(latch4,1);
shiftOut(d,clk,MSBFIRST,anods[j]);
j++;

digitalWrite(latch4,0);
shift_floor(f);
digitalWrite(latch4,1);
shiftOut(d,clk,MSBFIRST,anods[j]);
j++;

 
digitalWrite(latch1,1);
digitalWrite(latch2,1);
digitalWrite(latch3,1);
   
}

