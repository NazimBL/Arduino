bool sendExpect(String sendCMD, String expect, int timeout = 400) {
  sim900.flush();
  sim900.println(sendCMD);
  String response;
  delay(timeout);
  response = sim900.readString();
  Serial.println(response);
  return contains(response, expect);
}

bool contains(String cmd, String resp) {

  byte i = 0;
  int index = cmd.indexOf(resp);

  if (index >= 0 ) return true;
  if (index == -1) return false;
}

float measure() {
  for (i = 0 ; i < 40 ; i++) {
    stg1[i] = 0;
    for (j = 0; j < 100; j++) {
      temp = analogRead(A0);
      stg1[i] = (temp > stg1[i]) ? temp : stg1[i];
      delayMicroseconds(100);
    }
  }
  avg = 0;
  for (i = 0; i < 40; i++) {
    avg += stg1[i];
  }

  avg = avg / 40;
  current = 46.08 * (float)avg;
  //Serial.println(current);
  power = 220.0 * current;
  //Serial.print(",");
  //Serial.println(power*0.001);
  return power * 0.001;
}

