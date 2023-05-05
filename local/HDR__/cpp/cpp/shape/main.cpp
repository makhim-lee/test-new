#include<iostream>
#include<typeinfo>
#include"shape.h"
//#include"rectangle.h"
//#include"circle.h"

void printArea(const Shape *ps){ ///void * ??????????????????????????????????????????????????????????????
    //RTTI(RumTime Type Identification)
    if(typeid(*ps) == typeid(Rectangle)){
        std::cout<<"rectangle"<<ps->area()<<std::endl;;
        std::cout<<"diagonal : "<<(dynamic_cast<const Rectangle *>(ps))->getDiagonal()<<std::endl;
    }
    else if (typeid(*ps) == typeid(Rectangle)){
        std::cout<<"circle"<<ps->area()<<std::endl;;
        std::cout<<"Circumference : "<< (dynamic_cast<const Circle *>(ps))->getCircumference()<<std::endl;
    }
    // std::cout<<"area : "<<ps->area()<<std::endl;
}

int main()
{
    // Shape s;  ABC 의 객체는 만들 수 없음  
    Shape *ps; // O 포인터랑 레퍼런스는 가능 
    
    Shape *shapes[5];
    shapes[0] = new Rectangle(0, 0, 100, 50);
    shapes[1] = new Rectangle(50, 50, 10, 20);
    shapes[2] = new Circle(100, 100, 10);
    shapes[3] = new Rectangle(100, 200, 5, 20);
    shapes[4] = new Circle(200, 200, 50);

    for(int i = 0; i < 5; ++i){
        printArea(shapes[i]);
    }

    for(int i = 0; i < 5; ++i){
        delete shapes[i];
    }
    return 0;
}

