#include <stdio.h>
#include "board.h"

int main(void)
{
	int scores[11] = {0, };
	
	int frameScores[11][3] = {0, };

	printBoard();
	
	for (int i = 1; i <= 10; ++i) {
		printf("%d frame first cast : ", i);
		scanf("%d", &frameScores[i][1]);
		setFrameScore(i, 1, frameScores[i][1]);
		printBoard();
		
		if (i > 1 && frameScores[i-1][1] + frameScores[i-1][2] == 10 && frameScores[i-1][1] != 10) {
			scores[i-1] = scores[i-2] + 10 + frameScores[i][1];	
			//printf("frame : %d score : %d\n", i-1, scores[i-1]);	
			setScore(i-1, scores[i-1]);
			printBoard();
		} else if (i > 2 && frameScores[i-2][1] == 10 && frameScores[i-1][1] == 10) {
			scores[i-2] = scores[i-3] + 10 + (10 + frameScores[i][1]);
			//printf("frame : %d score : %d\n", i-2, scores[i-2]);
			setScore(i-2, scores[i-2]);
			printBoard();
		}

		if (i == 10 || i != 10 && frameScores[i][1] != 10) {
			printf("%d frame second cast : ", i);
			scanf("%d", &frameScores[i][2]);
			setFrameScore(i, 2, frameScores[i][2]);
			printBoard();
		
			if (i > 1 && frameScores[i-1][1] == 10) {
				scores[i-1] = scores[i-2] + 10 + (frameScores[i][1] + frameScores[i][2]);
				//printf("frame : %d score : %d\n", i-1, scores[i-1]);
				setScore(i-1, scores[i-1]);
				printBoard();			
			}
						
			if (frameScores[i][1] + frameScores[i][2] < 10) {
				scores[i] = scores[i-1] + frameScores[i][1] + frameScores[i][2];
				//printf("frame : %d score : %d\n", i, scores[i]);
				setScore(i, scores[i]);
				printBoard();
			}
			
			// 10 frame bonus cast!
			if (i == 10 && frameScores[i][1] + frameScores[i][2] >= 10) {
				int bonus;
				printf("%d frame third cast : ", 10);
				scanf("%d", &bonus);
				setFrameScore(i, 3, bonus);
				printBoard();
				
				scores[10] = scores[9] + frameScores[10][1] + frameScores[10][2] + bonus;
				//printf("frame : %d score : %d\n", 10, scores[10]);
				setScore(10, scores[10]);
				printBoard();	
			}
		}
	}	

	return 0;
}
