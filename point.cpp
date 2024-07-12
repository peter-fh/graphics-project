#include "point.h"
#include <math.h>
#include <iostream>

Point::Point(int x, int y, int z){
    this->x = new int(x);
    this->y = new int(y);
    this->z = new int(z);
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

	case 'y':
	    *this->y += d;
	case 'z':
	    *this->z += d;
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
