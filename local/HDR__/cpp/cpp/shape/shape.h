#ifndef SHAPE_H
#define SHAPE_H

//shape.h
class Shape{  //ABC(Abstract Base Class)추상클레스
protected:
    int x_;
    int y_;

public:
    Shape(int x = 0, int y = 0);
    virtual ~Shape() {};
    void move(int offsetX, int offsetY);
    virtual double area() const = 0; // pure virtual func <-- 아래 class에서 반드시 정의돼야 함 정의되지 않은 아래클래스도 ABC 가 됨 
    double getDiagonal()const;
};
#endif

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle : public Shape{
private:
    int width_;
    int height_;
public:
    Rectangle(int x, int y, int width, int height_);
    virtual double area()const;
};
#endif

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle : public Shape{
private:
    int rad_;
public:
    Circle(int x, int y, int rad);
    virtual double area() const;
    double getCircumference() const;
};
#endif