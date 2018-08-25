
void setup() {
  // put your setup code here, to run once:
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
Serial.begin(9600);
digitalWrite(10,0);
digitalWrite(11,0);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()){

  char m=Serial.read();
  if(m=='1'){
    digitalWrite(10,1);
    digitalWrite(11,0);
    Serial.println("open");
    delay(4000);
    m='v';
    
  }
  else if(m=='0'){
    digitalWrite(10,0);
    digitalWrite(11,1);
    Serial.println("close");
    delay(4000);
    m='v';
  }
 else{
    
    digitalWrite(10,0);
    digitalWrite(11,0);
    Serial.println("fuck");
 }
    digitalWrite(10,0);
    digitalWrite(11,0);
      
    
}
}
