int sensor=0;
void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);

}

void loop() {

sensor=analogRead(A1)*0.48828125;
int var=map(sensor,0,1024,-55,150);
  Serial.println(var);
  delay(1000);
}
