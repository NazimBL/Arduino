bool SendCommand(char *cmd,char *response,int timeout=800){

char *resp="";
byte count=0;
  Serial.flush();
  Serial.write(cmd);
  Serial.write('\r');
  //Serial.write(0x0D); hex equ of \r
  delay(10);
  long Time = millis();                                                             // take the sending command's time
  while ( (Time + timeout) > millis())                                              // wait for response from the module until the timeout is over
    {
      char c=(char)Serial.read();
      resp +=c;
      if(c=='\r')count++;
      if(count==2)return contains(resp, response);
                                                         
      if (contains(resp, response)) {
        //debug(String(Time-millis()));                                             //time needed to execute the command
        break;                                                                      // if the response contains the awaited response break the loop                                      
      }
    }
    Serial.flush();
    return contains(resp, response);  
}

