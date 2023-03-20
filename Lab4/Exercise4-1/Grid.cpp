#include<bits/stdc++.h>
#include "Grid.h"

using namespace std;

int Grid::gridOpenCount = 0;

void Grid::setMine(){
    isMine = true;
}

void Grid::setExplode(){
    isExplode = true;
}

void Grid::setMineCount(int mineCount){
    this->mineCount = mineCount;
}

void Grid::open(){
    isOpen = true;
    gridOpenCount++;
}

bool Grid::getIsMine(){
    return isMine;
}

bool Grid::getIsOpen(){
    return isOpen;
}

int Grid::getMineCount(){
    return mineCount;
}

void Grid::render(){
    if(isOpen == false) wcout << L"\u2B1C"; 
    else if(isOpen == true && mineCount == 0 && isMine == false) wcout << "  ";
    else if(isOpen == true && mineCount != 0 && isMine == false) wcout <<mineCount << " ";
    else if(isMine == true && isOpen == true && isExplode == true) wcout << L"\U0001F4A5";
    else if(isMine == true && isOpen == true && isExplode == false) wcout << L"\U0001F4A3";
}
