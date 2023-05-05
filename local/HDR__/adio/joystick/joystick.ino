#include "c:\ado\lib\my_arduino_H.h"
#define jx A0
#define jy A1
#define j_sw 8
#define ry 1


void setup() {
  DDRD = 0xF4;
  DDRC = 0x00;
  DDRB = 0x01;
  PORTB = 0x01;
  Serial.begin(115200);
}
int ad_buf1, ad_buf2;
void SerialXY(){
  Serial.print("x = ");
  Serial.println(ad_buf1, DEC);
  Serial.print("y = ");
  Serial.println(ad_buf2, DEC);
}

void loop() {
  ad_buf1 = A_in(jx);
  ad_buf2 = A_in(jy);
  SerialXY();
  PORTD = 0x00;

  if(ad_buf2 <= 10) d_out(4, 1);
  else if (ad_buf2 > 1000) d_out(5, 1);
  if(ad_buf1 <= 10) d_out(6, 1);
  else if (ad_buf1 > 990) d_out(7, 1);

  (d_in(j_sw) == 0) ? d_out(ry, 0) : d_out(ry, 1);
}
