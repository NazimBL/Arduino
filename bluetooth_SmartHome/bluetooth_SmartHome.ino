char values[5];

void setup() {
Serial.begin(9600);
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(13,OUTPUT);

}

void loop() {

if(Serial.available()>0){
Serial.readBytes(values,5);
fetchLight();
} 


delay(500);
}
void setDigitalLight(){
  
int i=charToInt(values[2]);
if(values[1]=='1')digitalWrite(i,1);
else digitalWrite(i,0);
  
}
int charToInt(char c){
  int i=(int)c;
  i=i-48;
  return i;
}
void setAnalogLight(){
int pin=charToInt(values[1]);
String s="";
for(int i=2;i<5;i++){

  s=s+(values[i]);
}

analogWrite(pin,s.toInt());  
 }
 void fetchLight(){
if(values[0]=='d'){
//digital
setDigitalLight();
}
else{
//analog  
setAnalogLight();
}
 
}

