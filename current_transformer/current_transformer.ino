#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
int a[455];
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
  sbi(ADCSRA, ADPS2);
  cbi(ADCSRA, ADPS1);
  cbi(ADCSRA, ADPS0);
 
}

void loop() {
  // put your main code here, to run repeatedly:
for(int i=0;i<450;i++){
  a[i]=analogRead(A0);
  Serial.println(a[i]);
}

Serial.println("end");
}
