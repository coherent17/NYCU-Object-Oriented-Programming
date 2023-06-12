#ifndef VAN_H
#define VAN_H

#include<bits/stdc++.h>
using namespace std;
#include "Vehicle.h"
class Van : public Vehicle{
    public:
        Van(string brand, string model, double price, string transmission_type);
};

#endif