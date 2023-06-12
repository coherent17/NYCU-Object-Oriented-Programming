#ifndef _ROCK_H_
#define _ROCK_H_

#include "Position.h"
#include "Block.h"

class Rock:public Block{
    public:
        Rock(Position pos);
        ~Rock();
        char** render();
};

#endif