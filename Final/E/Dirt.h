#ifndef _DIRT_H_
#define _DIRT_H_

#include "Position.h"
#include "Block.h"

class Dirt:public Block{
    public:
        Dirt(Position pos);
        ~Dirt();
        char** render();
};

#endif