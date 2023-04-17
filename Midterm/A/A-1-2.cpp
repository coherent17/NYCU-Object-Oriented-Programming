#include <iostream>

#include "Matrix.h"

using namespace std;


int main() {
    Matrix a(3, 3);
    a.setValue(0, 0, 1);
    a.setValue(1, 1, 2);
    a.setValue(2, 2, -1);


    double** b_arr = new double*[3];
    b_arr[0] = new double[3];
    b_arr[1] = new double[3];
    b_arr[2] = new double[3];

    b_arr[0][0] = 4.3;
    b_arr[0][1] = 2.3;
    b_arr[0][2] = -1.7;
    b_arr[1][0] = 1.9;
    b_arr[1][1] = -0.5;
    b_arr[1][2] = -0.7;
    b_arr[2][0] = 4.5;
    b_arr[2][1] = 0.8;
    b_arr[2][2] = 2.3;
    const Matrix b(3, 3, b_arr);

    delete [] b_arr[0];
    delete [] b_arr[1];
    delete [] b_arr[2];
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
    cout << "(a == b) = " << (a == b) << endl;


    Matrix e(3, 4);
    Matrix f(4, 3);

    e.setValue(0, 2, 3);
    f.setValue(2, 0, -1);

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