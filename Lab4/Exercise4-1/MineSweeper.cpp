#include<bits/stdc++.h>
#include "MineSweeper.h"

using namespace std;

void MineSweeper::run(){
    newGame();
    render();

    while(1){
        int x, y;
        while(1){
            cout << "Please enter the coordinate (x, y) you want to press: "; cin >> x >> y;

            if(!isPosValid(y, x)){
                cout << "Invalid coordinate!" << endl;
                continue;
            }
            if(map[y][x].getIsOpen()){
                cout << "Grid (" << x << ", " << y << ") is already pressed!" << endl;
                continue;
            }
            if(isPosValid(y, x)) break;
        }

        if(map[y][x].getIsMine()){
            explodeAllMines();
            render();
            cout << "Mine explode! You lose!" << endl << endl;
            break;
        } 

        openGrid(y, x);
        checkWin();

        if(win){
            revealAllMines();
            render();
            cout << "You Win!" << endl;
            break;
        } 
        render();
    }
    string choice;
    cout << "Do you want to play another round?(y/n) "; cin >> choice;
    if(choice == "y"){
       map[0][0].resetGridOpenCount();
       run();
    }
    return;
}

void MineSweeper::newGame(){
    createNewMap();
    generateMines();
    countMine();
}


void MineSweeper::createNewMap(){
    int sX, sY;
    while(1){
        cout << "Please input map width: "; cin >> sX;
        cout << "Please input map height: "; cin >> sY;
        if(sX  > 0 && sY > 0){
            sizeX = sX;
            sizeY = sY;

            map = new Grid*[sizeY];
            for(int i = 0; i < sizeY; i++){
                map[i] = new Grid[sizeX];
            }

            while(1){
                int mineN;
                cout << "Please input number of mines: "; cin >> mineN;
                if(mineN > 0 && mineN <= sX * sY){
                    mineNum = mineN;
                    return;
                } 
                cout << "Input Error" << endl;
            }
        } 
        cout << "Input Error!" << endl;
    }
}

void MineSweeper::generateMines() {
    for (int i = 0; i < mineNum; i++) {
        int posY, posX;
        do {
            posY = rand() % sizeY;
            posX = rand() % sizeX;
        } while (map[posY][posX].getIsMine());
        map[posY][posX].setMine();
    }
}

void MineSweeper::countMine(){
    for(int i = 0; i < sizeX; i++){
        for(int j = 0; j < sizeY; j++){
            int count = 0;
            if(isPosValid(j+1, i)){
                if(map[j+1][i].getIsMine()) count++;
            }
            if(isPosValid(j-1, i)){
                if(map[j-1][i].getIsMine()) count++;
            }
            if(isPosValid(j, i+1)){
                if(map[j][i+1].getIsMine()) count++;
            }
            if(isPosValid(j, i-1)){
                if(map[j][i-1].getIsMine()) count++;
            }


            if(isPosValid(j-1, i-1)){
                if(map[j-1][i-1].getIsMine()) count++;
            }

            if(isPosValid(j-1, i+1)){
                if(map[j-1][i+1].getIsMine()) count++;
            }


            if(isPosValid(j+1, i-1)){
                if(map[j+1][i-1].getIsMine()) count++;
            }

            if(isPosValid(j+1, i+1)){
                if(map[j+1][i+1].getIsMine()) count++;
            }

            map[j][i].setMineCount(count);
        }
    }
}

void MineSweeper::openGrid(int pressedPosY, int pressedPosX){



    if(map[pressedPosY][pressedPosX].getMineCount() == 0){
        propagateWhiteSpace(pressedPosY, pressedPosX);
    }

    if(!map[pressedPosY][pressedPosX].getIsOpen())
        map[pressedPosY][pressedPosX].open();

}


void MineSweeper::propagateWhiteSpace(int pressedPosY, int pressedPosX){

    if(!isPosValid(pressedPosY, pressedPosX)) return;

    if(map[pressedPosY][pressedPosX].getIsMine() || map[pressedPosY][pressedPosX].getIsOpen()) return;

    map[pressedPosY][pressedPosX].open();

    if(map[pressedPosY][pressedPosX].getMineCount() != 0) return;

    propagateWhiteSpace(pressedPosY+1, pressedPosX);
    propagateWhiteSpace(pressedPosY-1, pressedPosX);
    propagateWhiteSpace(pressedPosY, pressedPosX+1);
    propagateWhiteSpace(pressedPosY, pressedPosX-1);

}

void MineSweeper::revealAllMines(){
    for(int i = 0; i < sizeX; i++){
        for(int j = 0; j < sizeY; j++){
            map[j][i].open();
        }
    }
}

void MineSweeper::explodeAllMines(){
    for(int i = 0; i < sizeX; i++){
        for(int j = 0; j < sizeY; j++){
            map[j][i].open();
            if(map[j][i].getIsMine()){
                map[j][i].setExplode();
            }
        }
    }
}

void MineSweeper::checkWin(){
    cout << map[0][0].getGridOpenCount() << " " << mineNum << endl;
    int totalGrid = sizeX * sizeY;
    if(totalGrid - map[0][0].getGridOpenCount() == mineNum){
        win = true;
        return;
    } 
    win = false;
}

bool MineSweeper::isPosValid(int posY, int posX){
    if(posY >= 0 && posX >= 0 && posY < sizeY && posX < sizeX) return true;
    return false;
}

void MineSweeper::render(){

    cout << "   ";
    for(int i = 0; i < sizeX; i++){
        cout << setw(2) << i;
    }
    cout << endl;

    cout << "   ";
    for(int i = 0; i < 2 * sizeX; i++){
        cout << "-";
    }
    cout << endl;

    for(int i = 0; i < sizeY; i++){
        cout << setw(2) << i << "|"; 
        for(int j = 0; j < sizeX; j++){
            map[i][j].render();
        }
        wcout << "|" << endl;
    }
    cout << "   ";
    for(int i = 0; i < 2 * sizeX; i++){
        cout << "-";
    }
    cout << endl;
}