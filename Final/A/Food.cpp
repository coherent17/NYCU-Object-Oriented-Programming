#include "Food.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

Food::Food(stringstream &ss):Commodity(){
    int *car_value = new int;
    int *pro_value = new int;
    int *fat_value = new int;
    ss >> name >> *price >> *car_value >> *pro_value >> *fat_value;
    ptr_vec.push_back(car_value);
    ptr_vec.push_back(pro_value);
    ptr_vec.push_back(fat_value);
    cal_score();
}

Food::~Food(){
    for(size_t i = 0; i < ptr_vec.size(); i++){
        delete ptr_vec[i];
    }
}

void Food::cal_score(){
    *score = double(*ptr_vec[1]) / double(*price);
}

void Food::show_spec(){
    cout << "name: " << name << endl;
    cout << "price: " << *price << endl;
    cout << "car: " << *ptr_vec[0] << endl;
    cout << "pro: " << *ptr_vec[1] << endl;
    cout << "fat: " << *ptr_vec[2] << endl;
    cout << "score: " << *score << endl;
    cout << "==================================" << endl;
}