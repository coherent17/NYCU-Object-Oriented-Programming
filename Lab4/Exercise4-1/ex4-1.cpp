#include <iostream>


#ifndef _MINESWEEPER_H_
#define _MINESWEEPER_H_
#include "MineSweeper.h"
#endif


int main() {
    setlocale(LC_ALL, "en_US.utf-8");

    srand(0);

    MineSweeper game;
    game.run();
}