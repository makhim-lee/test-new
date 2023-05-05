#include<stdio.h>
#include<string.h>

int main(void)
{
    char alp[1000000];
    scanf("%s", alp);
    
    int Max = 0;
    int cnt;
    int len = strlen(alp);
    char x = 0;
    for(char i = 65; i <= 90; ++i){
        cnt = 0;
        for(int k = 0; k < len; ++k){
            if(alp[k] == i || alp[k] == (i + 32)) ++cnt;
        }
        
        if (cnt != 0){
            if(Max == cnt){
                printf("?\n");
                return 0;
            }
            Max = cnt;
            x = i;
        }
    }
    printf("%c\n", x);
    return 0;
}