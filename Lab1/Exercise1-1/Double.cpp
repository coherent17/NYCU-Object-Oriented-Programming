#include <iostream>
#include <cmath>
#include "Double.h"

using namespace std;

Double::Double(double num_paramter){
    num = num_paramter;
}

Double::~Double(){
}

double Double::Round(){
    return floor(num + 0.5);
}

double Double::Ceil(){
    return ceil(num);
}

double Double::Floor(){
    return floor(num);
}

void Double::showResult(){
    cout << "the beginning of the function(showResult)" << endl;
    cout << "Round(" << num << ") = " << Round() << endl;
    cout << "Ceil(" << num << ") = " << Ceil() << endl;
    cout << "Floor(" << num << ") = " << Floor() << endl;
    cout << "the end of the function(showResult)" << endl;
}