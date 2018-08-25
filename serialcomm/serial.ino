bool contains(String cmd,String resp){

byte i=0;
int index=cmd.indexOf(resp);

if (index >=0 ) return true;
if (index == -1) return false;
}

byte SendCommand(char *command,char *response,int timeout=400) {
  //Serial.setTimeout(400);
  char *resp = "";
  Serial.flush();
  Serial.write(command);
  delay(10);
  long  Time = millis();
  while ( (Time + timeout) > millis()) 
    {
      Serial.readBytesUntil('\r',resp,30);         
      if(contains(resp,command)){
        //echo ok
        mine.println("Echo ok");
        *resp="";
        Serial.readBytesUntil('\r',resp,30);
          if (contains(resp, response)) {
            mine.println("response ok");       
            return 1;           
          }else{
            mine.println("echo ok,no response");
              return 2;
          }          
      }else{
         mine.println("no echo");
         return 0;        
      }      
    }
    mine.println("Time out");
    return 4;    
}

