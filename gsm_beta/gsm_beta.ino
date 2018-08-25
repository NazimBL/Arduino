void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  String request="GET http://46.101.207.185/api.php?id=4&data=45\r\n";
  while(!sendTCP(request)); 
  delay(70);

}
