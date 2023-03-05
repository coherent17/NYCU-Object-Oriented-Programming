#include <iostream>
#include "lab1-1.h"
using namespace Complex;
int main(){
    Cplex n;
    n.real = 1 * pi;
    n.image = -0.5;
    showComplex(n);
    return 0;
}
