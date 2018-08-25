String tcp_start= "AT+CIPSTART=\"TCP\",\"172.20.3.102\",11000";
bool sendHTTP(bool stat = false) {
  if (!stat){
  if (sendExpect(tcp_start, "OK",4000)) {
    Serial.println("Connected :D");
    String getcommand ="ST_IPADDRESS";
    if (sendExpect("AT+CIPSEND=" + String(getcommand.length()), ">")) {
      if (sendExpect(getcommand, "S")) {
        return true;
      }
    }
  }}else{
    Serial.println("Connected :D");
    String getcommand ="ST_IPADDRESS" ;
    if (sendExpect("AT+CIPSEND=" + String(getcommand.length()), ">")) {
      if (sendExpect(getcommand, "S")) {
        return true;
      }
    }
    }
return false;
}

String getCredit(String ussd){

  String resp="";
  bool empty=true;
  esp.flush();
  esp.println(ussd);
  delay(100);
  long Time= millis();
  while ((Time + 10000)> millis())                                              
    {
      resp += Serial.readString();                                                  
      if (contains(resp, "OK")) {
        empty=false;
        break;                                                                                            
      }
    }
  Serial.println(resp);  
 String d[5];
 split(resp,'+',d,4);

 split(d[3],',',d,2);
 d[1].remove(0,1);
 d[1].remove(12);
  
 if (empty)return "";
 //3 is the index of the returned string
 else return d[1];  
}
