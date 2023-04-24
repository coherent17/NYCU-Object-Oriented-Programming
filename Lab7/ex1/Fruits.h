#ifndef FRUITS_H
#define FRUITS_H
#include "Stocks.h"

class Fruits : public Stocks {
    private:
        int *expired_month;
        int *expired_date;

    public:
        Fruits(int, int, int);
        ~Fruits();
        Fruits& operator=(const Stocks&);
        void Display();
};

#endif