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
int cnt_2 = 1234;
int t_loop = 0;

struct chak{
  int time_loop;
  char hour;
  int8_t min;
  int8_t sec;
}time = {0,16,0,0};

struct chk{
  char key_flag;
  char run_flag;
  char bit_flag;
  char byie_flag;
  uint32_t kb_flag;
  char key_d[10];
  float dk_flag;
}flag = {0,0,0,0,0};

uint8_t key_buf, mode_cnt = 1;
char d_buf[20];

// #define byte_key 1
#define byte_key
char key_bit_in(){ //read bit feat.arduino mode
  char buf = '0';
  (d_in(UP_key) == 1) ? buf = '1' :  // askicode input
  (d_in(DN_key) == 1) ? buf = '2' : 
  (d_in(RUN_key) == 1) ? buf = '3' :
  (d_in(STOP_key)) ? buf = '4' :
  (d_in(MODE_key)) ? buf = '5' : buf = '0';

  while (PINC != 0x00) {} // <-- prevention duble thuch 
  
  if(buf != '0') flag.key_flag = 1; 
  return buf;
}

char key_byte_in(){ // read byte feat.Mcu mode
  char buf = 0;
  if(PINC != 0) {
    buf = (PINC & 0x3f);
    // sprintf(d_buf, "%d\n", buf);
    // Serial.println(d_buf);
    Serial.print(buf);
  }
}

void key_chk(){ // key chk
  flag.key_flag = 0; // flag reset
  tx_str("\033[2J");
  switch (key_buf) {
    case '1': 
    case 0x01:
      cnt_2++;
      tx_str("\x1b[0m");
      Serial.println(cnt_2); 
      break; //up key
    case '2': case 0x02 : cnt_2--; Serial.println(cnt_2); break;  //dn key
    case '3': case 0x04 : flag.run_flag = 1; break; // runkey
    case '4': case 0x08 : flag.run_flag = 0; break; // stop key
    case '5': case 0x10 :     // mdoe key
      mode_cnt++;
      if(mode_cnt >= 5) mode_cnt = 1; 
      break;
  }
}


void up_cnt(){
  for(; cnt_2 <= 9999; ){
    cnt_2 += 5;
    sprintf(d_buf, "Count = %4d", cnt_2);
    Serial.println(d_buf);
    _delay_ms(200);

    key_buf = key_bit_in();
    if(flag.key_flag == 1) key_chk(); break;
  }
  
}
void dn_cnt(){
  cnt_2 -= 5;
  sprintf(d_buf, "Count = %4d", cnt_2);
  Serial.println(d_buf);
  _delay_ms(200);
}

char key_rd(){
  #ifdef bit_key
    char buf = '0';
    buf = key_bit_in();
  #endif;

  #ifdef byte_key
    char buf = 0;
    buf = key_byte_in();
  #endif;
  return buf;
}

void setup() {
  DDRD = 0xff;
  DDRB = 0xff;
 
  // mcu 방식
  DDRC = 0x00;   //port input
  PORTC = 0xff;  //pullup on
  // Arduino방식
  //pinMode(D14, INPUT_PULLUP);
  //pinMode(D15, INPUT_PULLUP); .....~ D19
  Serial.begin(9600);
}

void loop() {
  // #ifdef bit_key
  //   key_buf = key_byte_in();
  // #endif 

  // #ifdef byte_key
  //   key_buf = key_bit_in();
  // #endif 

  key_buf = key_rd();

  if(flag.key_flag == 1) key_chk();
  _delay_ms(10);

  if(flag.run_flag){
    switch (mode_cnt) {
    case 1: up_cnt(); break;
    case 2: dn_cnt(); break;
    // case 3: env_cnt(); break; 
    // case 4: odd_cnt(); break;
    // case 5: mul(); break;
    }
  }
}