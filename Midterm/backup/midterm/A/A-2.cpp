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


    const double c = 1.7;

    cout << "a =\n" << a << endl;
    cout << "b =\n" << b << endl;
    cout << "c = " << c << endl << endl;
    cout << "a * b =\n" << a * b << endl;
    cout << "b * a =\n" << b * a << endl;
    cout << "a * c =\n" << a * c << endl;
    cout << "c * b =\n" << c * b << endl;

    a *= b * a * c;
    cout << "a *= b * a * c" << endl << endl;
    cout << "a =\n" << a << endl;

    a *= -c;
    cout << "a *= -c" << endl << endl;
    cout << "a =\n" << a << endl;



    Matrix d(2, 3);
    d.setValue(0, 0, 1);
    d.setValue(0, 1, 2);
    d.setValue(0, 2, 3);
    d.setValue(1, 0, 4);
    d.setValue(1, 1, 5);
    d.setValue(1, 2, 6);


    Matrix e(3, 2);
    e.setValue(0, 0, 1);
    e.setValue(0, 1, 2);
    e.setValue(1, 0, 3);
    e.setValue(1, 1, 4);
    e.setValue(2, 0, 5);
    e.setValue(2, 1, 6);

    cout << "d =\n" << d << endl;
    cout << "e =\n" << e << endl;
    cout << "d * e =\n" << d * e << endl;
    cout << "e * d =\n" << e * d << endl;

}