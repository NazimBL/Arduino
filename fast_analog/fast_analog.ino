#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
  cbi(ADCSRA, ADPS2);
  cbi(ADCSRA, ADPS1);
  cbi(ADCSRA, ADPS0);
  CLKPR = (1 << CLKPCE);
  CLKPR=0x80;
  TCCR2B = TCCR2B & 0b11111000 | 0x08;
 
}

void loop() {
  // put your main code here, to run repeatedly:
long t0,t;
t0=micros();
analogRead(A0);
t=micros()-t0;
Serial.println((float)(t));
delay(1000);


}
