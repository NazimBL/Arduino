boolean  SendExpect(char *command, char *response, int timeout = 400) {          // timeout set by defalt to 400 ms 
  String resp = "";
  Serial.flush();
  Serial.write(command);
  Serial.write('\r');
  delay(10);
  long int Time = millis();                                                         // take the sending command's time
  while ( (Time + timeout) > millis())                                              // wait for response from the module until the timeout is over
    {
      resp += Serial.readString();                                                  
      if (contains(resp, response)) break;                                          // if the response contains the awaited response break the loop                                      
    }
    Serial.flush();
    return contains(resp, response);                                                // if the response contains the awaited response returns 1 else 0
}
