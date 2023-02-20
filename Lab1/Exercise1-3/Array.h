#ifndef ARRAY_H
#define ARRAY_H

namespace Array{
    typedef struct{
        int* num_arr;
        int length;
    }Arr;
    void initialize(Arr &A, int* arr, int len);
    void showArray(Arr &A);
    void add_num(Arr &A);
    int count_n(Arr &A);
}

#endif