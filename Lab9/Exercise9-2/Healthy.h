#ifndef HEALTHY_H_
#define HEALTHY_H_
#include <fstream>
#include <sstream>
#include "Commodity.h"
using namespace std;

class Healthy: public Commodity{
    private:
        string *name_arr;
        int *value_arr;
        int arr_length;
    
    public:
        Healthy(stringstream& ss);
        ~Healthy();
        void cal_score();
        void show_spec();
};

#endif