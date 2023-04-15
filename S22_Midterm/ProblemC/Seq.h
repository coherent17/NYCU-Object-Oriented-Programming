#ifndef _Seq_H__
#define _Seq_H__
#include <iostream>
#include <string>

using namespace std;

class Seq{
    private:
        int *data;
        int size;
    public:
        //Q1
        Seq(string);
        Seq(int);
        Seq (int *data, int size);
        ~Seq();
        void display();

        //Q2
        void operator >>(int); // right circular shift
        void operator <<(int); // left circular shift
        Seq operator-(); // circular time reversal
        Seq(const Seq&); // copy constructor

        //Q3
        friend Seq operator *(const Seq& , const Seq&); // convolution sum
        Seq mid_filter(int); // median filter
};

#endif