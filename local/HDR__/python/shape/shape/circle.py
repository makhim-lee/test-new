#circle.py
from shape.shape import Shape

class Circle(Shape):
    def __init__(self, x, y, rad):
        super().__init__(x, y)
        self.__rad = rad
        
    def area(self):
        return 3.14 * self.__rad * self.__rad
    def get_circumference(self):
        return 3.14 * 2 * self.__rad
    