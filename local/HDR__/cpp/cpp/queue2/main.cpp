#include "queue.h"

int main()
{
    Queue q1;
    Queue q2(100);
    Queue q3 = q2;

    q1 = q2; 

    q1.push(100);
    q1.push(200);
    q1.push(300);
    
    std::cout << q1.pop() << std::endl;
    std::cout << q1.pop() << std::endl;
    std::cout << q1.pop() << std::endl;

    for(int i = 1; i <= 3; ++i){
        if(!q2.isFull()){
            q2.push(i);
        }
    }
    while(1){
        if(q2.isEmpty())break;
        std::cout << "q2 pop() :"<<q2.pop()<<std::endl;
    }

    return 0;
}