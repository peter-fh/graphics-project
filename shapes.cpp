#include <iostream>
#include <cmath>

class point {
    int x;
    int y;
    int z;
    
public:
    point() {
        x = 0;
        y = 0;
        z = 0;
    }

    point(int a, int b, int c) {
        x = a;
        y = b;
        z = c;
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    int getZ() {
        return z;
    }

    void displayPoint() {
        std::cout << "x: " << x << "\ny: " << y << "\nz: " << z << "\n";
    }

    int translate(int d, char axis) {
        switch (axis) {
        case 'x':
            x += d;
            return 0;
        case 'y':
            y += d;
            return 0;
        case 'z':
            z += d;
            return 0;
        default:
            std::cout << "Invalid axis!\n";
            return -1;
        }
    }
};

class triangle {
    point vertex_1;
    point vertex_2;
    point vertex_3;

public:
    triangle() {
        vertex_1 = point();
        vertex_2 = point();
        vertex_3 = point();
    }

    triangle(point a, point b, point c) {
        vertex_1 = a;
        vertex_2 = b;
        vertex_3 = c;
    }

    void displayTriangle() {
        std::cout << "VERTEX 1\n";
        vertex_1.displayPoint();
        std::cout << "VERTEX 2\n";
        vertex_2.displayPoint();
        std::cout << "VERTEX 3\n";
        vertex_3.displayPoint();
    }

    int translate(int d, char axis){
        if (axis == 'x' || axis == 'y' || axis == 'z') {
            vertex_1.translate(d, axis);
            vertex_2.translate(d, axis);
            vertex_3.translate(d, axis);
            return 0;
        }
        else {
            std::cout << "Invalid axis!\n";
            return -1;
        }
    }

    float calcArea() {
        //Finding vectors PQ and PR
        point pq = point(vertex_2.getX() - vertex_1.getX(), vertex_2.getY() - vertex_1.getY(), vertex_2.getZ() - vertex_1.getZ());
        point pr = point(vertex_3.getX() - vertex_1.getX(), vertex_3.getY() - vertex_1.getY(), vertex_3.getZ() - vertex_1.getZ());

        //Finding cross product of PQ and PR
        point pqxpr = point(pq.getY() * pr.getZ() - pr.getY() * pq.getZ(), (pq.getX() * pr.getZ() - pr.getX() * pq.getZ()) * -1, pq.getX() * pr.getY() - pr.getX() * pq.getY());

        //Finding magnitude of PQxPR
        float result = 0.5 * sqrt(pow((int) pqxpr.getX(), 2) + pow((int) pqxpr.getY(), 2) + pow((int) pqxpr.getZ(), 2));

        return result;
    }
};

int main()
{
    point p;
    p.translate(10, 'x');
    p.translate(10, 'q');
    p.displayPoint();

    std::cout << "\n";

    triangle t = triangle(point(-5, 5, -5), point(1, -6, 6), point(2, -3, 4));
    t.translate(10, 'x');
    t.displayTriangle();
    std::cout << "Area: " << t.calcArea();
}
