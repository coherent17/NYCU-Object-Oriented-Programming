#ifndef SUV_H
#define SUV_H

#include<bits/stdc++.h>
using namespace std;
#include "Vehicle.h"
class SUV : public Vehicle{
    public:
        SUV(string brand, string model, double price, string transmission_type);
};

#endif