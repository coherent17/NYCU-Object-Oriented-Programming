#include<bits/stdc++.h>
using namespace std;

#ifndef _LINE_GP_H_
#define _LINE_GP_H_

typedef struct _Point{
    double x;
    double y;
}Point;

typedef struct _Line{
    Point p1;
    Point p2;
}Line;

class LineGp{
    private:
        Line lines[3];
        vector<Point> intersectP;
        void set_L(int, Line);
        void interset(Line, Line);
        void interset_lines();

    public:
        LineGp();
        void set_lines();
        void printLines();
        void computeArea();
};

#endif