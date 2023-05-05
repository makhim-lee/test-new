#include<cmath>
#include "shape.h"

Shape::Shape(int x, int y)
: x_(x), y_(y)
{

}

void Shape::move(int offsetX, int offsetY){
    y_ += offsetY;
    x_ += offsetX;
}

double Rectangle::getDiagonal()const{
    return sqrt(width_ * width_ + height_ * height_);
}

// area() ?? 