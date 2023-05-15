// Vector.h
#ifndef VECTOR_H_
#define VECTOR_H_
#include "Point2D.h"
template <class T>
class Vector
{
private:
    int len;
    T* vec;
public:
    // add any member if necessary
    Vector(int,T);
    Vector(int,T*);
    void display();
    void operator +=(const Vector<T>&);
    template<class S>
    friend S dot (const Vector<S> &, const Vector<S> &);
};

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

#endif