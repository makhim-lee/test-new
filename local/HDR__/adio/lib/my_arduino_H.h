#ifndef my_arduino_H 
#define my_arduino_H

//포트정의
#define LED1 0
#define LED2 1
#define LED3 2
#define LED4 3
#define LED5 4
#define LED6 5
#define LED7 6
#define LED8 7
// 소스 회로
#define ON 1
#define OFF 0
#define _ON 0
#define _OFF 1

//비트연사
#define bit_set(ADDRESS, BIT) (ADDRESS |= (1<<BIT)) // bit hi
#define bit_clr(ADDRESS, BIT) (ADDRESS &= ~(1<<BIT)) // bit low
#define bit_chk(ADDRESS, BIT) (ADDRESS & (1<<BIT)) //bit chak
#define bit_tg(PORT, BIT) (PORT ^= (1<<BIT)) //bit togg
//
#define d_out(pin, value) digitalWrite(pin, value) //d_out(LED1, ON);
#define d_in(pin) digitalRead(pin) //d_out(LED1, ON);

#define A_out(pin, value) analogWrite(pin, value) 
#define A_in(pin) analogRead(pin) 

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

#endif