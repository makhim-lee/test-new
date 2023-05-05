/*
avr 3.3 이상
전공 평점 계산기 
학점 * 과목평점   (과목명 학점 평점)
p 등급은 제외 

++)과목이름 과목평점 학점
a+ a0 b+ ~ d0 f 4.5 ~ 1.0, 0.0
*/
#include<stdio.h>

double grade(char score)
{
    double i;
    for(int i = 0; i < 2; ++i){
        printf("%c", score[i]);
    }
    return i;
}

int main(void)
{
    char grade[2];
    
    scanf("%s",grade);
    grade(grade);
    
    printf("\n");

    return 0;
}