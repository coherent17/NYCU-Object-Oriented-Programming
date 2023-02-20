// ex1-3.cpp
#include <iostream>
using namespace std;
#include "Array.h"

void Array::initialize(Arr &A, int* arr, int len){
    A.num_arr = arr;
    A.length = len;
}

void Array::showArray(Arr &A){
    cout << "The number in num_arr is ";
    for(int i = 0; i < A.length; i++){
        cout << A.num_arr[i] << " ";
    }
    cout << endl;
}

void Array::add_num(Arr &A){
    cout << "please enter a new number: ";
    int new_num;
    cin >> new_num;

    int *new_array = new int[(A.length + 1)];
    for(int i = 0; i < A.length; i++){
        new_array[i] = A.num_arr[i];
    }
    new_array[A.length] = new_num;
    A.length++;
    delete [] A.num_arr;
    A.num_arr = new_array;
}

int Array::count_n(Arr &A){
    cout << "please enter a counting number: ";
    int num;
    cin >> num;
    int count = 0;
    for(int i = 0; i < A.length; i++){
        if(A.num_arr[i] == num) count++;
    }
    return count;
}