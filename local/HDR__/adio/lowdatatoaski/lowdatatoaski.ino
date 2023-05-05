// std lib
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// my lib
#include "c:\ado\lib\my_arduino_H.h"
// prj func
//define
unsigned int cnt;
char d_buf[30];

void setup() {
  DDRD = 0xff;
  Serial.begin(115200); // 115200
}
void loop() {
  for(cnt = 0 ; cnt <= 9999; cnt++)
  {
    Serial.write(cnt/1000 + 0x30);
    Serial.write(cnt%1000/100 + '0');
    Serial.write(cnt%100/10 + 0x30);
    Serial.write(cnt%10 + '0');
    Serial.write('\n');
    Serial.write('\007');
    // 실습 4

    sprintf(d_buf, "Counter = %4d\n", cnt);
    Serial.write(d_buf);
    delay(200);

  }

 //===============================================

 

  // 실습1

  //Serial.print("song k\n");

  //delay(500);

}

 


/* 시리얼 인터럽트 방식 */

/*

void setup(){

    Serial.begin(9600);

    Serial.println("Serial Port Connected!");

}

 

}