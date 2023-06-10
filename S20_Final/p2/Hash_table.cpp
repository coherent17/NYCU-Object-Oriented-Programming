#include "Hash_table.h"
#include "Point2D.h"
//operator overloading for string
int operator%(string a, int b){
    int ret = 0;
    for(size_t i = 0; i < a.length(); i++)
        ret += a[i];
    return ret % b;
}

template <class T>
Hash_table<T>::Hash::Hash(){
    next = nullptr;
}

template <class T>
Hash_table<T>::Hash_table(){
    for(int i = 0; i < 10; i++){
        head[i] = nullptr;
    }
}

template <class T>
void Hash_table<T>::insert(T value){
    Hash *temp = head[key = value % 10];
    if(temp == nullptr){
        head[key] = new Hash;
        head[key]->value = value;
    }
    else{
        //find the tail
        while(temp->next){
            temp = temp->next;
        }
        temp->next = new Hash;
        temp->next->value = value;
    }
}

template <class T>
void Hash_table<T>::search(T value){
    Hash *temp = head[value % 10];
    while(temp){
        if(temp->value == value){
            cout << value << " exists." << endl;
            return;
        }
        temp = temp->next;
    }
    cout<< value <<" does not exist."<<endl;
}

template <class T>
void Hash_table<T>::show(){
    for(int i = 0; i < 10; i++){
        Hash *temp = head[i];
        if(temp){
            cout << "index: " << i << endl;
            while(temp){
                cout << temp->value << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
}

template <class T>
void Hash_table<T>::insertionsort(T value){
    Hash *temp = head[key = value % 10];
    if(!temp){
        head[key] = new Hash;
        head[key]->value = value;
        return;
    }
    if(head[key]->value > value){
        Hash *tmp = head[key];
        head[key] = new Hash;
        head[key]->value = value;
        head[key]->next = tmp;
        return;
    }
    while(temp->next){
        if(temp->next->value > value){
            Hash *tmp = temp->next;
            temp->next = new Hash;
            temp->next->value = value;
            temp->next->next = tmp;
            return;
        }
        temp = temp->next;
    }
    temp->next = new Hash;
    temp->next->value = value;
}


template Hash_table<int>::Hash_table();
template Hash_table<string>::Hash_table();
template Hash_table<Point2D>::Hash_table();

template void Hash_table<int>::insert(int);
template void Hash_table<string>::insert(string);
template void Hash_table<Point2D>::insert(Point2D);

template void Hash_table<int>::search(int);
template void Hash_table<string>::search(string);
template void Hash_table<Point2D>::search(Point2D);

template void Hash_table<int>::show();
template void Hash_table<string>::show();
template void Hash_table<Point2D>::show();

template void Hash_table<int>::insertionsort(int);
template void Hash_table<string>::insertionsort(string);
template void Hash_table<Point2D>::insertionsort(Point2D);