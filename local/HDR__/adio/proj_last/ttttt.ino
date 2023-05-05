#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <LiquidCrystal.h>
const int rs = 8, en = 9, d4 =4, d5 =5, d6 =6, d7 =7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#include <MsTimer2.h>
#include <SoftwareSerial.h>
#include "my_arduino_lib.h"

SoftwareSerial s(10,11);    // 2:RX 3:TX
char data;

struct chak{
  int hour;
  int min;
  int sec;
}time = {9,16,0};

char d_buf[20];
int cnt = 1;

void time2_irq()
{
  time.sec++;

  if(time.sec > 59){
    time.sec = 0;
    time.min++;
    if(time.min > 59){
      time.min = 0;
      time.hour++;
    }
  }
}

void setup() {
  // 인터럽트 타임 호출

  MsTimer2::set(997, time2_irq);
  MsTimer2::start();

  // lcd port
  DDRD = 0xff;
  DDRB = 0x03;

  pinMode(12, OUTPUT);
  pinMode(13, INPUT);

  lcd.begin(16, 2);

  Serial.begin(9600);
  s.begin(9600);

}

void loop() {
  //통신 받기
  if(s.available())
  {
    data = s.read(); 
    Serial.println(data); 
  }

// cnt
  sprintf(d_buf,"Cnt : %2d", cnt);
  lcd.setCursor(0, 0);
  lcd.print(d_buf);

// 모터 작동후 작동
  if (data == 'a') {  
    lcd.clear();
    lcd.setCursor(5, 0);
    lcd.print("clear");
    delay(5000);

    cnt --;
    data = 'b';
    lcd.clear();
    sprintf(d_buf,"time %2d:%2d:%2d", time.hour, time.min, time.sec);
    lcd.setCursor(0, 1);
    lcd.print(d_buf);
  }
  // 패드 부족 
  if (cnt == 0) {
    lcd.clear();
    while(digitalRead(13) == 0){
      lcd.setCursor(5, 1);
      lcd.print("no more");
      digitalWrite(12, 1);
    }
    lcd.clear();
    cnt = 30;  
    digitalWrite(12, 0);
  }
}
