#ifndef HEALTHY_H_
#define HEALTHY_H_
#include <fstream>
#include <sstream>
#include "Commodity.h"
#include <map>
using namespace std;

class Healthy: public Commodity{
    private:
        int arr_length;
        map<string, int> healthy_map;
    
    public:
        Healthy(stringstream& ss);
        ~Healthy();
        void cal_score();
        void show_spec();
};

#endif