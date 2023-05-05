#include "c:\ado\lib\my_arduino_H.h"

const int trig = 4;
const int echo = 2;

void setup() {
  DDRD = 0x10;
  Serial.begin(115200);
}
void loop() {
  //send ultrasound 10ms
  d_out(trig, 1);
  delayMicroseconds(10);
  d_out(trig, 0);

  long distance = pulseIn(echo, HIGH) / 58;
  Serial.print(distance, DEC);
  Serial.println("cm");
  delay(200);
}