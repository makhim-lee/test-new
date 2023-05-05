#include<stdio.h>

int main(void)
{
    int bonus;
    int bonusCast;
    int frameScores[11] = {0,};
    int scores[11][3] = {0,};  //1~9 frame
//first cast   
    for (int i = 1; i <= 10; ++i) {
		do{// insert num in 1
            printf("%d frame first cast : ", i);
            scanf("%d", &scores[i][1]);
            if(scores[i][1] < 0 || scores[i][1] > 10){
                printf("over point error\n");
            }
        }while(scores[i][1] < 0 || scores[i][1] > 10);

		if (i >= 2 && scores[i-1][1] + scores[i-1][2] == 10 && scores[i-1][1] != 10) {
			bonus = scores[i][1];
            frameScores[i-1] = frameScores[i-2] + 10 + bonus;	
			printf("frame : %d score : %d\n", i-1, frameScores[i-1]);	
		} else if (i >= 3 && scores[i-2][1] == 10 && scores[i-1][1] == 10) {
			bonus = scores[i][1] + 10;
            frameScores[i-2] = frameScores[i-3] + 10 + bonus;
			printf("frame : %d score : %d\n", i-2, frameScores[i-2]);
		}
//second cast
		if (scores[i][1] != 10 || i == 10) {			
            do{// insert num in 2
                printf("%d frame first cast : ", i);
                scanf("%d", &scores[i][2]);
                if(scores[i][2] < 0 || scores[i][1] + scores[i][2] > 10){
                    printf("over point error\n");
                }
            }while(scores[i][2] < 0 || scores[i][1] + scores[i][2] > 10);

			if (i > 1 && scores[i-1][1] == 10) {
				bonus = scores[i][1] + scores[i][2];
                frameScores[i-1] = frameScores[i-2] + 10 + bonus;
				printf("frame : %d score : %d\n", i-1, frameScores[i-1]);
			}
						
			if (scores[i][1] + scores[i][2] < 10) {
                //bonus = 0
				frameScores[i] = frameScores[i-1] + scores[i][1] + scores[i][2];
				printf("frame : %d score : %d\n", i, frameScores[i]);
			}
		}
	}
//bonus cast
    if(scores[10][1] + scores[10][2] >= 10){
        do{// insert num in bonus
            printf("bonus frame second cast : ");
            scanf("%d", &bonusCast);
            if(bonusCast < 0 || bonusCast > 10){
                printf("over point error\n");
            }
        }while(bonusCast < 0 || bonusCast > 10);
		
        frameScores[10] = frameScores[9] + scores[10][1] + scores[10][2] + bonusCast;
        printf("frame : 10 score : %d\n", frameScores[10]);
    }
    return 0;
}