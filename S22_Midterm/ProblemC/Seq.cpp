#include "Seq.h"
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

//Q1
Seq::Seq(string filename){
    ifstream file(filename, ios::binary);

    int number;
    file.read(reinterpret_cast<char*>(&number), sizeof(number));
    size = number;

    data = new int[size];
    int idx = 0;
    while (file.read(reinterpret_cast<char*>(&number), sizeof(number))){
        data[idx] = number;
        idx++;
    }
    file.close();
}

Seq::Seq(int size){
    this->size = size;
    data = new int[size];
    for(int i = 0; i < size; i++){
        data[i] = 0;
    }
}

Seq::Seq(int *data, int size){
    this->data = data;
    this->size = size;
}

Seq::~Seq(){
    delete []data;
}

void Seq::display(){
    for(int i = 0; i < size; i++){
        cout << data[i] << " ";
    }
    cout << endl;
}

//Q2
void Seq::operator>>(int offset){

    int *newData = new int[size];

    for (int i = 0; i < size; i++) {
        newData[(i + offset) % size] = data[i];
    }
    delete []data;
    data = newData;
}

void Seq::operator<<(int offset){
    int *newData = new int[size];

    for (int i = 0; i < size; i++) {
        newData[(i - offset + size) % size] = data[i];
    }
    delete []data;
    data = newData;
}

Seq Seq::operator-(){

    int *newData = new int[size];
    newData[0] = data[0];

    for(int i = 1; i < size; i++){
        newData[(size - i)] = data[i];
    }
    delete []data;
    data = newData;
    return *this;
}

Seq::Seq(const Seq& s){
    this->size = s.size;
    this->data = new int[s.size];
    for(int i = 0; i < s.size; i++){
        this->data[i] = s.data[i];
    }
}


//Q3
Seq operator *(const Seq& a, const Seq& b){
    int retSize = a.size + b.size - 1;
    int *retData = new int[retSize];
    for(int i = 0; i < retSize; i++){
        retData[i] = 0;
    }

    for(int i = 0; i < retSize; i++){
        for(int j = 0; j < b.size; j++){
            if(i - j >= 0 && i - j < a.size)
                retData[i] += a.data[i - j] * b.data[j];
        }
    }

    return Seq(retData, retSize);
}

Seq Seq::mid_filter(int M){
    int temp_size = (M - 1) / 2 + size + (M - 1) / 2;
    int *temp = new int[temp_size];
    for(int i = 0; i < temp_size; i++){
        temp[i] = 0;
    }

    for(int i = 0; i < size; i++){
        temp[i + (M - 1) / 2] = data[i];
    }

    int retSize = size;
    int *retData = new int[retSize];

    int curIndex = 0;

    for(int i = 0; i + M < temp_size; i++){
        vector<int> window;
        for(int j = i; j <= i + M - 1; j++){
            window.push_back(temp[j]);
        }
        sort(window.begin(), window.end());
        if (window.size() % 2 == 1) {
            retData[curIndex++] = window[window.size() / 2];
        } 
        else {
            int middle1 = window[(window.size() - 1) / 2];
            int middle2 = window[(window.size() + 1) / 2];
            retData[curIndex++] = (middle1 + middle2) / 2;
        }

    }

    return Seq(retData, retSize);
}