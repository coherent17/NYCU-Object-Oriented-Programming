#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>

#include "Position.h"

using namespace std;

class Block;

class Player {
   public:
    const static int sizeX = 8;
    const static int sizeY = 8;
    const static int mineDistance = 5;

    enum class Movement { LEFT, RIGHT };

   private:
    Position pos;
    Block**(*map);
    int mapSizeX;
    int mapSizeY;

   public:
    Position getPos() { return pos; };

    // Level1
    // Construct player
    Player(Position pos, Block*** map, int mapSizeY, int mapSizeX);

    // Render player
    char** render();

    // Level2
    // Move the player left or right
    // Player can go up 1 block
    // Player will fall if there is no block below
    // Need to check for x bound
    void move(Movement movement);

    // Level3
    // Mine a block
    // Call block->mine()
    // If the block below player is mined, player will fall
    // Return true if block is mined, else return false
    bool mine(Position pos);
};

#endif