#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int8_t tg_flag = 0;  ///char
#include "c:\ado\lib\my_arduino_H.h"
#include "c:\ado\lib\my_fnd_lib.h"

uint32_t cnt = 0; // unsigned long
int t_loop = 0;

struct chak{
  int time_loop;
  char hour;
  int8_t min;
  int8_t sec;
}time = {0,16,0,0};


void setup() {
  DDRD = 0xff;
  DDRB = 0xff;
}

void loop() {
  // for(time.sec = 1; time.sec <= 59; time.sec++){
  //   for(int i = 0; i <= 1000; i++){
  //     fnd_time(time.hour, time.min, time.sec);
  //     _delay_ms(1);  
  //   }
  //   (time.sec % 2 == 0)? tg_flag = 1 : tg_flag = 0;
  //   if (time.sec == 59) {
  //     time.min = time.min + 1;

  //   }
  //   if (time.min == 59) {
  //     time.hour = time.hour + 1;
  //     time.min = 0;
  //   }
  // }

  
  // for(time.sec = 1; time.sec <= 59; time.sec++){
  //   for(int i = 0; i <= 40; i++){
  //     fnd_dis(cnt);
  //     _delay_ms(1);  
  //   }
  //   (time.sec % 2 == 0)? tg_flag = 1 : tg_flag = 0;
  //   if (time.sec == 59) time.min = time.min + 1;
  //   if (time.min == 59) {
  //     time.hour = time.hour + 1;
  //     time.min = 0;
  //   }
  //   cnt = time.sec + (time.min * 100) + (time.hour * 10000) ;
  // }

  fnd_font_(); _delay_ms(1);// 알파벳 

}  
