#include <iostream>

#include "Matrix.h"

using namespace std;


int main() {
    Matrix a(2, 2);
    a.setValue(0, 0, 1);
    a.setValue(1, 1, 2);



    double** b_arr = new double*[2];
    b_arr[0] = new double[2];
    b_arr[1] = new double[2];

    b_arr[0][0] = 0.5;
    b_arr[0][1] = 3.2;
    b_arr[1][0] = 1.6;
    b_arr[1][1] = -0.3;
    const Matrix b(2, 2, b_arr);

    delete [] b_arr[0];
    delete [] b_arr[1];
    delete [] b_arr;


    cout << "a =\n" << a << endl;
    cout << "b =\n" << b << endl;
    cout << "a + b =\n" << a + b << endl;
    cout << "a - b =\n" << a - b << endl;
    cout << "+b =\n" << +b << endl;
    cout << "-b =\n" << -b << endl;
    cout << "a.transpose() =\n" << a.transpose() << endl;
    cout << "b.transpose() =\n" << b.transpose() << endl;



    Matrix c = a;
    cout << "c = a" << endl;

    Matrix d = -b;
    cout << "d = -b" << endl;
  
    c += a + b;
    cout << "c += a + b" << endl;

    d -= c + a;
    cout << "d -= c + a" << endl;

    cout << "c =\n" << c << endl;
    cout << "d =\n" << d << endl;

    d = c;
    cout << "d = c" << endl;

    cout << "(a != b) = " << (a != b) << endl;
    cout << "(c != d) = " << (c != d) << endl;
    cout << "(c == d) = " << (c == d) << endl;


    Matrix e(2, 3);
    Matrix f(3, 2);

    e.setValue(1, 2, 3);
    f.setValue(2, 1, -2);

    cout << "e =\n" << e << endl;
    cout << "f =\n" << f << endl;
    cout << "e.transpose() =\n" << e.transpose() << endl;
    cout << "f.transpose() =\n" << f.transpose() << endl;


    f = e;
    cout << "f = e" << endl;

    cout << "f =\n";
    cout << f << endl;

    e = a;
    cout << "e = a" << endl;

    cout << "e =\n";
    cout << e << endl;
}