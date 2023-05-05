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
}

void loop() {
  for (int i = 0; i <= 7; ++i) {
  R_MV;
  delay(220);
  }
  for (int i = 0; i <= 7; ++i) {
  L_MV;
  delay(220);
  }
}
