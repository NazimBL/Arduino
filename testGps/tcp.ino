const String apn = "djezzy.internet";
bool cgatt(byte rst = 2);

byte creg(){
    
  //if(config_tag)RomConfig();
  //if(sms_tag)smsInterupt();
  
    Serial.flush();
    Serial.write("AT+CREG?");
    Serial.write('\r');
    
    delay(1000);
    String creg_string=Serial.readString();
  if (contains(creg_string, "+CREG:")) {
    creg_string = creg_string.charAt(creg_string.indexOf(",") + 1);
  }else creg_string="4";
  return (byte) creg_string.toInt();   
}

bool cipSend(String request) {
  //we have to convert the string req
  //String stringCmd="AT+CIPSEND="+String(request.length()+1);
  String stringCmd="AT+CIPSEND="+String(49);
  char cmd[request.length()]={0};
  stringCmd.toCharArray(cmd,stringCmd.length()+1);
  
  if (SendExpect(cmd, ">", 4000)) {
  request.toCharArray(cmd,request.length()+1);  
    
  if (SendExpect(cmd, "Done",10000,2))
    {
      Serial.flush();
      return true;
    }
  }
  delay(1000);
  return false;
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
        String apnCmd="AT+CGDCONT=1,\"IP\",\"" + apn + "\"";
        char cmd[apnCmd.length()]={0};
        apnCmd.toCharArray(cmd,apnCmd.length()+1);
        if (SendExpect(cmd, "OK" , 1000)) {
          return true;
        }
      }
      break;
    //returned when interupt flag is on ==> get out of the loop and send msg  
    //case 21:smsInterupt();  
    default:
      delay(2000);
      break;
  }
  return config_gprs(rst);
}

bool sendTCP(String request) {
  if (config_gprs()) {
    if (!SendExpect("AT+CIPSTATUS", "CONNECT")) {
      if ( SendExpect("AT+CIPSTART=\"TCP\",\"46.101.207.185\",80", "CONNECT OK", 10000)) {
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
  if (!SendExpect("AT+CGATT?", "+CGATT:1")) {
    SendExpect("AT+CGATT=1", "OK", 4000);
    delay(500);
    return cgatt(rst);
  } else return true;
}
