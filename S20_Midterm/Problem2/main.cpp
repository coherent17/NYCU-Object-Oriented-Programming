#include <iostream>
#include <fstream>
#include "numpy.h"
using namespace std;

int* slicing(int a, int b){
    int *c = new int[2];
    c[0] = a;
    c[1] = b;
    return c;
}
// three main
int main(int argc, char* argv[]){
    //Q1
    cout << "---Q1---" << endl;
    int axis;
    numpy a(argv[1]);
    int* dimension;
    cout << "max = " << a.max() << endl;
    dimension = a.argmax();
    cout << "argmax = (" << dimension[0] << ", " << dimension[1] << ")" <<  endl;
    delete [] dimension;
    
    //Q2
    cout << "---Q2---" << endl;
    cout << a[0][2] << endl;
    cout << a << endl << endl;
    a.sort(axis = 0);
    cout << a << endl << endl;
    a.sort(axis = 1);
    cout << a << endl << endl;
    numpy b = a.reshape(4, -1);
    cout << b << endl << endl;


    //Q3
    cout << "---Q3---" << endl;
    numpy c = a*b;
    cout << c << endl << endl;
    numpy d = concatenate(b, c, axis = 0);
    cout << d << endl << endl;
    numpy e = concatenate(a, c, axis = 1);
    cout << e << endl << endl;
    numpy f(e, slicing(0,2), slicing(1,3));
    cout << f << endl << endl;

    return 0;
}
