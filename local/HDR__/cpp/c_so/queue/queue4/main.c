#include "queue.h"

int main(void)
{
    Queue s1, s2;
    initQueue(&s1, 100);
    initQueue(&s2, 10);

    push(&s1, 100);
    push(&s1, 200);
    push(&s1, 300);
    printf("%d\n", pop(&s1));
    printf("%d\n", pop(&s1));
    printf("%d\n", pop(&s1));

    push(&s2, 300);
    push(&s2, 400);
    push(&s2, 500);
    printf("%d\n", pop(&s2));
    printf("%d\n", pop(&s2));
    printf("%d\n", pop(&s2));
    
    cleanupQueue(&s1);
    cleanupQueue(&s2);
    return 0;
}