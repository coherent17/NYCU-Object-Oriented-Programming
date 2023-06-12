#ifndef _AIR_H_
#define _AIR_H_

#include "Position.h"
#include "Block.h"

class Air:public Block{
    public:
        Air(Position pos);
        ~Air();
        char** render();
};

#endif