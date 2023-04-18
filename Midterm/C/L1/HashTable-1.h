#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;
struct node
{
    int itemNum;
    int price;
    node* ptr;
};
class HashTable{
private:
    int tableSize;
    node* tablePtr;
    int (*HashingFuncton)(int key, int tableSize);
public:
    HashTable(int tableSize);
    ~HashTable();

    void operator += (node n); //Insert data to hash table  
    void printTable();
    void searchTable();
    void analyzeTable();

    static int moduloDivision(int key, int tableSize); //Hashing function
};
#endif