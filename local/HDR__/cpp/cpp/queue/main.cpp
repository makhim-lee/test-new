#include "queue.h"

int main()
{
    Queue s1(100), s2(10);
    

    s1.push(100);
    s1.push(200);
    s1.push(300);
    // printf("%d\n", s1.pop());
    // printf("%d\n", s1.pop());
    // printf("%d\n", s1.pop());
    std::cout << s1.pop() << std::endl;
    std::cout << s1.pop() << std::endl;
    std::cout << s1.pop() << std::endl;


    s2.push(300);
    s2.push(400);
    s2.push(500);
    // printf("%d\n", s2.pop());
    // printf("%d\n", s2.pop());
    // printf("%d\n", s2.pop());
    std::cout << s2.pop() << std::endl;
    std::cout << s2.pop() << std::endl;
    std::cout << s2.pop() << std::endl;
    
    return 0;
}