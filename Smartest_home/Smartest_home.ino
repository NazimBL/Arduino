
#include <DHT11.h>
const byte dh=9;
const byte in1 = 11;
const byte in2 = 13;
const byte fan=10;
const byte gym_motor=3;
//leds from 4 to 8 ?
DHT11 dht11(dh);
//fetch float array
char buff[7];
//contain pin number analog/digital value
char values[5];
//fetch space array
char n[7];
//to send data only once
char previous='a';
//# of lights on
byte count=0;
byte lights_on=0;
//light energy lost
double E=0;
 //light bulbs consumption in watt
float p_light=12;
//in watt =250w * 0.75
float PR_Ppeak=187.5;
//2.92*1.2 m²
float Area=3.5;
double E_solar=0;
//number of hours under full sun
double H=0;

char garage_motor='m';

bool fan_tag=false;
char m='a';
bool auto_tag=true;


void setup() {

  for(byte i=3;i<8;i++)pinMode(i,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(fan,OUTPUT);

  Serial.begin(9600);

}

void loop() {
  
solarEnergyCounter();
lightEnergyCounter();
automatedLight();

float temp, humi;
dht11.read(humi, temp);
 
if(Serial.available()){
  Serial.readBytes(values,5);
  m=values[0]; 
  Serial.println(m);
  fetchLight();
 }
 if(m=='1'){
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    delay(1700);
    m='s';
    auto_tag=true;
 }
 else if (m=='0') {
    digitalWrite( in1 , HIGH);
    digitalWrite( in2, LOW);
    delay(1700);
    m='s';
    auto_tag=true;
    
  }else if(m=='2'){
    digitalWrite(fan,1);
    auto_tag=false;
  }
  else if(m=='3'){
    digitalWrite(fan,0);
    auto_tag=false;
  }  
 else if(m=='t' && previous!='t'){
  Serial.write('t');
  write_string(temp);
  delay(50);
  previous='t';
  }
  else if(m=='h'&& previous!='h'){
    Serial.write('h'); 
    write_string(humi); 
    delay(50);
     previous='h'; 
  }
  else if(m=='s' && previous!='s'){
     Serial.write('s');
     write_string(E_solar);
     delay(50);
     previous='s';
  }
  else if(m=='l' && previous!='l'){
   Serial.write('l');
    write_string(E);
    delay(50); 
    previous='l';
  }
  else if(m=='2'){
    if(!fan_tag)digitalWrite(fan,1);
    else digitalWrite(fan,0);
    fan_tag=!fan_tag; 
  }
  else {
    digitalWrite( in1 , LOW);
    digitalWrite( in2, LOW);
    auto_tag=true;
  }
dht11.read(humi, temp);
  if(auto_tag)tempControll(temp);
  delay(100);
}
void automatedLight(){
if(analogRead(A0)<200)digitalWrite(7,1);
else digitalWrite(7,0);
  
}
void tempControll(float t){
  if(t>28)digitalWrite(fan,1);
  else digitalWrite(fan,0);
}

//power and energy consumed by lights
void lightEnergyCounter(){
//change this according to the number of pins
for(byte i=3;i<8;i++) if(digitalRead(i)==1)count++;
lights_on=count;
count=0;
//Et=n*p*t where n is the number if lights on
//KWS
E=(lights_on*p_light/10000)+E;
}
//takes off space character from float-string
void fetch( ){
byte j=0;
for(byte i=0;i<7;i++){
  if(buff[i]!=' '){
    n[j]=buff[i];
    j++;
}}}
void solarEnergyCounter(){
  
H=analogRead(A0);
//2200 in the average radiation per year in algeria
H=map(H,0,1023,0,2200);
//H gives average sun got in one year
H=H/365;
//number of hourss of sunlight per day
H=H/24;
//to convert in seconds
H=H/36;
//still 100
//6 is the # of panels
//devide by addional 10 due to delay  ( got kwh )
E_solar=((PR_Ppeak*H*Area)*0.6/10000)+E_solar;
//still 10 devide it in android to avoid error in calculation
}

//Serial_write
void write_string(float f){
    dtostrf(f, 6,1, buff);
    fetch();
    Serial.write(n);
    Serial.write("\n");
}
void setDigitalLight(){
  
int i=charToInt(values[2]);
if(values[1]=='1')digitalWrite(i,1);
else digitalWrite(i,0);
  
}
int charToInt(char c){
  //check if this shit is correct
  int i=(int)c;
  i=i-48;
  return i;
}
void setAnalogLight(){
int pin=charToInt(values[1]);
String s="";
for(byte i=2;i<5;i++) s=s+(values[i]);
analogWrite(pin,s.toInt());  
 }
void fetchLight(){
if(values[0]=='d')setDigitalLight();
else setAnalogLight();
}

void lightMonitor(){
byte desired=200;
byte dif=0;
byte actual_light=analogRead(A1);
actual_light=map(actual_light,0,1023,0,255);

if(actual_light>desired){
  //change with gym pin
  dif=actual_light-desired;
  analogWrite(3,desired-dif);
}else analogWrite(3,desired);
}



