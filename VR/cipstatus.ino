int cipstatus(){
  esp.flush();
  int state;
  String response;
  esp.println("AT+CIPSTATUS");
  delay(100);
  for (int i=0 ; i<1000; i++) {
    if (esp.available()>0){
      response=esp.readString();
      break;
      }
    delay(1);
    }
  state=(contains(response,":"))?response.indexOf(":"):0;
  response=response.charAt(state+1);
  return response.toInt();
}
bool contains(String cmd,String resp){

int i=0;
int index=cmd.indexOf(resp);

if (index >=0 ) return true;
if (index == -1) return false;
}

/*
 int s=cipstatus();
Serial.println("CIPSTATUS="+String(s));
if (s==2 || s==4){
  
 if (sendHTTP()){ 
     Serial.println("Sent =D");
  }else {
  Serial.println("Socket Error");    
  }
 } else if(s==3){
   //sendHTTP(true);
   
  }else if(s==0){
    Serial.println("Reseting");
    while ( !sendExpect("AT+RST","OK")){
      delay(100);
      }
    esp.flush();

  }else if(s==5){
    Serial.println("No Acess Point ..");
    
    delay(1000);
  }*/

