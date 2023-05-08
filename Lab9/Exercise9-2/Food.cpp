#include "Food.h"
#include <string>
#include <iostream>
using namespace std;

Food::Food(stringstream &ss):Commodity(){
    car_value = new int;
    pro_value = new int;
    fat_value = new int;
    ss >> name >> *price >> *car_value >> *pro_value >> *fat_value;
    cal_score();
}

Food::~Food(){
    delete car_value;
    delete pro_value;
    delete fat_value;
}

void Food::cal_score(){
    *score = double(*pro_value) / double(*price);
}

void Food::show_spec(){
    cout << "name: " << name << endl;
    cout << "price: " << *price << endl;
    cout << "car: " << *car_value << endl;
    cout << "pro: " << *pro_value << endl;
    cout << "fat: " << *fat_value << endl;
    cout << "score: " << *score << endl;
    cout << "==================================" << endl;
}