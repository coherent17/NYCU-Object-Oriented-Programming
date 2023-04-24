#ifndef _PAIR_H_
#define _PAIR_H_
#include <iostream>

class Pair
{
private:
    int first;
    int second;
    static int count;
    void operator*=(Pair &);

public:
    friend class Container;
    // Level 1 25%
    // Constructors and destructor
    Pair();
    Pair(int);
    Pair(int, int);
    Pair(const Pair &);
    ~Pair();

    // Accessor and mutators
    void setPair(int, int);
    int getKey();
    int getValue();

    // Static functions
    static int getCount();
    static Pair **readBinaryFile(char *, int);

    // Operator overloads
    Pair &operator=(const Pair &);
    bool operator<(const Pair &);
    friend std::ostream &operator<<(std::ostream &, const Pair);
};
#endif