byte signal_power() {
  sim900.flush();
  byte state;
  String response;
  sim900.println("AT+CSQ");
  delay(100);
  for (int i = 0 ; i < 1000; i++) {
    if (sim900.available() > 0) {
      response = sim900.readString();
      break;
    }
    delay(1);
  }
  state = (contains(response, ":")) ? response.indexOf(":") : 0;
  char a = response.charAt(state + 2);
  //char b=(int(response.charAt(state+3)) == 0)?NULL:response.charAt(state+3);
  char b = response.charAt(state + 3);
  if (b != "" || b != NULL || b != " ") {
    response = (String)a + "" + "" + (String)b;
  }
  else response = "fercha";
  Serial.println("Signal Power:" + String(response));
  int power = response.toInt();
  if (String(power) != response.toInt()) power = 10;
  return power;
}
