#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int8_t tg_flag = 0;  ///char
#include "c:\ado\lib\my_arduino_H.h"
#include "c:\ado\lib\my_fnd_lib.h"
#include "c:\ado\lib\my_key_lib.h"
#include "c:\ado\lib\io.h"
#include "c:\ado\lib\uart.c"

long cnt = 123456; // unsigned long
int cnt_2 = 0;


struct chk{
  char key_flag;
  char run_flag;
  char bit_flag;
  char byie_flag;
  uint32_t kb_flag;
  char key_d[10];
  float dk_flag;
}flag = {0,0,0,0,0};

uint8_t key_buf, mode_cnt = 0;

char key_bit_in()  //read bit feat.arduino mode
{
  char buf = '0';
  (d_in(UP_key) == 1) ? buf = '1' :  // askicode input
  (d_in(DN_key) == 1) ? buf = '2' : 
  (d_in(RUN_key) == 1) ? buf = '3' :
  (d_in(STOP_key)) ? buf = '4' :
  (d_in(MODE_key)) ? buf = '5' : buf = '0';

  while (PINC != 0x00) {}
  
  if(buf != '0') flag.key_flag = 1; 
  return buf;
}
char key_byte_in() // read byte feat.Mcu mode
{

}
void key_chk() // key chk
{
  flag.key_flag = 0; // flag reset
  switch (key_buf) {
    case '1': 
      cnt_2++;
      tx_str("\x1b[0m");
      tx_str("\033[2J");   
      Serial.println(cnt_2); 
      break; //up key
    case '2': cnt_2--; Serial.println(cnt_2); break;  //dn key
    case '3': flag.run_flag = 1; break; // runkey
    case '4': flag.run_flag = 0; break; // stop key
    case '5':     // mdoe key
      mode_cnt++;
      if(mode_cnt >= 5) mode_cnt = 1; 
      break;
  }
}

void setup() {
  DDRD = 0xf0;
  DDRB = 0xff;
 
  // mcu 방식
  DDRC = 0x00;   //port input
  PORTC = 0xff;  //pullup on
  Serial.begin(9600);

  attachInterrupt(0, key_irq, CHANGE); // RISING
  attachInterrupt(1, key_irq_1, FALLING);
}
void  key_irq(){// up
  Serial.println("RISING");
}
void  key_irq_1(){ //down
  Serial.println("FALLING");
}

void loop() {
  key_buf = key_bit_in();
  if(flag.key_flag == 1) key_chk();
  _delay_ms(10);

  if(flag.run_flag){
    switch (mode_cnt) {
    // case 1: up_cnt(); break;
    // case 2: dn_cnt(); break;
    // case 3: env_cnt(); break; 
    // case 4: odd_cnt(); break;
    // case 5: mul(); break;
    }
  }
}