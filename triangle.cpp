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
    std::cout << "u: " << u << "\n";
    std::cout << "v: " << v << "\n";
    Point cross_product = crossProduct(u, v);
    std::cout << "u x v: " << cross_product << "\n";
    return cross_product.magnitude() * 0.5;
}


std::istream& operator>>(std::istream& i, Triangle t){
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


// std::ostream& operator<<(std::ostream& o, Triangle t){
//     
// }
