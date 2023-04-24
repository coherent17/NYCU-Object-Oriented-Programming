#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
class Triangle : public Shape {
    private:
    public:
        Triangle();
        Triangle(int, int, int);
        Triangle(int, int, int, int);
        ~Triangle();
        void ComputeArea();
        void ComputePerimeter();
        void ComputePoints();
};

#endif