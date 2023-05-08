#ifndef FOOD_H_
#define FOOD_H_

#include "Commodity.h"
#include <fstream>
#include <sstream>
using namespace std;

class Food: public Commodity{
    private:
        int *car_value;
        int *pro_value;
        int *fat_value;

    public:
        Food(stringstream &ss);
        ~Food();
        void cal_score();
        void show_spec();
};

#endif