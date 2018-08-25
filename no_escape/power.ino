void powerUp()
{
  digitalWrite(9, LOW);
  delay(1000);
  digitalWrite(9, HIGH);
  delay(2000);
  digitalWrite(9, LOW);
  delay(3000);
}

void reset() {
  Serial.println("Reseting...");
  digitalWrite(9, LOW);
  delay(2000);
  digitalWrite(9, HIGH);
  delay(4000);
  digitalWrite(9, LOW);
  delay(3000);
  digitalWrite(9, HIGH);
  delay(4000);
  digitalWrite(9, LOW);
  delay(3000);
}

