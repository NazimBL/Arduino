void send_by_force() {
  bool tag = false;

  for (int calc =0 ; calc < 4 ; calc++) {
    if (sendExpect("AT", "OK")){
      tag=true;
      break;
      }
    }
  if (!tag) powerUp();
}
