

int temp=0;
void setup() {
  
pinMode(A1,INPUT);
Serial.begin(9600);

}

void loop() {

  
temp=analogRead(A1);
int val=map(temp,0,1023,-55,150);
Serial.println(val);
delay(1500);

}
