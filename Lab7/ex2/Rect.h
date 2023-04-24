#ifndef RECT_H
#define RECT_H

#include "Shape.h"

class Rect : public Shape {
    private:
        int W;

    public:
        Rect();
        Rect(int, int, int, int);
        Rect(int, int, int, int, int);
        ~Rect();
        void ComputeArea();
        void ComputePerimeter();
        void ComputePoints();
};

#endif