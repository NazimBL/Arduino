char c;
void setup() {

pinMode(13,OUTPUT);
Serial.begin(9600);
}

void loop() {

while(Serial.available()){
c=Serial.read();

if(c=='o') {
  digitalWrite(13,1);
  Serial.println("Led is on");
}
  
  else {
    digitalWrite(13,0);
    Serial.println("led is off");
  }
 
}

}
