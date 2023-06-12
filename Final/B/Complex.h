// Complex.h
#ifndef _COMPLEX_H_
#define _COMPLEX_H_

#include<bits/stdc++.h>
using namespace std;

class Complex{
private:
    double real;
    double imag;
public:
    // please add constructors
    Complex();
    Complex(double, double);
    void set_real(double);
    void set_imag(double);
    void operator=(const Complex &);
    Complex operator+(const Complex &);
    Complex operator-(const Complex &);
    void operator+=(const Complex &);
    void operator-=(const Complex &);
    friend std::ostream &operator<<(std::ostream &os, const Complex);
};

Complex::Complex() : real(0.0), imag(0.0) {}

Complex::Complex(double real, double imag) : real(real), imag(imag) {}

void Complex::set_real(double real) {
    this->real = real;
}

void Complex::set_imag(double imag) {
    this->imag = imag;
}

void Complex::operator=(const Complex &other) {
    this->real = other.real;
    this->imag = other.imag;
}

Complex Complex::operator+(const Complex &other) {
    Complex result;
    result.real = this->real + other.real;
    result.imag = this->imag + other.imag;
    return result;
}

Complex Complex::operator-(const Complex &other) {
    Complex result;
    result.real = this->real - other.real;
    result.imag = this->imag - other.imag;
    return result;
}

void Complex::operator+=(const Complex &other) {
    this->real += other.real;
    this->imag += other.imag;
}

void Complex::operator-=(const Complex &other) {
    this->real -= other.real;
    this->imag -= other.imag;
}

std::ostream &operator<<(std::ostream &os, const Complex c) {
    os << c.real;
    if (c.imag >= 0) {
        os << "+";
    }
    os << c.imag << "j";
    return os;
}

#endif