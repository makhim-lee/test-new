# include<stdio.h>
/*
#define BOLD 0x01
#define ITALIC 0x02
#define SHADOW 0x04
#define UL 0x08
*/
#define BOLD   (0x01 << 0)
#define ITALIC (0x01 << 1)
#define SHADOW (0x01 << 2)
#define UL     (0x01 << 3)


int main(void)
{
/*
	//int isBold, isTtalic, isShadow, isUL;
	cher isBold, isTtalic, isShadow, isUL;
	
	isBold = 1;
	isTtalic = 1;
	isShadow = 1;
	isBold = 0:
*/
/*
	unsigned char attr;
	attr = attr ^ attr;
	attr = attr | 0x01;
	attr = attr | (0x02 + 0x04);
	attr = attr & ~0x01;
*/	
	unsigned char attr;
	attr = attr ^ attr;
	attr = attr | BOLD;
	attr = attr | (ITALIC + SHADOW);
	attr = attr & ~BOLD;
	
	
	printf("attr: 0x%02x\n", attr);
	return 0;
}
