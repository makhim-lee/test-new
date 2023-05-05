#include<stdio.h>

int main(void)
{
    char Arr[8][3] = {
        {'c', '='},
        {'-', '-'},
        {'d', 'z', '='},
        {'d', '-'},
        {'l', 'j'},
        {'n', 'j'},
        {'s', '='},
        {'z', '='}
    };

    for (int i = 0; i < 8; ++i){
        for(int k = 0; k < 3; ++k){
            printf("%c", Arr[i][k]);
        }
        printf("\n");
    }

    return 0;
}