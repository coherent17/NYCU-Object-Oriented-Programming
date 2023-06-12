#ifndef _BLOCK_H_
#define _BLOCK_H_

#include "Position.h"

class Block {
   public:
    static const int sizeY = 4;
    static const int sizeX = 8;

   protected:
    bool selected = false;
    Position pos;
    int hardness;
    int minedCount = 0;

   public:
    void setSelected(bool selected) { this->selected = selected; }
    Position getPos() { return pos; }
    virtual ~Block() = default;

    // Level1
    // Construct block
    Block(Position pos);

    virtual char** render() = 0;

    // Level3
    // Mine the block
    // Increase minedCount
    // Return true if minedCount >= hardness, else return false
    bool mine();
};

#endif