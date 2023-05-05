#include"list.h"

int main(void)
{
    List list;
    initList(&list);

    insertFirstNode(&list, 4); // 4
    insertFirstNode(&list, 3); // 3, 4
    insertFirstNode(&list, 1);  // 1, 3, 4
    insertNode(&list, 3, 7);   // 1,2,3,4

    printList(&list);

    deleteNode(&list, 3);

    printList(&list);

    cleanupList(&list);

    return 0;
}