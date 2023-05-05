#include "queue.h"

int main(void)
{
    Queue s1, s2;
    initQueue(&s1, 100, sizeof(int));
    initQueue(&s2, 100, sizeof(double));

    int i,re = 0;
    i = 100; push(&s1, &i/*, sizeof(int)*/);
    i = 200; push(&s1, &i);
    pop(&s1, &re); printf("%d\n", re);
    pop(&s1, &re); printf("%d\n", re);
    i = 300; push(&s1, &i);
    pop(&s1, &re); printf("%d\n", re);

    double d,re2 = 0;
    d = 1.1; push(&s2, &d);
    d = 1.2; push(&s2, &d);
    pop(&s2, &re2); printf("%f\n", re2);
    pop(&s2, &re2); printf("%f\n", re2);
    d = 1.3; push(&s2, &d);
    pop(&s2, &re2); printf("%f\n", re2);
    
    cleanupQueue(&s1);
    cleanupQueue(&s2);
    return 0;
}