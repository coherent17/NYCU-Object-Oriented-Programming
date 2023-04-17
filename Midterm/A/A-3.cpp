#include <iostream>

#include "Matrix.h"

using namespace std;


int main() {
    Matrix a(4, 4);
    a.setValue(0, 0, 1.2);
    a.setValue(0, 1, 2.2);
    a.setValue(0, 2, 3.2);
    a.setValue(0, 3, 3.2);
    a.setValue(1, 0, 4.2);
    a.setValue(1, 1, 5.2);
    a.setValue(1, 2, 6.2);
    a.setValue(1, 3, 6.2);
    a.setValue(2, 0, -2.3);
    a.setValue(2, 1, 5.2);
    a.setValue(2, 2, 6.3);
    a.setValue(2, 3, 6.2);
    a.setValue(3, 0, -3.8);
    a.setValue(3, 1, 5.9);
    a.setValue(3, 2, 6.2);
    a.setValue(3, 3, 8.3);

    cout << "a =\n" << a << endl;
    cout << "a.determinant() = " << a.determinant() << endl;
}