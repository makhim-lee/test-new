#include <SoftwareSerial.h>

#include "my_arduino_lib.h"
#include "my_motor_lib.h"

#define M1_pin  14
#define M2_pin  15
#define EN_pin  16

#define trigPin 13
#define echoPin 12

// joystick

#define jy A4

int joy_buf;

int s_flag = 0;
int t_flag = 0;

SoftwareSerial s(10,11);    

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(M1_pin, OUTPUT);
  pinMode(M2_pin, OUTPUT);
  pinMode(EN_pin, OUTPUT);

  pinMode(A4, INPUT);

  // 시리얼통신
  Serial.begin(9600);

  s.begin(9600);

  m_stop();
}
void loop() {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long distance = pulseIn(echoPin, HIGH) / 58;

  if ((distance <= 30 || distance >= 3000) && t_flag >= 0 && t_flag <6){            
    s_flag = 0;
    t_flag++;
    delay(150);
  }
  if(distance >= 50 && distance <= 1000 && t_flag != 0){
    t_flag--;
  }
  while ((distance >= 50 && distance <= 1000) && t_flag >= 5){         
    delay(3000);
    t_flag++;
    
    if(t_flag == 6){                                                 
      s_flag = 1;
      t_flag = 0;
    }
  }

  if(s_flag == 1){
    s.write('a');
    m_cw();
    delay(2000);

    m_stop();

    s_flag = 0;
  }


// joystick

  joy_buf = analogRead(jy);
  PORTD = 0x00;

  if(joy_buf <= 20 || joy_buf > 900) {
    s.write('a');
    
    m_cw();
    delay(2000);
  }
  m_stop();
  delay(300);
}
