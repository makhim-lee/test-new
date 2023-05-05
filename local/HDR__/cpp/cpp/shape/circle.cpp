#include "shape.h"

Circle::Circle(int x, int y, int rad)
: Shape(x, y), rad_(rad)
{

}

double Circle::area()const{
    return 3.14 * rad_ * rad_;
}

double Circle::getCircumference() const{
    return 2 * rad_ * 3.14;
}

