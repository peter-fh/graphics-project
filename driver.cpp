#include "triangle.h"
#include <iostream>

const std::string menu(
  "\n\n"
  "1. Display triangle information\n"
  "2. Render triangle vertices in 2d\n"
  "3. Translate triangle\n"
  "4. Exit\n"
  "#: "
);


void userMenu(Triangle* triangle){
  bool user_exit = false;
  while (!user_exit){
    char choice;
    char axis;
    int d;
    std::cout << menu;
    std::cin >> choice;
    switch (choice) {
      case '1':
        std::cout << *triangle;
        break;
      case '2':
        std::cout << "Pick an axis to view the triangle from (x, y, or z)\n";
        std::cout << "Axis: ";
        std::cin >> axis;
        if (triangle->display(axis) == -1){
          std::cout << "Invalid axis!\n";
        }
        
        break;
      case '3':
        std::cout << "Pick an axis to translate the triangle (x, y, or z)\n";
        std::cout << "Axis: ";
        std::cin >> axis;
        std::cout << "Pick a number to translate the triangle\n";
        std::cout << "#: ";
        std::cin >> d;
        if (triangle->translate(d, axis) == -1){
          std::cout << "Invalid axis!\n";
        }
        break;
      case '4':
        user_exit = true;
        break;
      default:
        std::cout << "Invalid choice!\n";
        break;
    }

  }

}

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

  userMenu(triangle);


}
