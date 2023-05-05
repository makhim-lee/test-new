#ifndef __My_Arduino_LIB__
#define __My_Arduino_LIB__


//define
#define M1_pin  14
#define M2_pin  15
#define EN_pin  16


void m_cw()
{
  d_out(EN_pin, ON);
  d_out(M1_pin, 1);
  d_out(M2_pin, 0);
}


void m_stop()
{
  bit_clr(PORTB, M1_pin);
  bit_clr(PORTB, M2_pin);
  d_out(EN_pin, OFF);
}


#endif

