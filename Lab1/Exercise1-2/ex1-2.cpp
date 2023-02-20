#include <iostream>
#include "Array.h"

using namespace std;

int main(){
    int len;
    cout << "please enter the initial length: ";
    cin >> len;

    cout << "please enter " << len << " integer numbers: ";
    

    int *array = new int[len];
    for(int i = 0; i < len; i++){
        cin >> array[i];
    }

    Array a(array, len);
    a.showArray();


    int count = a.count_n();
    cout << "The counting number appears " << count << " times in the num_arr" << endl;

    a.add_num();
    a.showArray();

    count = a.count_n();
    cout << "The counting number appears " << count << " times in the num_arr" << endl;

    a.add_num();
    a.showArray();

    count = a.count_n();
    cout << "The counting number appears " << count << " times in the num_arr" << endl;

    return 0;
}