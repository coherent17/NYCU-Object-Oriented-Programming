#include "Pair.h"
#include <fstream>

using namespace std;

int Pair::count = 0;


void Pair::operator*=(Pair &P){
    Pair temp = Pair(first, second);
    first = P.first;
    second = P.second;
    P.first = temp.first;
    P.second = temp.second;
}

Pair::Pair(){
    first = 0;
    second = 0;
    count++;
}

Pair::Pair(int a){
    first = a;
    second = 0;
    count++;
}

Pair::Pair(int a, int b){
    first = a;
    second = b;
    count++;
}

Pair::Pair(const Pair &p){
    this->first = p.first;
    this->second = p.second;
    count++;
}

Pair::~Pair(){
    count--;
}

void Pair::setPair(int a, int b){
    first = a;
    second = b;
}

int Pair::getKey(){
    return first;
}

int Pair::getValue(){
    return second;
}

int Pair::getCount(){
    return count;
}

Pair **Pair::readBinaryFile(char *filename, int numPairs){
    ifstream fin(filename, ios::binary);
    Pair **ret = new Pair*[numPairs];
    for(int i = 0; i < numPairs; i++){
        int key, value;
        fin.read(reinterpret_cast<char*>(&key), sizeof(key));
        fin.read(reinterpret_cast<char*>(&value), sizeof(value));
        ret[i] = new Pair(key, value);
    }
    fin.close();
    return ret;
}

Pair &Pair::operator=(const Pair &P){
    first = P.first;
    second = P.second;
    return *this;
}

bool Pair::operator<(const Pair &P){
    return first < P.first;
}

ostream& operator<<(ostream &out, const Pair P){
    out << "key: " << P.first << ", value: " << P.second << endl;
    return out;
}

