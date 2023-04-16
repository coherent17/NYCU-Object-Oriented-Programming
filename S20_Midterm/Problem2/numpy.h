#ifndef _NUMPY_H_
#define _NUMPY_H_

#include <iostream>

class numpy{
    private:
        int** array;
        int row;
        int column;

    public:
        numpy();
        ~numpy();
        numpy(const char *input_file);
        numpy(int x, int y);
        numpy(const numpy &);
        numpy(const numpy &, int* , int* );
        
        //Q1
        int max();
        int* argmax();


        //Q2
        int get_row();
        int get_column();
        friend std::ostream& operator<<(std::ostream&, numpy&);
        int* operator[](int);
        void sort(int axis);
        numpy reshape(int, int);

        //Q3
        numpy operator*(numpy&);
        friend numpy concatenate(numpy&, numpy&, int axis);
        friend int* slicing(int, int);
};

#endif
