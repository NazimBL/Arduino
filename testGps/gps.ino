String getNmea() {
  //think of reseting module if there is no data
   byte timeout=0;
   char *nmea="";
   while (!SendCommand("AT+GPS=1", "OK",500));
   while (!SendCommand("AT+GPSRD=3", "OK",1000));  
   Serial.flush();
   while (true) {
    //break o the loop if the module takes too long to answer
    //if(timeout>=200)break;
    if (Serial.available()) {
      char c=(char)Serial.read();
      nmea +=c;
      if(c=='\n'){               
        if ( contains(nmea, "+GPSRD:") && contains(nmea,"$")) {
              return nmea;
        }else return "";               
      }
    } 
    //delay(30);
   // timeout++;  
  }
}
