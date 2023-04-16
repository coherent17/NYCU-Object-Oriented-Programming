#include "Square.h"
#include <cmath>

using namespace std;


//Q1:
Square::Square(double c_x, double c_y, double len, double angle){
    this->center = Center(c_x, c_y);
    this->len = len;
    this->angle = angle;
}

Square::Square(const Square &S){
    this->center = S.center;
    this->len = S.len;
    this->angle = S.angle;
}

//ref: https://blog.csdn.net/guyuealian/article/details/78288131
double x_prime(double x, double y, double theta, double c_x, double c_y){
    return (x - c_x) * cos(theta * PI / 180) - (y - c_y) * sin(theta * PI / 180) + c_x;
}

double y_prime(double x, double y, double theta, double c_x, double c_y){
    return (x - c_x) * sin(theta * PI / 180) + (y - c_y) * cos(theta * PI / 180) + c_y;
}


ostream& operator<<(ostream &out, const Square &S){
    out << "center: (" << S.center.x << "," << S.center.y << ") " << "len:" << S.len << " " << "angle:" << S.angle << endl;
    double c_x = S.center.x;
    double c_y = S.center.y;
    out << "point1: " << x_prime(c_x - S.len / 2, c_y - S.len / 2, S.angle, c_x, c_y) << " " << y_prime(c_x - S.len / 2, c_y - S.len / 2, S.angle, c_x, c_y) << " ";
    out << "point2: " << x_prime(c_x - S.len / 2, c_y + S.len / 2, S.angle, c_x, c_y) << " " << y_prime(c_x - S.len / 2, c_y + S.len / 2, S.angle, c_x, c_y) << " ";
    out << "point3: " << x_prime(c_x + S.len / 2, c_y + S.len / 2, S.angle, c_x, c_y) << " " << y_prime(c_x + S.len / 2, c_y + S.len / 2, S.angle, c_x, c_y) << " ";
    out << "point4: " << x_prime(c_x + S.len / 2, c_y - S.len / 2, S.angle, c_x, c_y) << " " << y_prime(c_x + S.len / 2, c_y - S.len / 2, S.angle, c_x, c_y) << endl;
    return out;
}


//Q2
Square Square::operator*(double a){
    return Square(center.x, center.y, len * a, angle);
}

Square Square::operator^(double a){
    return Square(center.x, center.y, len, angle + a);
}

Square Square::operator+(double a){
    return Square(center.x + a, center.y + a, len, angle);
}

void Square::operator +=(Center c){
    center.x += c.x;
    center.y += c.y;
}

//Q3

//overloading using member function
Square& Square::operator++(){
    //prefix
    center.x++;
    center.y++;
    return *this;
}

Square Square::operator++(int x){
    //postfix
    Square tmp = Square(*this);
    this->center.x++;
    this->center.y++;
    return tmp;
}

Square& Square::operator--(){
    //prefix
    center.x--;
    center.y--;
    return *this;
}

Square Square::operator--(int x){
    //postfix
    Square tmp = Square(*this);
    this->center.x--;
    this->center.y--;
    return tmp;
}

//overloading using friend function
Square operator++(Square &S){
    //prefix
    ++S.center.x;
    ++S.center.y;
    return S;
}

Square operator++(Square &S, int x){
    //postfix
    Square tmp = Square(S);
    S.center.x++;
    S.center.y++;
    return tmp;
}

Square operator--(Square &S){
    //postfix
    --S.center.x;
    --S.center.y;
    return S;
}
Square operator--(Square &S, int x){
    //prefix
    Square tmp = Square(S);
    S.center.x--;
    S.center.y--;
    return tmp;
}

bool Square::operator ==(Square &S){
    if(S.center.x != center.x || S.center.y != center.y || S.len != len)
        return false;
    if(S.angle != angle && S.angle != 360 - angle)
        return false;
    return true;
}

bool Square::operator <(Square &S){
    return S.len > len;
}