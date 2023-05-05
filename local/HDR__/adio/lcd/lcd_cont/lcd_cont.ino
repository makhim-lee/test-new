#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// #include <LiquidCrystal.h>
// const int rs = 8, en = 9, d4 =4, d5 =5, d6 =6, d7 =7;
// LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#include "c:\ado\lib\my_arduino_H.h"

#define LCD_IF_8_Bit 1
#define LCD_PD 1 // headfile upsied
#include "c:\ado\lib\my_lcd_lib_v2_3.h"

void setup() {
  DDRD = 0xff;
  DDRB = 0xff;
  lcd_init();

  //lcd test
  lcd_gotoxy(3, 1);
  lcd_str("Yoon Jae");
  lcd_gotoxy(11, 2);  // lcd.setCursor (11. 2)
  lcd_send('k'); // lcd.write('k');
  LCD_CLR;
}

char d_buf[20];
int cnt = 1234;

void loop() {
  // lcd_gotoxy(10, 1);
  // lcd_send(cnt/1000 + 0x30);
  // lcd_send(cnt%1000/100 + 0x30);
  // lcd_send(cnt%100/10 + 0x30);
  // lcd_send(cnt%10 + 0x30);

  // lcd_gotoxy(10, 2);
  // lcd_send((9999-cnt)/1000 + 0x30);
  // lcd_send((9999-cnt)%1000/100 + 0x30);
  // lcd_send((9999-cnt)%100/10 + 0x30);
  // lcd_send((9999-cnt)%10 + 0x30);

  // cnt ++;
  // delay(200);
  // if (cnt == 5000) cnt = 1234;

    
  sprintf(d_buf,"UP Cnt : %4d", cnt);
  lcd_gotoxy(1, 1);
  lcd_str(d_buf);
  sprintf(d_buf,"DN Cnt : %4d", 9999 - cnt);
  lcd_gotoxy(1, 2);
  lcd_str(d_buf);
  cnt ++;
  delay(500);
  if (cnt == 5000) cnt = 1234;
}
