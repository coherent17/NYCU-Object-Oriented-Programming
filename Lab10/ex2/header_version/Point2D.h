#include <iostream>

using namespace std;

#ifndef POINT_H_
#define POINT_H_

class Point2D{
    private:
        int x;
        int y;
    public:
        //Add constructor by yourself
        Point2D();
        Point2D(int);
        Point2D(int, int);
        ~Point2D();
        void operator = (const Point2D &);
        void set_x(int);
        void set_y(int);
        int get_x();
        int get_y();
        void operator+=(const Point2D&);
        Point2D& operator*(const Point2D&);
        friend ostream &operator<<(ostream &, const Point2D&);
};

#endif