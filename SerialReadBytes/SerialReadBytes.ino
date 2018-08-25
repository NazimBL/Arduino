int i=0;
char m='a';
char values[5];
char buff[7];


void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);

pinMode(13,OUTPUT);
digitalWrite(13,1);

}

void loop() {

int val=analogRead(A0);
float temp=(val*40)/1023;
 

if(Serial.available()){

Serial.readBytes(values,5);
m=values[0];
  
}

if(m=='t'){
  //Serial.write('z');
  dtostrf(temp, 6,1, buff);
  Serial.write(buff);
  Serial.write('\n');
}
  delay(50);
 


}
