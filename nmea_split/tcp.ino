const String apn = "djezzy.internet";
bool cgatt(byte rst = 2);
boolean  SendCommand(String command, String response, int timeout = 400);

bool cipSend(String request) {
  if (SendCommand("AT+CIPSEND=" + String(request.length()), ">", 4000)) {
  if (SendCommand(request, "Done", 5000))
    {
      Serial.flush();
      return true;
    }
  }
  delay(1000);
  return false;
}
byte creg(){
  //when interrupt flag is true return this to get out of tcp loop 
  if(sms_tag)return (byte)21;
    Serial.flush();
    Serial.println("AT+CREG?");
    delay(1000);
    String creg_string=Serial.readString();
  if (contains(creg_string, "+CREG:")) {
    creg_string = creg_string.charAt(creg_string.indexOf(",") + 1);
  }else creg_string="4";
  return (byte) creg_string.toInt();   
}
bool config_gprs(byte rst = 0) {
  if (rst >= 3) {
    reset();
    return false;
  }
  rst++;
  switch (byte status = creg()) {
    case 1:
    case 5:
      if (cgatt()) {
        if (SendCommand("AT+CGDCONT=1,\"IP\",\"" + apn + "\"", "OK" , 1000)) {
          return true;
        }
      }
      break;
    //returned when interupt flag is on==> get out of the loop and send msg  
    case 21:smsInterupt();  
    default:
      delay(2000);
      break;
  }
  return config_gprs(rst);
}

bool sendTCP(String request) {
  if (config_gprs()) {
    if (!SendCommand("AT+CIPSTATUS", "CONNECT")) {
      if ( SendCommand("AT+CIPSTART=\"TCP\",\"46.101.207.185\",80", "CONNECT OK", 10000)) {
        delay(500);
        Serial.flush();
        return cipSend(request);
      }
    } else {
      return cipSend(request);
    }
  }
  return false;
}


bool cgatt(byte rst = 2) {
  //attach gprs
  if (rst <= 0) return false;
  rst--;
  if (!SendCommand("AT+CGATT?", "+CGATT:1")) {
    SendCommand("AT+CGATT=1", "OK", 4000);
    delay(500);
    return cgatt(rst);
  } else return true;
}

