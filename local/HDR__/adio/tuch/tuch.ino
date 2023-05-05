#include "c:\ado\lib\my_arduino_H.h"
#define A_touch A2 
#define D_touch 2

void setup() {
  DDRD = 0xF4;
  DDRC = 0x00;
  Serial.begin(115200);
}
int dig, anal;
void SerialXY(){
  Serial.print("Digtal = ");
  Serial.println(dig);
  Serial.print("Analog = ");
  Serial.println(anal);
}

void loop() {
  dig = d_in(D_touch);
  anal = A_in(A_touch);
  SerialXY();
  delay(500);
  
}