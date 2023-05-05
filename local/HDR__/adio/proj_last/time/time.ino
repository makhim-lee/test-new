#include <MsTimer2.h>

struct chak{
  int hour;
  int min;
  int sec;
}time = {0,0,0};


void time2_irq()
{

  time.sec++;
  Serial.println(time.sec, DEC);

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

  // hw 로리지널 uart
  Serial.begin(9600);          // Serial 통신 초기화
  // 소프트웨어 시리얼 포트

  MsTimer2::set(1000, time2_irq);
  MsTimer2::start();
}

 

void loop() {


}
