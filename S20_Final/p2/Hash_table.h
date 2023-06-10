#ifndef _HASH_TABLE_H_
#define _HASH_TABLE_H_
#include<bits/stdc++.h>
using namespace std;
template <class T>
class Hash_table{
    class Hash{
        public:
            T value;
            Hash *next;
            Hash();
    };
    private:
        int key;
        Hash *head[10];
    public:
        Hash_table();
        void insert(T);
        void search(T);
        void show();
        void insertionsort(T);
};

#endif