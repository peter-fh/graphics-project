#include "point.h"
#include <istream>

#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle {

public:
    Triangle();
    Triangle(Point& p1, Point& p2, Point& p3);
    ~Triangle();
    int translate(int d, char axis);
    float calcArea();
    friend std::istream& operator>>(std::istream& i, Triangle t);
    //friend std::ostream& operator<<(std::ostream& o, Triangle t);

private:
    Point* vertex_1;
    Point* vertex_2;
    Point* vertex_3;

};

#endif
