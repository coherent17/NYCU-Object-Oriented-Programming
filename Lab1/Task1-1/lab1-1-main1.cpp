#include <iostream>
#include "lab1-1.h"
int main(){
    Complex::Cplex n;
    n.real = 1 * Complex::pi;
    n.image = -0.5;
    Complex::showComplex(n);
    return 0;
}
