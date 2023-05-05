#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "board.h"

static char scoreBoard[][44] = {
	" ----------------------------------------- ",
	"| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |  10 |",
	" ----------------------------------------- ",
	"| | | | | | | | | | | | | | | | | | | | | |",
	" ----------------------------------------- ",
	"|   |   |   |   |   |   |   |   |   |     |",	
	" ----------------------------------------- "
};

void printBoard(void)
{
	system("clear");
	for (int i = 0; i < 7; ++i) {
		printf("%s\n", &scoreBoard[i][0]);		// scoreBoard[i]
	}
}

void setFrameScore(int frame, int cast, int score)
{
	char c;
	if (cast == 2 && (scoreBoard[3][(frame-1)*4 + 1] - '0' + score) == 10) {
		c = '/';
	} else if ( (cast == 1 && score == 10) || frame == 10 && (cast == 2 || cast == 3) && score == 10) {
		c = 'X';
	} else {
		c = score + '0';
	}
		
	scoreBoard[3][(frame-1)*4 + 2*cast-1] = c;
}

void setScore(int frame, int score)
{
	char str[10];
	sprintf(str, "%3d", score);
	strncpy(&scoreBoard[5][(frame-1) * 4 + 1], str, 3); 
}

