#include "Complex.h"
#include <iostream>
#include <cmath>
using namespace std;

Complex::Complex(){}

Complex::~Complex(){}

Complex::Complex(double a,double b){
    real = a;
    img = b;
}

const Complex Complex::operator +(const Complex& b){
    return Complex(real+b.real,img+b.img);
}

const Complex Complex::operator -(const Complex& b){
    return Complex(real-b.real,img-b.img);
}

const Complex Complex::operator *(const Complex& b){
    return Complex(real * b.real - img*b.img , img*b.real + real*b.img);
}

void printComplex(Complex a){
    cout<< "Complex number is: ";

    if(a.img == 0 && a.real == 0){
        cout << "0" << endl;
    }

    else if(a.img == 0 && a.real != 0){
        cout << a.real << endl;
    }
    else if(a.real == 0 && a.img != 0){
        if(a.img == 1){
            cout << "j" << endl;
        }
        else{
            cout << a.img << "j" << endl;
        }
    }
    else{
        if(a.img == 1){
            cout << a.real << "+j" << endl;
            return;
        }
        if(a.img == -1){
            cout << a.real << "-j" << endl;
            return;
        }
        if(a.img < 0){
            cout << a.real << a.img << "j" << endl;
        }
        else{
            cout << a.real << "+" << a.img << "j" << endl;
        }
    }
}

void Complex::Polar(){
    double r = sqrt(real*real+img*img);
    double theta = atan(img/real) * 180 / 3.14159;
    cout << "Polar form is: " << r << "(cos" << theta << "+isin" << theta << ")" << endl;
}