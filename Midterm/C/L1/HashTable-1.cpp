#include "HashTable-1.h"
#include <iostream>

using namespace std;

HashTable::HashTable(int tableSize){
    this->tableSize = tableSize;
    HashingFuncton = moduloDivision;
    tablePtr = new node[tableSize];
    for(int i = 0; i < tableSize; i++){
        tablePtr[i].ptr = nullptr;
    }
}

HashTable::~HashTable(){
    node *temp, *current;
    for (int i = 0; i < tableSize; i++) {
        current = tablePtr[i].ptr;
        while(current != nullptr){
            temp = current;
            current = current->ptr;
            delete temp;
        }
        tablePtr[i].ptr = nullptr;
    }
    
    delete []tablePtr;
}

void HashTable::operator+=(node n){
    int idx = HashingFuncton(n.itemNum, tableSize);
    node *current = tablePtr[idx].ptr;
    node *prev = nullptr;

    while(current != nullptr){
        prev = current;
        current = current->ptr;
    }

    node *newnode = new node;
    newnode->itemNum = n.itemNum;
    newnode->price = n.price;
    newnode->ptr = nullptr;

    if(prev == nullptr){
        tablePtr[idx].ptr = newnode;
    }
    else{
        prev->ptr = newnode;
    }
}

void HashTable::printTable(){
    cout << endl;
    cout << "Home Addr\tPrime Area\tOverflow List" << endl; 

    for(int i = 0; i < tableSize; i++){
        cout << i;
        if(tablePtr[i].ptr == nullptr){
            cout << endl;
            continue;
        }
        
        cout << "\t\t";
        node *temp = tablePtr[i].ptr;
        cout << temp->itemNum << "/" << temp->price << "\t\t";
        temp = temp->ptr;
        
        while(temp != nullptr){
            cout << temp->itemNum << "/" << temp->price;
            if(temp->ptr != nullptr) cout << ", ";
            temp = temp->ptr;
        }
        cout << endl;
    }

}

void HashTable::searchTable(){
    int inputItemNumber;
    cout << "Please enter the item number: "; cin >> inputItemNumber;
    int idx = HashingFuncton(inputItemNumber, tableSize);
    if(tablePtr[idx].ptr == nullptr){
        cout << "Not Found" << endl;
        return;
    }
    node *temp = tablePtr[idx].ptr;
    while(temp != nullptr){
        if(temp->itemNum == inputItemNumber){
            cout << "Price: " << temp->price << endl;
            return;
        }
        temp = temp->ptr;
    }
    cout << "Not Found" << endl;
}

void HashTable::analyzeTable(){
    int primeAreaCount = 0;
    for(int i = 0; i < tableSize; i++){
        if(tablePtr[i].ptr != nullptr) primeAreaCount++;
    }

    int OverflowNodeCount = 0;
    for(int i = 0; i < tableSize; i++){
        if(tablePtr[i].ptr != nullptr && tablePtr[i].ptr->ptr != nullptr){
            node *temp = tablePtr[i].ptr->ptr;
            while(temp != nullptr){
                OverflowNodeCount++;
                temp = temp->ptr;
            }
        }
    }

    int MaxLength = 0;
    for(int i = 0; i < tableSize; i++){
        if(tablePtr[i].ptr != nullptr){
            int length = 0;
            node *temp = tablePtr[i].ptr;
            while(temp != nullptr){
                length++;
                temp = temp->ptr;
            }
            MaxLength = MaxLength > length ? MaxLength : length;
        }
    }

    cout << endl;
    cout << "Percentage of Prime Area filled: " << double(primeAreaCount) / double(tableSize) * 100 << "%" << endl;
    cout << "Average nodes in overflow lists: " << double(OverflowNodeCount) / double(tableSize) << endl;
    cout << "Longest linked list: " << MaxLength << endl;

}

int HashTable::moduloDivision(int key, int tableSize){
    return key % tableSize;
}