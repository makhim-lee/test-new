#include <stdio.h>

int main(void)
{
	int scores[11] = {0, };
	
	// 1 ~ 9 frame
	int frameScores[10][3] = {0, };
	
	for (int i = 1; i <= 9; ++i) {
		printf("%d frame first cast : ", i);
		scanf("%d", &frameScores[i][1]);
		
		if (i > 1 && frameScores[i-1][1] + frameScores[i-1][2] == 10 && frameScores[i-1][1] != 10) {
			scores[i-1] = scores[i-2] + 10 + frameScores[i][1];	
			printf("frame : %d score : %d\n", i-1, scores[i-1]);	
		} else if (i > 2 && frameScores[i-2][1] == 10 && frameScores[i-1][1] == 10) {
			scores[i-2] = scores[i-3] + 10 + (10 + frameScores[i][1]);
			printf("frame : %d score : %d\n", i-2, scores[i-2]);
		}

		if (frameScores[i][1] != 10) {
			printf("%d frame second cast : ", i);
			scanf("%d", &frameScores[i][2]);
		
			if (i > 1 && frameScores[i-1][1] == 10) {
				scores[i-1] = scores[i-2] + 10 + (frameScores[i][1] + frameScores[i][2]);
				printf("frame : %d score : %d\n", i-1, scores[i-1]);
			}
						
			if (frameScores[i][1] + frameScores[i][2] < 10) {
				scores[i] = scores[i-1] + frameScores[i][1] + frameScores[i][2];
				printf("frame : %d score : %d\n", i, scores[i]);
			}
		}
	}	
	
	// 10 frame
	int frameScores10[4] = {0, };

	printf("10 frame first cast : ");
	scanf("%d", &frameScores10[1]);
	
	// 9 frame / --> print 9 frame score
	if (frameScores[9][1] + frameScores[9][2] == 10 && frameScores[9][1] != 10) {
		scores[9] = scores[8] + 10 + frameScores10[1];
		printf("frame : %d score : %d\n", 9, scores[9]);

	// 8 frame X, 9 frame X, --> print 8 frame score	
	} else if (frameScores[8][1] == 10 && frameScores[9][1] == 10) {
		scores[8] = scores[7] + 10 + (10 + frameScores10[1]);
		printf("frame : %d score : %d\n", 8, scores[8]);
	}
	
	printf("10 frame second cast : ");
	scanf("%d", &frameScores10[2]);
	
	// 9 frame X --> print 9 frame score
	if (frameScores[9][1] == 10) {
		scores[9] = scores[8] + 10 + (frameScores10[1] + frameScores10[2]);
		printf("frame : %d score : %d\n", 9, scores[9]);
	}

	// 10 frame first + second < 10 --> 10 frame score	
	if (frameScores10[1] + frameScores10[2] < 10) {
		scores[10] = scores[9] + frameScores10[1] + frameScores10[2];
		printf("frame : %d score : %d\n", 10, scores[10]);
				
	} else {
		printf("10 frame third cast : ");
		scanf("%d", &frameScores10[3]);
		
		scores[10] = scores[9] + frameScores10[1] + frameScores10[2] + frameScores10[3];
		printf("frame : %d score : %d\n", 10, scores[10]);
	}

	return 0;
}
