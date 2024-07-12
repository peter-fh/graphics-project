#include "triangle.h"
#include <iostream>

Triangle::Triangle(){
    vertex_1 = nullptr;
    vertex_2 = nullptr;
    vertex_3 = nullptr;
}

Triangle::Triangle(Point& p1, Point& p2, Point& p3){
    vertex_1 = new Point(p1);
    vertex_2 = new Point(p2);
    vertex_3 = new Point(p3);
}


Triangle::~Triangle(){
    delete vertex_1;
    delete vertex_2;
    delete vertex_3;
}


int Triangle::translate(int d, char axis){
    int return_val = this->vertex_1->translate(d, axis);
    if (return_val != 0) {
	return return_val;
    }
    this->vertex_2->translate(d, axis);
    this->vertex_3->translate(d, axis);
    return 0;
}


float Triangle::calcArea(){
    Point u = *vertex_2 - *vertex_1;
    Point v = *vertex_3 - *vertex_1;
    Point cross_product = crossProduct(u, v);
    return cross_product.magnitude() * 0.5;
}


std::istream& operator>>(std::istream& i, Triangle& t){
    int x1, y1, z1;
    int x2, y2, z2;
    int x3, y3, z3;

    i >> x1 >> y1 >> z1;
    i >> x2 >> y2 >> z2;
    i >> x3 >> y3 >> z3;

    t.vertex_1 = new Point(x1, y1, z1);
    t.vertex_2 = new Point(x2, y2, z2);
    t.vertex_3 = new Point(x3, y3, z3);

    return i;
}


typedef struct {
    int x;
    int y;
} Point2;


int Triangle::display(char axis){
    Point2 vertices[3];
    Point2 p1;
    Point2 p2;
    Point2 p3;
    switch (axis) {
	case 'x':
	    p1.x = vertex_1->getY();
	    p1.y = vertex_1->getZ();
	    p2.x = vertex_2->getY();
	    p2.y = vertex_2->getZ();
	    p3.x = vertex_3->getY();
	    p3.y = vertex_3->getZ();
	    break;
	case 'y':
	    p1.x = vertex_1->getX();
	    p1.y = vertex_1->getZ();
	    p2.x = vertex_2->getX();
	    p2.y = vertex_2->getZ();
	    p3.x = vertex_3->getX();
	    p3.y = vertex_3->getZ();
	    break;
	case 'z':
	    p1.x = vertex_1->getX();
	    p1.y = vertex_1->getY();
	    p2.x = vertex_2->getX();
	    p2.y = vertex_2->getY();
	    p3.x = vertex_3->getX();
	    p3.y = vertex_3->getY();
	    break;
	default: 
	    return -1;
    }
    vertices[0] = p1;
    vertices[1] = p2;
    vertices[2] = p3;

    int width = 20;
    int height = 20;
    for (int y=0; y < height; ++y){
	for (int x=0; x < width; ++x){
	    bool found_point = false;
	    for (int i=0; i < 3; ++i){
		Point2 current_point = vertices[i];
		if (x == current_point.x && y == current_point.y){
		    found_point = true;
		}
	    }

	    if (found_point) {
		std::cout << "#";
	    } else {
		std::cout << " ";
	    }
	}
	std::cout << "\n";
    }
    return 0;
}

std::ostream& operator<<(std::ostream& o, Triangle& t){
    o << "Triangle:\n";
    o << *t.vertex_1 << "\n";
    o << *t.vertex_2 << "\n";
    o << *t.vertex_3 << "\n";
    o << "Area: " << t.calcArea() << "\n";
    return o;
	
}
