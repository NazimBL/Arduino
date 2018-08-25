void getGps(){
gps_tag=true;
while(gps_tag){ 
nmea_fetch(getNMEA());
delay(20);
}
}

