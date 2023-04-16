#include <iostream>
#include "Center.h"
#define PI 3.14159265

using namespace std;

class Square{
    private:
        Center center;
        double len;
        double angle;

    public:
        //Q1
        Square(double, double, double, double);
        Square(const Square &);
        friend ostream & operator<<(ostream &, const Square &);

        //Q2
        Square operator*(double);
        Square operator^(double);
        Square operator+(double);
        void operator +=(Center);

        //Q3
        //overloading using member function
        Square& operator++();   //prefix
        Square operator++(int); //postfix
        Square& operator--();   //prefix
        Square operator--(int); //postfix

        //overloading using friend function
        friend Square operator++(Square &);     //prefix
        friend Square operator++(Square &, int);//postfix
        friend Square operator--(Square &);     //prefix
        friend Square operator--(Square &, int);//postfix

        bool operator ==(Square &);
        bool operator <(Square &);
};
