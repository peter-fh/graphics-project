#include "triangle.h"
#include <iostream>

int main(){

  Point vertex_1(0,0,0);
  Point vertex_2(0,0,0);
  Point vertex_3(0,0,0);

  std::cout << "Enter vertex 1 (three numbers separated by spaces):\n";
  std::cin >> vertex_1;

  std::cout << "Enter vertex 2 (three numbers separated by spaces):\n";
  std::cin >> vertex_2;

  std::cout << "Enter vertex 3 (three numbers separated by spaces):\n";
  std::cin >> vertex_3;

  Triangle* triangle = new Triangle(vertex_1, vertex_2, vertex_3);

  std::cout << *triangle;

  if (triangle->display('z') == -1){
    std::cout << "invalid axis\n";
  }

}
