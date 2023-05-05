#include<stdio.h>


int main(void){
    int frame1[10];
    int frame2[10];
    int point[10] = {-1,};
    int bonus1, bonus2;
    for(int i = 0; i < 10; ++i){   
        printf("                            start %d frame\n", i + 1);
        do{
            printf("%d flame one : ", i + 1);
            scanf("%d", &frame1[i]);
            if(frame1[i] > 10){
                printf("error\n");
            }
        }while(frame1[i] > 10);
     
        if(frame1[i] == 10){
            if(frame1[i - 2] == 10 && frame1[i - 1] == 10 && i > 1){
                point[i-2] = 30;
                frame1[i-2] = 11;
                printf("  %d flame %d\n", i - 1, point[i - 2]);
            }
        }else if(frame1[i - 1] + frame2[i - 1] == 10 && frame1[i - 1] != 10 && i >= 1){
            point[i - 1] = 10 + frame1[i];
            printf("   %d flame : %d\n", i, point[i - 1]);
        }

        if(frame1[i] != 10){
            do{
                printf("%d flame two : ", i + 1);
                scanf("%d", &frame2[i]);
                if(frame1[i] + frame2[i] > 10){
                    printf("error\n");
                }
            }while(frame1[i] + frame2[i] > 10);
          
            point[i] = frame1[i] + frame2[i];
            if (frame1[i - 1] == 10){
                if (frame1[i - 2] == 10){
                    point[i - 2] = frame1[i - 2] + frame1[i - 1] + point[i];
                    printf("   %d flame : %d\n", i - 1, point[i - 2]);
                }else{
                    point[i - 1] = frame1[i - 1] + point[i];
                    printf("   %d flame : %d\n", i, point[i - 1]);
                }
            }
            if(frame1[i] + frame2[i] < 10){
                printf("   %d flame : %d\n", i + 1, point[i]);
            }  
        }
        if (i == 9){
            do{
                printf("%d flame bonus : ", i + 1);
                scanf("%d", &bonus1);
                if(bonus1 > 10){
                    printf("error\n");
                }
            }while(bonus1 > 10);
        
            if(frame1[i] == 10){
                do{
                    printf("%d flame bonus : ", i + 1);
                    scanf("%d", &bonus2);
                    if(bonus2 > 10){
                        printf("error\n");
                    }
                }while(bonus2 > 10);
            }
        }
    }

    if(point[8] == -1){
        if(bonus1 == 10){
            point[8] = 30;
        }else{
            point[8] = 20 + bonus1 + bonus2;
        }
    }
    if(frame1[9] == 10 ){
        if (bonus1 == 10) {
            // 10 10 a
            point[9] = 30 + (3 * bonus1);
        }else { 
            // 10 a / b
            point[9] = 10 + 2 * (bonus1 + bonus2);
        }
    }else if(point[9] == -1){
        // spare / a
        point[9] = 10 + (2 * bonus1);
    }else{
        point[9] += bonus1;
    }
    int sum;
    for (int i = 0; i < 10; ++i)
    {
        sum += point[i];
    }    
    printf("end game your point si : %d\n", sum );
}



