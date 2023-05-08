#include "Healthy.h"
#include <iostream>

using namespace std;
Healthy::Healthy(stringstream& ss):Commodity(){
    ss >> name >> *price >> arr_length;
    name_arr = new string[arr_length];
    value_arr = new int[arr_length];
    for(int i = 0; i < arr_length; i++){
        ss >> name_arr[i];
        ss >> value_arr[i];
    }
    cal_score();
}

Healthy::~Healthy(){
    delete []name_arr;
    delete []value_arr;
}

void Healthy::cal_score(){
    double sum = 0;
    for(int i = 0; i < arr_length; i++){
        sum += value_arr[i];
    }
    *score = double(sum) / double(*price);
}

void Healthy::show_spec(){
    cout << "name: " << name << endl;
    cout << "price: " << *price << endl;

    for(int i = 0; i < arr_length; i++){
        cout << name_arr[i] << ": " << value_arr[i] << endl;
    }

    cout << "score: " << *score << endl;
    cout << "==================================" << endl;
}