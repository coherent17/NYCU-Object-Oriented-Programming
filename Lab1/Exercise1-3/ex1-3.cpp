#include <iostream>
#include "Array.h"

using namespace std;
using namespace Array;

int main(){
    int len;
    cout << "please enter the initial length: ";
    cin >> len;

    cout << "please enter " << len << " integer numbers: ";


    int *array = new int[len];
    for(int i = 0; i < len; i++){
        cin >> array[i];
    }

    Arr a;
    initialize(a, array, len);
    showArray(a);


    int count = count_n(a);
    cout << "The counting number appears " << count << " times in the num_arr" << endl;

    add_num(a);
    showArray(a);

    count = count_n(a);
    cout << "The counting number appears " << count << " times in the num_arr" << endl;

    add_num(a);
    showArray(a);

    count = count_n(a);
    cout << "The counting number appears " << count << " times in the num_arr" << endl;

    return 0;
}