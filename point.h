#ifndef POINT_H
#define POINT_H
#include <istream>

class Point {

public:
    Point(int x, int y, int z);
    ~Point();
    int translate(int d, char axis);
    friend float distance(Point* a, Point* b);
    float magnitude();
    friend Point crossProduct(Point& a, Point& b);

    Point operator-(Point& a);
    friend std::ostream& operator<<(std::ostream&, Point&);
    
private:
    int* x;
    int* y;
    int* z;

};

#endif
