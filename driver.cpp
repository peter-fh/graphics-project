#include "triangle.h"
#include <iostream>

int main(){
  Point vertex_1(0,0,0);
  Point vertex_2(1,1,1);
  Point vertex_3(2,2,2);
  Triangle* triangle = new Triangle(vertex_1, vertex_2, vertex_3);
  std::cout << triangle->calcArea() << "\n";
  Triangle triangle_2;
  std::cin >> triangle_2;
  std::cout << triangle_2.calcArea() << "\n";
}
