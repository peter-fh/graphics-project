#include "point.h"
#include <math.h>
#include <iostream>

// TODO: Null checks and default constructor?

Point::Point(int x, int y, int z){
    this->x = new int(x);
    this->y = new int(y);
    this->z = new int(z);
}

Point::Point(const Point& p){
    this->x = new int(*p.x);
    this->y = new int(*p.y);
    this->z = new int(*p.z);
}

Point::~Point(){
    delete x;
    delete y;
    delete z;
}

int Point::translate(int d, char axis){
    // d already has to be an int, why would we check that it isn't?
    if (false){
	return -2;
    }
    switch (axis){
	case 'x':
	    *this->x += d;
	    break;
	case 'y':
	    *this->y += d;
	    break;
	case 'z':
	    *this->z += d;
	    break;
	default:
	    return -1;
	    break;
    }

    return 0;
}

float distance(Point* a, Point* b){
    int dx = *a->x - *b->x;
    int dy = *a->y - *b->y;
    int dz = *a->z - *b->z;
    return sqrt(dx*dx+dy*dy+dz*dz);
}

Point Point::operator-(Point& a){
    int x = *(this->x) - *(a.x);
    int y = *(this->y) - *(a.y);
    int z = *(this->z) - *(a.z);
    return Point(x,y,z);
}

float Point::magnitude(){
    int x = *this->x;
    int y = *this->y;
    int z = *this->z;
    return sqrt(x*x + y*y + z*z);
}


Point crossProduct(Point& a, Point& b){
    int x1 = *a.x;
    int y1 = *a.y;
    int z1 = *a.z;
    int x2 = *b.x;
    int y2 = *b.y;
    int z2 = *b.z;

    int i = y1*z2 - z1*y2;
    int j = z1*x2 - x1*z2;
    int k = x1*y2 - y1*x2;

    return Point(i,j,k);
}


std::ostream& operator<<(std::ostream& o, Point& p){
    o << "(" << *p.x << ", " << *p.y << ", " << *p.z << ")";
    return o;
}

int Point::getX(){
    return *this->x;
}
int Point::getY(){
    return *this->y;
}
int Point::getZ(){
    return *this->z;
}

std::istream& operator>>(std::istream& i, Point& p){
    int x, y, z;
    i >> x >> y >> z;
    *p.x = x;
    *p.y = y;
    *p.z = z;
    return i;
}
