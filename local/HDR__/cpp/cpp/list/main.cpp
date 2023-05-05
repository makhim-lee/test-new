#include"list.h"

int main()
{
    List list;
    //List list2 = list; X
    //list2 = list1;

    list.insertFirstNode(4); // 4
    list.insertFirstNode(3); // 3, 4
    list.insertFirstNode(1);  // 1, 3, 4
    list.insertNode(3, 7);   // 1,2,3,4

    list.deleteNode(3);
    //list.printList(); 
    std::cout << list<<std::endl;

    return 0;
}