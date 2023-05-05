#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

int main(void)
{
    Node *head = NULL;
    Node *current = NULL;
    int num, d;
    scanf("%d", &num);
    for(int i = 0; i < num; ++i)
    {
        Node *newNode = malloc(sizeof(Node));
        scanf("%d", &d);
        newNode->data = d;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            current = head;
        }
        else
        {
            current->next = newNode;
            current = newNode;
        }
    }

    Node *p = head;
    while(p)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
    return 0;
}
