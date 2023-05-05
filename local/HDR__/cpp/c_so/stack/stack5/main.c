#include"stack.h"

int main(void)
{
    Stack s1, s2;
    initStack(&s1, 100, sizeof(int));
    initStack(&s2, 10, sizeof(double));

    //push(&s1, 100);
    int i = 100; push(&s1, &i/*, sizeof(int)*/);
    //push(&s1, 200);
    i = 200; push(&s1, &i);
    //push(&s1, 300);
    i = 300; push(&s1, &i);

    int re;
    pop(&s1, &re); printf("%d\n", re);
    pop(&s1, &re); printf("%d\n", re);
    pop(&s1, &re); printf("%d\n", re);

    double d = 1.1 ; push(&s2, &d);
    d = 1.2 ; push(&s2, &d);
    d = 1.3 ; push(&s2, &d);

    double re2;
    pop(&s2, &re2); printf("%f\n", re2);
    pop(&s2, &re2); printf("%f\n", re2);
    pop(&s2, &re2); printf("%f\n", re2);
    
    cleanupStack(&s1);
    cleanupStack(&s2);
    return 0;
}