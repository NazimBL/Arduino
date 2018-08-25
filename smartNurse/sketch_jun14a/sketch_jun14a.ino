int bpm,bps=0;
int counter=0;
void setup() {
  // put your setup code here, to run once:
pinMode(13,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int pulse=analogRead(A0);
Serial.println(pulse);
if(pulse>550){
  digitalWrite(13,1);
  bps++;
}
else {
  digitalWrite(13,0); 
}
delay(10);


}
