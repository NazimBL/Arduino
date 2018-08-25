bool contains(String cmd,String resp){

byte i=0;
int index=cmd.indexOf(resp);

if (index >=0 ) return true;
if (index == -1) return false;
}
boolean  SendExpect(char *command,char *response, int timeout = 800,byte op=0) {       
 String resp = "";
  Serial.flush();
  //sms
  if (op==0)
  {
    Serial.write(command);
    Serial.write('\r');
  }else if(op==2){
    Serial.write(command);
    Serial.write('\r');
    Serial.write('\n');
  } else {
    Serial.print(String((char)26));
  }
  //Serial.write(0x0D); hex equ of \r
  delay(10);
  long Time = millis();                                                             // take the sending command's time
  while ( (Time + timeout) > millis())                                              // wait for response from the module until the timeout is over
  {
    resp += Serial.readString();
    if (contains(resp, response)) {
      //debug(String(Time-millis()));                                             //time needed to execute the command
      break;                                                                      // if the response contains the awaited response break the loop
    }
  }
  Serial.flush();
  return contains(resp, response);                                                // if the response contains the awaited response returns 1 else 0
}                                               // if the response contains the awaited response returns 1 else 0

void split(String NMEA,char splitChar,String data[],byte dataSize){
  long j=0;
  //check variable 
  long k=0;
  for(byte a=0;a<dataSize;a++)data[a]="";
  for(byte i=0;j<NMEA.length();i++){ 
        while(NMEA.charAt(j)!=splitChar){
            if(k>3)break;
            if(NMEA.charAt(j)=='\0')k++;
            data[i].concat(NMEA.charAt(j));                     
            j++;                      
         }
        j++;               
  }  
}


