#include <iostream>

#ifndef _GRID_H_
#define _GRID_H_
#include "Grid.h"
#endif

#define cout wcout

using namespace std;

class MineSweeper {
    private:
        //member variable
        int sizeX;
        int sizeY;
        int mineNum;
        bool win;
        Grid** map = nullptr;

    public:
        void run();

   private:
        // Prepare new grid map
        void newGame();
        void createNewMap();
        void generateMines();
        void countMine();

        // In game interaction
        void openGrid(int pressedPosY, int pressedPosX);
        void propagateWhiteSpace(int pressedPosY, int pressedPosX);

        // After game setting
        void revealAllMines();
        void explodeAllMines();

        // Helper functions
        void checkWin();
        bool isPosValid(int posY, int posX);

        // Render
        void render();
};