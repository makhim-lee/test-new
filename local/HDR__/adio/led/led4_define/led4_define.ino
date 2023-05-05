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

#define bit_set(ADDRESS, BIT) (ADDRESS |= (1<<BIT)) // bit hi
#define bit_clr(ADDRESS, BIT) (ADDRESS &= ~(1<<BIT)) // bit low
#define bit_chk(ADDRESS, BIT) (ADDRESS & (1<<BIT)) //bit chak
#define bit_tg(PORT, BIT) (PORT ^= (1<<BIT)) //bit togg

#define d_out(pin, value) digitalWrite(pin, value) //d_out(LED1, ON);

unsigned char cnt;

void setup() {
  DDRD = 0xff;
  PORTD = 0x00;
  bit_set(PORTD, LED1);
}

void loop() {

  PORTD = PORTD<<1;
  delay(500);
  if(bit_chk(PORTD, LED8)){
    PORTD = 0x01;
    delay(500);
  }
  // bit_tg(PORTD, LED1);
  // bit_clr(PORTD, LED5);           
  // delay(100);
  // PORTD ^= 0x02;
  // bit_set(PORTD, LED5);
  // delay(100);

  // d_out(LED1, ON);
  // delay(200);
  // d_out(LED1, OFF);
  // delay(200);
}
