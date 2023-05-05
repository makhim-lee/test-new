//카드갯수
//소유카드
//확인할 카드 갯수
//확인할 카드 목록
//0, 1로 소유여부 확인

#include<stdio.h>

int main(void)
{
    int numCard;
    int suchCard;
    scanf("%d", &numCard);
    int myCards[numCard];
    for(int i = 0; i < numCard; ++i){
        scanf("%d", &myCards[i]); 
    }

    scanf("%d", &suchCard);
    int suchCards[suchCard];
    for (int i = 0; i < suchCard; ++i)
    {
        scanf("%d", &suchCards[i]);
        for (int k = 0; k < numCard; k++)
        {
            if(suchCards[i] == myCards[k]){
                suchCards[i] = 1; 
                break;
            }else if (k = (numCard-1)) suchCards[i] = 0; 
        } 
    }

    for (int i = 0; i < suchCard; ++i)
    {
        printf("%d\n", suchCards[i]);
    }
    
    return 0;
}