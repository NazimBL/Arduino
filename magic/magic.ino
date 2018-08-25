
char rec[1];
void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
pinMode(3,OUTPUT);
}

void loop() {


if(Serial.available()){
  Serial.readBytes(rec,1);
}
if(rec[0]=='1'){
  digitalWrite(3,1);
  Serial.println("On");
}
else if(rec[0]=='0')digitalWrite(3,0);

}
