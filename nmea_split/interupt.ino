long interrupt_temp;
long interrupt_times;
byte  interrupt_count = 0;
int  interrupt_clickmax = 1500;
int  interrupt_clickmini = 300;

void interrupt_call()
{
  interrupt_temp = millis();
  if (interrupt_count == 0) {
    interrupt_count++;
    interrupt_times = interrupt_temp;
  } else if (interrupt_count == 1) {
    if (((interrupt_temp - interrupt_times) > interrupt_clickmini) && ((interrupt_temp - interrupt_times) < interrupt_clickmax)) {
      interrupt_times = interrupt_temp;
      interrupt_count++;
    } else if ((interrupt_temp - interrupt_times) >= interrupt_clickmax) {
      interrupt_count = 1;
      interrupt_times = interrupt_temp;
    }
  } else if (interrupt_count == 2) {
    if (((interrupt_temp - interrupt_times) > interrupt_clickmini) && ((interrupt_temp - interrupt_times) < interrupt_clickmax)) {
      interrupt_times = interrupt_temp;
      interrupt_count++;
    } else if ((interrupt_temp - interrupt_times) > interrupt_clickmax) {
      interrupt_count = 1;
      interrupt_times = interrupt_temp;
    }
  }
  if (interrupt_count == 3) {
    interrupt_times = interrupt_temp;
    interrupt_count = 0;
    interrupt_sucess();
  }

}
void interrupt_sucess() {
  //after three clicks get gps location  then send it in an SMS
  gps_tag=false;
  sms_tag=true; 
}
