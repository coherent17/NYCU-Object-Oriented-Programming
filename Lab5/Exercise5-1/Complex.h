#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using namespace std;

class Complex{
    private:
        double real;
        double img;

    public:
        Complex(double,double);
        Complex();
        ~Complex();

        //member function
        const Complex operator +(const Complex&);
        const Complex operator -(const Complex&);
        const Complex operator *(const Complex&);
        void Polar();

        //friend function
        friend void printComplex(Complex);
};
#endif