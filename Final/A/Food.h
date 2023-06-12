#ifndef FOOD_H_
#define FOOD_H_

#include "Commodity.h"
#include <vector>
using namespace std;

class Food: public Commodity{
    private:
        vector<int *> ptr_vec;

    public:
        Food(stringstream &ss);
        ~Food();
        void cal_score();
        void show_spec();
};

#endif