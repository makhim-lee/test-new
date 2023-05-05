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

void setup(){
  DDRD = 0xff;
  PORTD = 0x00;
}

void loop(){
  for (cnt = 0; cnt <= 255 ; cnt++) {
    PORTD = cnt;
    delay(200);
  }
}

