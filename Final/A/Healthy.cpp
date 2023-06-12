#include "Healthy.h"
#include <iostream>

using namespace std;
Healthy::Healthy(stringstream& ss):Commodity(){
    ss >> name >> *price >> arr_length;
    for(int i = 0; i < arr_length; i++){
        string a;
        int b;
        ss >> a;
        ss >> b;
        cout << a << " " << b << endl;
        if(healthy_map.find(a) != healthy_map.end()){
            healthy_map[a] = healthy_map[a]+ b;
            
        }
        else{
            healthy_map[a] = b;
        }
            
    }
    cal_score();
}

Healthy::~Healthy(){
    ;
}

void Healthy::cal_score(){
    double sum = 0;
    map<string, int>::iterator it;

    for (it = healthy_map.begin(); it != healthy_map.end(); it++){
        sum += it->second;
    }

    *score = double(sum) / double(*price);
}

void Healthy::show_spec(){
    cout << "name: " << name << endl;
    cout << "price: " << *price << endl;

    map<string, int>::iterator it;

    for (it = healthy_map.begin(); it != healthy_map.end(); it++)
    {
        std::cout << it->first    // string (key)
                << ':'
                << it->second   // string's value 
                << std::endl;
    }

    cout << "score: " << *score << endl;
    cout << "==================================" << endl;
}