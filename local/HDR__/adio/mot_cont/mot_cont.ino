#include "c:\ado\lib\my_arduino_H.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

# define M1_pin 8
# define M2_pin 9
# define EN_pin 10
# define pan1_pin 11
# define pan2_pin 12

char run_flg = 0;
//moter
void m_cw() {d_out(10, 1); bit_set(PORTB, 0); d_out(9, 0);}
void m_ccw() {d_out(10, 1); d_out(8, 0); d_out(9, 1);}
void m_stop() {d_out(10, 1); d_out(8, 0); d_out(9, 0);}
void m_puz() {(run_flg == 0)? d_out(10, 0) : d_out(10, 1);}
//pan
void pan_cw() {d_out(11, 1); d_out(12, 0);}
void pan_ccw() {d_out(11, 0); d_out(12, 1);}
void pan_stop() {d_out(11, 0); d_out(12, 0);}

void setup() {
  DDRD = 0xfe;
  DDRB = 0X1f;
  Serial.begin(9600);
  m_stop();
  pan_stop();
}

void loop() {
  pan_cw();
  m_cw();
  delay(1000);
}
