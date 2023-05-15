#include "Vector.h"
#include <iostream>

using namespace std;

// Constructor to create a vector of length len and initialize all elements to val
template <class T>
Vector<T>::Vector(int len, T val) {
    this->len = len;
    vec = new T[len];
    for (int i = 0; i < len; i++) {
        vec[i] = val;
    }
}

template<>
Vector<double>::Vector(int len, double val) {
    this->len = len;
    vec = new double[len];
    for (int i = 0; i < len; i++) {
        vec[i] = val;
    }
}

template<>
Vector<Point2D>::Vector(int len, Point2D val) {
    this->len = len;
    vec = new Point2D[len];
    for (int i = 0; i < len; i++) {
        vec[i] = val;
    }
}

// Constructor to create a vector of length len and copy elements from arr
template <class T>
Vector<T>::Vector(int len, T* arr) {
    this->len = len;
    vec = new T[len];
    for (int i = 0; i < len; i++) {
        vec[i] = arr[i];
    }
}

template <>
Vector<double>::Vector(int len, double* arr) {
    this->len = len;
    vec = new double[len];
    for (int i = 0; i < len; i++) {
        vec[i] = arr[i];
    }
}

template <>
Vector<Point2D>::Vector(int len, Point2D* arr) {
    this->len = len;
    vec = new Point2D[len];
    for (int i = 0; i < len; i++) {
        vec[i] = arr[i];
    }
}

// Display the elements of the vector
template <class T>
void Vector<T>::display() {
    for (int i = 0; i < len; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

template <>
void Vector<double>::display() {
    for (int i = 0; i < len; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

template <>
void Vector<Point2D>::display() {
    for (int i = 0; i < len; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

// Overload the "+=" operator to add elements of another vector to this vector
template <class T>
template <class S>
void Vector<T>::operator +=(const Vector<S>& other) {
    for (int i = 0; i < len; i++) {
        vec[i] += other.vec[i];
    }
}

template <>
template <>
void Vector<double>::operator +=(const Vector<double>& other) {
    for (int i = 0; i < len; i++) {
        vec[i] += other.vec[i];
    }
}

template <>
template <>
void Vector<Point2D>::operator +=(const Vector<Point2D>& other) {
    for (int i = 0; i < len; i++) {
        vec[i] += other.vec[i];
    }
}

// Calculate the dot product of two vectors
template <class S>
S dot(const Vector<S>& v1, const Vector<S>& v2) {
    S result = 0;
    for (int i = 0; i < v1.len; i++) {
        result += v1.vec[i] * v2.vec[i];
    }
    return result;
}

template <>
double dot(const Vector<double>& v1, const Vector<double>& v2) {
    double result = 0;
    for (int i = 0; i < v1.len; i++) {
        result += v1.vec[i] * v2.vec[i];
    }
    return result;
}

template <>
Point2D dot(const Vector<Point2D>& v1, const Vector<Point2D>& v2) {
    Point2D result = 0;
    for (int i = 0; i < v1.len; i++) {
        result += v1.vec[i] * v2.vec[i];
    }
    return result;
}