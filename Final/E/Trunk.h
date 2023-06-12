#ifndef _TRUNK_H_
#define _TRUNK_H_

#include "Position.h"
#include "Block.h"

class Trunk:public Block{
    public:
        Trunk(Position pos);
        ~Trunk();
        char** render();
};

#endif