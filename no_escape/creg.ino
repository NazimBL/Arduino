int creg() {
  sim900.flush();
  int state;
  String response;
  sim900.println("AT+CREG?");
  delay(100);
  for (int i = 0 ; i < 1000; i++) {
    if (sim900.available() > 0) {
      response = sim900.readString();
      break;
    }
    delay(1);
  }
  state = (contains(response, ":")) ? response.indexOf(",") : 0;
  if (state < 0)response = '4';
  else response = response.charAt(state + 1);
  return response.toInt();
}
