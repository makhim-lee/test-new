/*
 * my_fnd.h
 *
 *  Created on: Oct 27, 2022
 *      Author: tj-bu
 */


#ifndef _MY_FND_LIB_
#define _MY_FND_LIB_


const unsigned char fnd_font[] =
{
   // 0,   1,   2,   3,   4,   5,   6,   7,   8,   9,   H,   L,   E,   o,   P,  F,
   0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x27,0x7f,0x6f,0x76,0x38,0x79,0x5c,0x73,0x71,
   // C,    d,    A,    u,    T,    r,   b,  blk
   0x39, 0x5e, 0x77, 0x1c, 0x44, 0x50, 0x7c, 0x00
}; // 읽기만 가능함

// fnd maseg display
#define O   0x0d   //o display
#define F   0x0f    // F display
#define H   0x0a    // H   "
#define L   0x0b    // L   "
#define E   0x0c    // E   "
#define P   0x0e    // P   "
#define C   0x10    // C   "
#define D   0x11    // d   "
#define A   0x12    // A   "
#define U   0x13    // u   "
#define T   0x14    // t   "
#define R   0x15    // r   "
#define b   0x16    // b   "
#define BLK 0x00   // fnd blk display

#define X100000 8
#define X10000 9
#define X1000 10
#define X100 11
#define X10 12
#define X1 13


int8_t scan = 0; //typedef char int8_t

void fnd_dis(uint32_t d_buf)
{
  scan++;
  if(scan > 7) scan = 1;

  switch(scan)
  {
    case 1: // x100000
	      d_out(X1, _OFF);  //fnd off
	      PORTD = fnd_font[d_buf/100000];
	      d_out(X100000, _ON); //fnd ON
	    break;
    case 2: // x10000
	      d_out(X100000, _OFF);  //fnd off
	      if(tg_flag == 1) PORTD = fnd_font[d_buf%100000/10000] | 0x80;
		  else PORTD = fnd_font[d_buf%100000/10000] & 0x7f;
	      d_out(X10000, _ON); //fnd ON
	    break;
    case 3: // x1000
	      d_out(X10000, _OFF);  //fnd off
	      PORTD = fnd_font[d_buf%10000/1000];
	      d_out(X1000, _ON); //fnd ON
	    break;
    case 4: // x100
	      d_out(X1000, _OFF);  //fnd off
	      PORTD = fnd_font[d_buf%1000/100] | 0x80;
	      d_out(X100, _ON); //fnd ON
	    break;
    case 5: // x10
	      d_out(X100, _OFF);  //fnd off
	      PORTD = fnd_font[d_buf%100/10];
	      d_out(X10, _ON); //fnd ON
	    break;
    case 6: // x1
	      d_out(X10, _OFF);  //fnd off
	      PORTD = fnd_font[d_buf%10] | 0x80;
	      d_out(X1, _ON); //fnd ON
	    break;
	}
}
void fnd_time(int8_t hour, char min, char sec)
{
  scan++;
  if(scan > 7) scan = 1;

  switch(scan)
  {
    case 1: // x100000
	      d_out(X1, _OFF);  //fnd off
	      PORTD = fnd_font[hour/10];
	      d_out(X100000, _ON); //fnd ON
	    break;
    case 2: // x10000
	      d_out(X100000, _OFF);  //fnd off
	      if(tg_flag == 1) PORTD = fnd_font[hour%10] | 0x80;
		  else PORTD = fnd_font[hour%10] & 0x7f;
	      d_out(X10000, _ON); //fnd ON
	    break;
    case 3: // x1000
	      d_out(X10000, _OFF);  //fnd off
	      PORTD = fnd_font[min/10];
	      d_out(X1000, _ON); //fnd ON
	    break;
    case 4: // x100
	      d_out(X1000, _OFF);  //fnd off
	      if(tg_flag == 1) PORTD = fnd_font[min%10] | 0x80;
		  else PORTD = fnd_font[min%10] & 0x7f;
	      d_out(X100, _ON); //fnd ON
	    break;
    case 5: // x10
	      d_out(X100, _OFF);  //fnd off
	      PORTD = fnd_font[sec/10];
	      d_out(X10, _ON); //fnd ON
	    break;
    case 6: // x1
	      d_out(X10, _OFF);  //fnd off
	      if(tg_flag == 1) PORTD = fnd_font[sec%10] | 0x80;
		  else PORTD = fnd_font[sec%10] & 0x7f;
	      d_out(X1, _ON); //fnd ON
	    break;
	}

}

void fnd_font_()
{
  scan++;
  if(scan > 7) scan = 1;

  switch(scan)
  {
    case 1: // x100000
	      d_out(X1, _OFF);  //fnd off
	      PORTD = fnd_font[A];
	      d_out(X100000, _ON); //fnd ON
	    break;
    case 2: // x10000
	      d_out(X100000, _OFF);  //fnd off
		  PORTD = fnd_font[D];
	      d_out(X10000, _ON); //fnd ON
	    break;
    case 3: // x1000
	      d_out(X10000, _OFF);  //fnd off
	      PORTD = fnd_font[C];
	      d_out(X1000, _ON); //fnd ON
	    break;
    case 4: // x100
	      d_out(X1000, _OFF);  //fnd off
	      PORTD = fnd_font[C];
	      d_out(X100, _ON); //fnd ON
	    break;
    case 5: // x10
	      d_out(X100, _OFF);  //fnd off
	      PORTD = fnd_font[E];
	      d_out(X10, _ON); //fnd ON
	    break;
    case 6: // x1
	      d_out(X10, _OFF);  //fnd off
	      PORTD = fnd_font[H];
	      d_out(X1, _ON); //fnd ON
	    break;
	}
}

#endif /* INC_MY_FND_LIB_H_ */
