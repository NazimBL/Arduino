String getNmea() {
  //think of reseting module if there is no data
   byte timeout=0;
   char *nmea=""; 
   while (!SendCommand("AT+GPS=1", "OK",500));
   while (!SendCommand("AT+GPSRD=3", "OK",1000));  
   Serial.flush();
   while (true) {
    //break o the loop if the module takes too long to answer
    if(timeout>=200)break;
    if (Serial.available()) {
      Serial.readBytesUntil('\n',nmea,40);
      if ( contains(nmea, "+GPSRD:") && contains(nmea,"$")) {
        String data=(String)nmea;
        return data.substring(data.indexOf("+GPSRD:") + 7);
      }else  return "";         
    }
    //change this and the timeout break value to calibrate more
    delay(30);
    timeout++;
  }
}
void fetchNmea(String nmea){
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
