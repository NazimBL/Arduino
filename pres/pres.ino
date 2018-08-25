int push1 = 7;
int in1 = 5;
int in2 = 6;
int push2 = 8;
char m ;

void setup() {

  Serial.begin(9600);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(push1, INPUT);
  pinMode(push2, INPUT);
}


void loop() {
  int p = digitalRead(push1);
  int p2 = digitalRead(push2);
  if (Serial.available()) {
    m = Serial.read();
  }

  if ((m == '1') && (p == LOW)) {
    digitalWrite( in1 , LOW);
    digitalWrite( in2, HIGH);
    delay(1300);
    m='s';

  }
  else if ((m == '0') ) {
    digitalWrite( in1 , HIGH);
    digitalWrite( in2, LOW);
    delay(1300);
    m='s';

  }
  else {
    digitalWrite( in1 , LOW);
    digitalWrite( in2, LOW);
  }
 
  
}
