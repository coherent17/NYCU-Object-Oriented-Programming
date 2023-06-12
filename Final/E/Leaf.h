#ifndef _LEAF_H_
#define _LEAF_H_

#include "Position.h"
#include "Block.h"

class Leaf:public Block{
    public:
        Leaf(Position pos);
        ~Leaf();
        char** render();
};

#endif