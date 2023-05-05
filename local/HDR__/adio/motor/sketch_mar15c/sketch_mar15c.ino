#include "c:\ado\lib\my_arduino_H.h"
volatile boolean state = false;
const int ledPin = 13;

void m_cw()   {d_out(10, 1); d_out(8, 1); d_out(9, 0); d_out(3, 1); d_out(4, 0);}
void m_ccw()  {d_out(10, 1); d_out(8, 0); d_out(9, 1); d_out(4, 1); d_out(3, 0);}
void m_stop() {d_out(10, 1); d_out(8, 0); d_out(9, 0); d_out(4, 0); d_out(3, 0);}
void m_puz()  {(run_flg == 0)? d_out(10, 0) : d_out(10, 1);}


void setup(){
  DDRD = 0xfe;
    pinMode(ledPin,OUTPUT);
    Serial.begin(9600);
    Serial.println("Serial Port Connected!");
}
 
void loop(){
  if(state == 1){
    m_cw();
    delay(1000);
  }else m_stop();
}
/* 시리얼 수신 ISR */
void serialEvent(){
    char cTemp = Serial.read();
    if(cTemp == '1'){
        state = true;
    }
    else{
        state = false;
    }
 
}
