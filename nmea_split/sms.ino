String sosNumber="0021367002323";

bool sendSMS(String message)
{             
  //Set the SMS in text mode
  if (SendCommand("AT+CMGF=1","OK",5000)){
    if (SendCommand("AT+CMGS="+sosNumber,">",2000)){
      Serial.print(message);
      if(SendCommand((String)(char)26,"OK",2000)){
        return true;
      }
    }
  }
}
void smsInterupt(){
  getGps();
  String message=latitude+","+longitude;
  while(!sendSMS(message));
  sms_tag=false;
}

