#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <avr/power.h>
bool on=true;

void setup() {
  pinMode(8,INPUT);
  digitalWrite(8,0);
  pciSetup(8);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if(on){

  Serial.println("Morning !");
  delay(500);
  sleep(1);
  delay(2000);
}else{
  Serial.println("Nighty");
  delay(2000);
  sleep(2);
}
}
void pciSetup(byte pin)
{
    *digitalPinToPCMSK(pin) |= bit (digitalPinToPCMSKbit(pin));  // enable pin
    PCIFR  |= bit (digitalPinToPCICRbit(pin)); // clear any outstanding interrupt
    PCICR  |= bit (digitalPinToPCICRbit(pin)); // enable interrupt for the group
}
ISR (PCINT0_vect) 
 {    
     on=!on;
 }

 void sleep(byte sleepMode)
{ 
    if(sleepMode==1){
      set_sleep_mode(SLEEP_MODE_IDLE);
      // Set sleep enable (SE) bit:
      sleep_enable();    
      power_twi_disable();
      power_spi_disable();
      //power_usart0_disable(); //Needed for serial.print
      //power_timer0_disable(); //Needed for delay and millis()
      power_timer1_disable();
      power_timer2_disable(); 
            
    }else{
      set_sleep_mode(SLEEP_MODE_PWR_DOWN);
      //power_all_disable();
      
    }
    // Put the device to sleep:
      sleep_mode();
      sleep_cpu (); 
    
  
}
