#ifndef POINT_H
#define POINT_H

class Point {

public:
    Point(int x, int y, int z);
    ~Point();
    int translate(int d, char axis);
    friend float distance(Point* a, Point* b);
    
private:
    int* x;
    int* y;
    int* z;

};

#endif
