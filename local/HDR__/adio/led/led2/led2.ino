#define LED1 0
#define LED2 1
#define LED3 2
#define LED4 3
#define LED5 4
#define LED6 5
#define LED7 6
#define LED8 7
// 소스
#define ON 1
#define OFF 0
// 싱크
#define _ON 0
#define _OFF 1
unsigned char cnt = 0;

void setup() {
//  DDRD = 0xff;
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);

  digitalWrite(LED1, ON);
}

void loop() {
  digitalWrite(LED1, ON);
  digitalWrite(LED2, OFF);
  digitalWrite(LED3, ON);
  digitalWrite(LED4, OFF);   //PORTD = 0x0a;
  delay(500);
  
  digitalWrite(LED1, OFF);
  digitalWrite(LED2, ON);
  digitalWrite(LED3, OFF);
  digitalWrite(LED4, ON);     //PORTD = 0x05;
  delay(500);
}