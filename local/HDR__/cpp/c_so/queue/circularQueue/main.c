#include "queue.h"

int main(void)
{
    Queue q1, q2;
    initQueue(&q1, 100);
    initQueue(&q2, 10);

    push(&q1, 100);
    push(&q1, 200);
    push(&q1, 300);
    printf("%d\n", pop(&q1));
    printf("%d\n", pop(&q1));
    printf("%d\n", pop(&q1));

    push(&q2, 300);
    push(&q2, 400);
    push(&q2, 500);
    printf("%d\n", pop(&q2));
    printf("%d\n", pop(&q2));
    printf("%d\n", pop(&q2));
    
    cleanupQueue(&q1);
    cleanupQueue(&q2);
    return 0;
}