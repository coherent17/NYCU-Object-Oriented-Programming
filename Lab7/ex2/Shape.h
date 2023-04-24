#ifndef SHAPE_H
#define SHAPE_H

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

struct Point {
    int x;
    int y;
};

class Shape {
    private:
        int L;
        int pos_x;
        int pos_y;
        int canvas_size;
        vector<Point> points;  // all plotting points

    public:
        Shape();
        Shape(int, int, int);
        ~Shape();
        void setL(int);
        void setx(int);
        void sety(int);
        void setSize(int);
        int getL()const;
        int getx()const;
        int gety()const;
        int getSize()const;
        void appendPoints(int x, int y);
        bool findPoint(int x, int y);
        void draw();
        vector<Point> getPoints();
};

#endif