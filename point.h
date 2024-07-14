#ifndef POINT_H
#define POINT_H
#include <istream>

class Point {

public:
    Point(int x, int y, int z);
    Point(const Point& p);
    ~Point();

    int getX();
    int getY();
    int getZ();

    int translate(int d, char axis);
    float magnitude();

    friend float distance(Point* a, Point* b);
    friend Point crossProduct(Point& a, Point& b);

    Point operator-(Point& a);
    friend std::ostream& operator<<(std::ostream&, Point&);
    friend std::istream& operator>>(std::istream&, Point&);
    
private:
    int* x;
    int* y;
    int* z;

};

#endif
