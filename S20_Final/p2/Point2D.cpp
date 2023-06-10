#include "Point2D.h"

Point2D::Point2D(){
    x = 0;
    y = 0;
}

Point2D::Point2D(int x, int y){
    this->x = x;
    this->y = y;
}

void Point2D::SetXY(int x, int y){
    this->x = x;
    this->y = y;
}

int Point2D::operator %(int a){
    return (x * x + y * y) % a;
}

bool Point2D::operator >(Point2D& P){
    if(x==P.x)
        if(y>=P.y)
            return true;
        else
            return false;
    else
        if(x < P.x)
            return false;
        else
            return true;
}

bool Point2D::operator ==(Point2D& P){
    if(x == P.x && y == P.y) return true;
    return false;
}

ostream &operator<<(ostream &out, Point2D P){
    out << "(" << P.x << ", " << P.y << ")";
    return out;
}