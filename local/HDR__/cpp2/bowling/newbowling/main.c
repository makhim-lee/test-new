#include<stdio.h>
#include"board.h"

int main(void)
{
    int bonus;
    int bonusCast;
    int frameScores[11] = {0,};
    int scores[11][3] = {0,};  //1~9 frame
//first cast   
    for (int i = 1; i <= 10; ++i) {
        printBoard();
		do{// insert num in 1
            printf("%d frame first cast : ", i);
            scanf("%d", &scores[i][1]);
            if(scores[i][1] < 0 || scores[i][1] > 10){
                printf("over point error\n");
            }else{
                setScore (i, 1, scores[i][1]);
            }
        }while(scores[i][1] < 0 || scores[i][1] > 10);

		if (i >= 2 && scores[i-1][1] + scores[i-1][2] == 10 && scores[i-1][1] != 10) {
			bonus = scores[i][1];
            frameScores[i-1] = frameScores[i-2] + 10 + bonus;	
            setFrameScore(i-1, frameScores[i-1]);

		} else if (i >= 3 && scores[i-2][1] == 10 && scores[i-1][1] == 10) {
			bonus = scores[i][1] + 10;
            frameScores[i-2] = frameScores[i-3] + 10 + bonus;
            setFrameScore(i-2, frameScores[i-2]);
		}
        printBoard();
//second cast
		if (scores[i][1] != 10 || i == 10) {			
            do{// insert num in 2
                printf("%d frame first cast : ", i);
                scanf("%d", &scores[i][2]);
                if((scores[i][2] < 0) || (scores[i][1] + scores[i][2] > 10) && (i != 10)){
                    printf("over point error\n");
                }else{
                    setScore (i, 2, scores[i][2]);
                }
            }while((scores[i][2] < 0) || (scores[i][1] + scores[i][2] > 10) && (i != 10));

			if (i > 1 && scores[i-1][1] == 10) {
				bonus = scores[i][1] + scores[i][2];
                frameScores[i-1] = frameScores[i-2] + 10 + bonus;
                setFrameScore(i-1, frameScores[i-1]);
			}
						
			if (scores[i][1] + scores[i][2] < 10) {
                //bonus = 0
				frameScores[i] = frameScores[i-1] + scores[i][1] + scores[i][2];
                setFrameScore(i, frameScores[i]);
			}
		}
        printBoard();
	}
//bonus cast
    if(scores[10][1] + scores[10][2] >= 10){
        do{// insert num in bonus
            printf("bonus frame second cast : ");
            scanf("%d", &bonusCast);
            if(bonusCast < 0 || bonusCast > 10){
                printf("over point error\n");
            }else{
                setScore (10, 3, bonusCast);
            }
            
        }while(bonusCast < 0 || bonusCast > 10);
		
        frameScores[10] = frameScores[9] + scores[10][1] + scores[10][2] + bonusCast;
        setFrameScore(10, frameScores[10]);
        printBoard();
    }
    return 0;
}