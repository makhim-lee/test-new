#include "c:\ado\lib\my_arduino_H.h"

//unsigned int cnt = 0;
unsigned char dp = 0x01; ///0b00000001
unsigned char flag = 0x01;
unsigned char d1[] = {0x00, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
unsigned char d2[6] = {0x81, 0x42, 0x24, 0x18};

void setup() {
  DDRD = 0xff;
  PORTD = 0x01;

}

void loop() {

/* Arr  */

for (char cnt = 0; cnt <= 4; cnt++) {
  PORTD = d2[cnt];
  delay(200);
}
for (char cnt = 4; cnt >= 0; cnt--) {
  PORTD = d2[cnt];
  delay(200);
}

/*   if
  PORTD = dp;
  if (flag == 0) dp <<= 1;
  else dp >>= 1;

  delay(200);
  if (dp == 0) {
    if (flag == 1) {
      dp = 0x01;
      flag = 0; 
    }else {
      dp = 0x80;
      flag = 1;
    }
  }
*/


  /*   while
  while(PORTD != 0x80){
    PORTD = PORTD<<1;
    delay(200);
  }
  while (PORTD != 0x01) {
    PORTD = PORTD>>1;
    delay(200);
  }
  */
}
