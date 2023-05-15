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
    template<class S>
    void operator +=(const Vector<S>&);
    template<class S>
    friend S dot (const Vector<S> &, const Vector<S> &);
};
#endif