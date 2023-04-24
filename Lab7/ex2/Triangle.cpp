#include "Triangle.h"
#include <cmath>

Triangle::Triangle(){

}

Triangle::Triangle(int a, int b, int c){
    setL(a);
    setx(b);
    sety(c);
    setSize(20);
}

Triangle::Triangle(int a, int b, int c, int d){
    setL(a);
    setx(b);
    sety(c);
    setSize(d);
}

Triangle::~Triangle(){

}

void Triangle::ComputeArea(){
    cout << "Area: " << getL() * getL() << endl;
}

void Triangle::ComputePerimeter(){
    cout << "Perimeter : " << 2 * getL() + 2 * sqrt(2) * getL() << endl;
}

void Triangle::ComputePoints(){

    int topx = getx();
    int topy = gety();
    int L = getL();

    appendPoints(topx, topy);
    int count = 1;
    for(int j = topy - 1; j >= topy - 1 - L + 2; j--){
        appendPoints(topx + count, j);
        appendPoints(topx - count, j);
        count++;
    }
    for(int i = topx - count; i <= topx + count; i++){
        appendPoints(i, topy - L);
    }
}