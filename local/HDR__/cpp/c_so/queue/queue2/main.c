#include "queue.h"

int main(void)
{
    push(100);
    push(200);

    printf("%d\n", pop());

    push(300);

    printf("%d\n", pop());
    printf("%d\n", pop());

    return 0;
}