#include "Food.h"
#include "Healthy.h"
#include "Commodity.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const Commodity* c1, Commodity *c2){
    return c1->name < c2->name;
}

int main(int argc, char** argv){
    string filename = string(argv[1]);
    ifstream fin(filename);

    vector<Commodity *> V;
    string line;
    while(getline(fin, line)){
        stringstream ss(line);
        ss >> line;
        Commodity *temp;
        if(line == "H") temp = new Healthy(ss);
        else temp = new Food(ss);
        V.push_back(temp);
    }
    fin.close();

    sort(V.begin(), V.end(), cmp);
    for(size_t i = 0; i < V.size(); i++){
        V[i]->show_spec();
    }
    for(size_t i = 0; i < V.size(); i++){
        delete V[i];
    }
}