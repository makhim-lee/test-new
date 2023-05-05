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

void byte_out(unsigned char data);
unsigned char cnt;

void setup(){
  DDRD = 0xff;
  PORTD = 0x00;
}

void loop(){
  for(cnt = 0; cnt <= 255; cnt++){
    byte_out(cnt);
    delay(200);
    d_out(LED8, 1);
    delay(200);
    d_out(LED8, 0);
    delay(200);
  }


}

void byte_out(unsigned char data)
{
  d_out(LED1, data%2); // bit 0 = 1sb
  d_out(LED2, data/2%2); // bit 1
  d_out(LED3, data/4%2); // bit 2
  d_out(LED4, data/8%2); // bit 3
  d_out(LED5, data/16%2); // bit 4
  d_out(LED6, data/32%2); // bit 5
  d_out(LED7, data/64%2); // bit 6
  d_out(LED8, data/128%2); // bit 7 = msb
}