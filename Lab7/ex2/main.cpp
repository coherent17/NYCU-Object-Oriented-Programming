#include "Circle.h"
#include "Rect.h"
#include "Shape.h"
#include "Square.h"
#include "Triangle.h"
#define CANVA_LEN 20

int main() {
    cout << "Circle c1: " << endl;
    Circle c1(3, 10, 14);  // Circle(L, pos_x, pos_y, canvas_size = 20)
    c1.ComputeArea();
    c1.ComputePerimeter();
    c1.ComputePoints();
    c1.draw();
    cout << endl;

    cout << "Rect r1: " << endl;
    Rect r1(10, 8, 10, 5);  // Rect(L, W, pos_x, pos_y, canvas_size = 20)
    r1.ComputeArea();
    r1.ComputePerimeter();
    r1.ComputePoints();
    cout << endl;

    cout << "Rect r2: " << endl;
    Square r2(4, 3, 3, 6);  // Square(L, pos_x, pos_y, canvas_size = 20)
    r2.ComputeArea();
    r2.ComputePerimeter();
    r2.ComputePoints();
    r2.draw();
    cout << endl;

    cout << "Triangle t1: " << endl;
    Triangle t1(4, 4, 9, 10);  // Triangle(L, pos_x, pos_y, canvas_size = 20)
    t1.ComputeArea();
    t1.ComputePerimeter();
    t1.ComputePoints();
    t1.draw();
    cout << endl;

    cout << "Triangle t2: " << endl;
    Triangle t2(3, 10, 6);  // Triangle(L, pos_x, pos_y, canvas_size = 20)
    t2.ComputeArea();
    t2.ComputePerimeter();
    t2.ComputePoints();
    cout << endl;

    Shape s1(0, 0, 0);  // Shape(L, pos_x, pos_y, canvas_size = 20)
    for (auto p : c1.getPoints()) {
        s1.appendPoints(p.x, p.y);
    }
    for (auto p : r1.getPoints()) {
        s1.appendPoints(p.x, p.y);
    }
    for (auto p : t2.getPoints()) {
        s1.appendPoints(p.x, p.y);
    }
    s1.draw();
    cout << endl;

    return 0;
}