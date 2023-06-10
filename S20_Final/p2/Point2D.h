#ifndef _POINT2D_H_
#define _POINT2D_H_
#include<bits/stdc++.h>
using namespace std;
class Point2D{
    private:
        int x;
        int y;
    public:
        Point2D();
        Point2D(int, int );
        void SetXY(int, int);

        //operator overloading
        int operator %(int a);
        bool operator >(Point2D& P);
        bool operator ==(Point2D& P);
        friend ostream &operator<<(ostream &, Point2D);
};

#endif