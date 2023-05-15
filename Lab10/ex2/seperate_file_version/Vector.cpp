#include "Vector.h"

template <class T>
Vector<T>::Vector(int len, T val) {
    this->len = len;
    vec = new T[len];
    for (int i = 0; i < len; i++) {
        vec[i] = val;
    }
}

template <class T>
Vector<T>::Vector(int len, T* arr) {
    this->len = len;
    vec = new T[len];
    for (int i = 0; i < len; i++) {
        vec[i] = arr[i];
    }
}


template <class T>
void Vector<T>::display() {
    for (int i = 0; i < len; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

template <class T>
void Vector<T>::operator +=(const Vector<T>& other) {
    for (int i = 0; i < len; i++) {
        vec[i] += other.vec[i];
    }
}

template <class S>
S dot(const Vector<S>& v1, const Vector<S>& v2) {
    S result = 0;
    for (int i = 0; i < v1.len; i++) {
        result += v1.vec[i] * v2.vec[i];
    }
    return result;
}

template Vector<double>::Vector(int, double);
template Vector<double>::Vector(int, double*);
template void Vector<double>::operator+=(Vector<double> const&);
template void Vector<double>::display();
template double dot<double>(Vector<double> const&, Vector<double> const&);

template Vector<Point2D>::Vector(int, Point2D);
template Vector<Point2D>::Vector(int, Point2D*);
template void Vector<Point2D>::operator+=(Vector<Point2D> const&);
template void Vector<Point2D>::display();
template Point2D dot<Point2D>(Vector<Point2D> const&, Vector<Point2D> const&);