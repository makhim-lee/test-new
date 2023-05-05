void setup() {
  // put your setup code here, to run once:

}
struct chak{
  int hour;
  int min;
  int sec;
}time;

void timetime(){

}

void loop() {

  time.sec = 0;
  time.min = 0;
  time.hour = 8;

  for(time.sec = 1; time.sec <= 59; time.sec++){
    delay(1000);
    if (time.sec == 59) {
      time.min = time.min + 1;
    }
    if (time.min == 59) {
      time.hour = time.hour + 1;
      time.min = 0;
    }
  }
  
  
  sprintf(d_buf,"time : %6d", timetime());
  lcd_gotoxy(1, 2);
  lcd_str(d_buf);
  

}
