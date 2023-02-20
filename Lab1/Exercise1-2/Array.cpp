// Array.cpp
#include <iostream>
using namespace std;
#include "Array.h"
// Member-function definitions for class Array.

Array::Array(int *array, int len){
    num_arr = new int[len];
    for(int i = 0; i < len; i++){
        num_arr[i] = array[i];
    }
    length = len;
}

Array::~Array(){
    delete [] num_arr;
}

void Array::showArray(){
    cout << "The number in num_arr is ";
    for(int i = 0; i < length; i++){
        cout << num_arr[i] << " ";
    }
    cout << endl;
}

void Array::add_num(){
    cout << "please enter a new number: ";
    int new_num;
    cin >> new_num;

    int *new_array = new int[(length + 1)];
    for(int i = 0; i < length; i++){
        new_array[i] = num_arr[i];
    }
    new_array[length] = new_num;
    length++;
    delete [] num_arr;
    num_arr = new_array;
}

int Array::count_n(){
    cout << "please enter a counting number: ";
    int num;
    cin >> num;
    int count = 0;
    for(int i = 0; i < length; i++){
        if(num_arr[i] == num) count++;
    }
    return count;
}