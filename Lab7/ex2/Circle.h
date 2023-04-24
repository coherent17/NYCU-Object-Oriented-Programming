#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#define PI 3.14

class Circle : public Shape {
    private:

    public:
        Circle(int, int, int);
        Circle(int, int, int, int);
        void ComputeArea();
        void ComputePerimeter();
        void ComputePoints();

};
#endif