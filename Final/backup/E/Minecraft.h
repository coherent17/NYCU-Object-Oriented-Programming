#ifndef _MINECRAFT_H_
#define _MINECRAFT_H_

#include <string>

using namespace std;

class Block;
class Player;

enum class ArrowKey { UP, DOWN, LEFT, RIGHT };

class Minecraft {
    int sizeX;
    int sizeY;


    // 2D array of Block*
    Block**(*map);

    Player* player = nullptr;

    bool exit = false;

    Block* selectedBlock = nullptr;


   public:
    int getSizeX() { return sizeX; };
    int getSizeY() { return sizeY; };
    void run();

    // Level1
    // Call buildMap
    Minecraft(string mapFilename);

    // delete blocks in map
    ~Minecraft();

    // Build map from map file
    void buildMap(string mapFilename);

    // Render blocks and player
    void render();

   private:
    // Level2
    // If 'a', player move left
    // Else if 'd', player move right
    // Else if 'x', exit game
    // Else if 'f', mine the selected block
    // After player move, selectedBlock = nullptr
    void onNormalKeyPress(char key);

    // Level3
    // Selected block
    // If selectedBlock == nullptr
    //   Selected block under player
    // Else
    //   Select the next block in the given direction
    //   of the current selected block
    //   The block also has to be inside the Player::mineDistance
    void onArrowKeyPress(ArrowKey key);
};

#endif