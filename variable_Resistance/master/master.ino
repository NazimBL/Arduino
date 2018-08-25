
#include <Wire.h>
void setup() {
  // put your setup code here, to run once:
 Wire.begin();
}
byte x = 0;
void loop() {
  // put your main code here, to run repeatedly:

 Wire.beginTransmission(8); // transmit to device #8
  Wire.write("x is ");        // sends five bytes
  Wire.write(x);              // sends one byte
  Wire.endTransmission();    // stop transmitting

  x++;
  delay(500);

}
