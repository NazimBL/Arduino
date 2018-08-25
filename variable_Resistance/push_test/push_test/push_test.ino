void setup() {
  
pinMode(7,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

if(digitalRead(7)==0)Serial.println("OPENNN");

else Serial.println("Closed");

delay(15);

}
