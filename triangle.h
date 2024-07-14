#include "point.h"
#include <istream>

#ifndef TRIANGLE_H
#define TRIANGLE_H



class Triangle {

public:
    Triangle();
    Triangle(const Point& p1, const Point& p2, const Point& p3);
    ~Triangle();

    int translate(int d, char axis);
    float calcArea();
    int display(char axis); 

    friend std::istream& operator>>(std::istream& i, Triangle& t);
    friend std::ostream& operator<<(std::ostream& o, Triangle& t);

private:
    Point* vertex_1;
    Point* vertex_2;
    Point* vertex_3;

};

#endif
