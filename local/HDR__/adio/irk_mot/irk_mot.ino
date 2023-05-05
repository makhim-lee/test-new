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
//
volatile unsigned char rx_buf[20];
volatile char rx_end_flag = 0;
volatile char rx_cnt = 0;
char d_buf[30];
unsigned int cnt;
//moter
void m_cw()   {d_out(10, 1); d_out(8, 1); d_out(9, 0); d_out(3, 1); d_out(4, 0);}
void m_ccw()  {d_out(10, 1); d_out(8, 0); d_out(9, 1); d_out(4, 1); d_out(3, 0);}
void m_stop() {d_out(10, 1); d_out(8, 0); d_out(9, 0); d_out(4, 0); d_out(3, 0);}
void m_puz()  {(run_flg == 0)? d_out(10, 0) : d_out(10, 1);}
//com_chk
void com_chk()
{
  rx_end_flag = 0;
  sprintf(d_buf, "%s", rx_buf);
  Serial.println(d_buf);

  switch(d_buf[0])
  {
    case 0x30: m_ccw(); Serial.println("k"); break;
    case 0x31: m_stop(); break;
    default: Serial.println("ky"); break;
  }
  memset(rx_buf, 0, sizeof(char) * 20);
}

void setup() {
  DDRD = 0xfe;
  DDRB = 0x07;
  Serial.begin(9600);
  m_stop();
  rx_end_flag = 0;
}

void loop() {
  if(rx_end_flag == 1) com_chk();
  bit_tg(PORTD, LED8);
}
// 이벤트처리
void serialEvent()
{
  unsigned char buf;
  if(Serial.available()){
    buf = Serial.read(); 
    if(buf == 0x0d){
      rx_cnt = 0;
      rx_end_flag = 1;
    }else{
      rx_buf[rx_cnt] = buf;
      rx_cnt++;
    }
  }
}
/*interupt
void serialEvent()
{
    Serial.println(Serial.readString());
}*/

/* 폴링방식
  if(Serial.available()){
    //rx_buf = Serial.read();
    Serial.println(Serial.readString());
}*/
  
  
