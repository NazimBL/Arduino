boolean  SendCommand(String command, String response, int timeout = 400) {
  String resp = "";
  Serial.flush();
  Serial.println(command);
  delay(10);
  long int Time = millis();
  while ( (Time + timeout) > millis()) 
    {
      resp += Serial.readString();
      if (contains(resp, response)) break;
    }
    Serial.flush();
    return contains(resp, response);
  
}
String getNMEA() {
  //think of reseting module if there is no data
   byte timeout=0; 
   while (!SendCommand("AT+GPS=1", "OK",500));
   while (!SendCommand("AT+GPSRD=3", "OK",2000)); 
  delay(100);
  
  Serial.flush();
  while (true) {
    //break o the loop if the module takes too long to answer
    if(timeout>=200)break;
    if (Serial.available()) {
      String data = Serial.readString();
      if ( contains(data, "+GPSRD:") && contains(data,"$")) {
        return data.substring(data.indexOf("+GPSRD:") + 7);
      }else  return "";         
    }
    //change this and the timeout break value to calibrate more
    delay(30);
    timeout++;
  }
}
void nmea_fetch(String nmea){
split(nmea,'\n',satelites,6);
for(byte i=0;i<6;i++){
  split(satelites[i],',',data,25); 
  if(satelites[i].length()>50){        
    //0 is manufacturer index , 3/2 latitude/long index check again
    if(contains(data[0],"GPGGA") && data[2]!=""){   
    times=data[1];
    latitude=data[2];
    longitude=data[4];
    }else if(contains(data[0],"GPRMC") && data[3]!=""){
    times=data[1];
    latitude=data[3];
    longitude=data[5];  
    }else if(contains(data[0],"GPGLL") && data[3]!=""){
    times=data[5];
    latitude=data[1];
    longitude=data[3];
    }
  }  
  }
  if(longitude!="" && times!="" && latitude!=""){   
    while (!SendCommand("AT+GPS=0", "OK"));
//    Serial.print("final data: ");
//    Serial.println(longitude);
//    Serial.println(latitude);
//    Serial.println(times);
    Serial.flush();
    //global variable to end search and restart when neccessary
    gps_tag=false;      
  }     
}
