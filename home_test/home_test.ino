bool tag=true;
char values[5]="a6220";
char m;
byte in1=13;
byte in2=12;
void setup() {

Serial.begin(9600);
 pinMode(in1,INPUT);
  pinMode(in2,INPUT);
  for(int i=3;i<12;i++)pinMode(i,OUTPUT);

}

void loop() {
if(Serial.available()){

  Serial.readBytes(values,5);
  m=values[0];
  Serial.println(m);
}
  
 
  for(int i=3;i<8;i++)digitalWrite(i,1);

}

