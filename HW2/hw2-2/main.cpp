#include "Role.h"
#include "Mage.h"
#include "Warrior.h"
#include "Vampire.h"
#include <iostream>
#include <cstring>
using namespace std;

void concat(string s1, string s2, int initSpaceCount, int midSpaceCount){
    int row = 5;
    int col1 = s1.length() / row;
    string m1[row][col1];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col1; j++) {
            m1[i][j] = s1.substr(i * col1 + j, 1);
        }
    }

    int col2 = s2.length() / row;
    string m2[row][col2];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col2; j++) {
            m2[i][j] = s2.substr(i * col2 + j, 1);
        }
    }

    for(int i = 0; i < row; i++){
        for(int j = 0; j < initSpaceCount; j++){
            cout << " ";
        }

        for(int j = 0; j < col1; j++){
            cout << m1[i][j];
        }

        for(int j = 0; j < midSpaceCount; j++){
            cout << " ";
        }

        for(int j = 0; j < col2; j++){
            cout << m2[i][j];
        }
        cout << endl;
    }
}

int main(){

    int p1_choice, p2_choice;
    Role *Player1, *Player2;
    cout << "Player 1 choose role:" << endl;
    cout << "1. Mage" << endl;
    cout << "2. Warrior" << endl;
    cout << "3. Vampire" << endl;
    cin >> p1_choice;

    cout << "Player 2 choose role:" << endl;
    cout << "1. Mage" << endl;
    cout << "2. Warrior" << endl;
    cout << "3. Vampire" << endl;
    cin >> p2_choice;

    switch(p1_choice){
        case 1:
            Player1 = new Mage();
            break;
        case 2:
            Player1 = new Warrior();
            break;
        case 3:
            Player1 = new Vampire();
            break;
        default:
            Player1 = nullptr;
            break;
    }

    switch(p2_choice){
        case 1:
            Player2 = new Mage();
            break;
        case 2:
            Player2 = new Warrior();
            break;
        case 3:
            Player2 = new Vampire();
            break;
        default:
            Player2 = nullptr;
            break;
    }

    cout << "Player 1: " << *Player1 << endl;
    cout << "Player 2: " << *Player2 << endl;
    concat(Player1->get_DEFAULT_ICON1(), Player1->get_DEFAULT_ICON2(), 6, 8);
    concat(Player1->get_DEFAULT_ICON1(), Player1->get_ATTACK_ICON2(), 6, 0);
    concat(Player1->get_ATTACK_ICON1(), Player1->get_DEFAULT_ICON2(), 10, 0);
    concat(Player1->get_DEFAULT_ICON1(), Player1->get_DEFENSE_ICON2(), 6, 8);

    // int Round = 1;
    // bool Play1First = (Player1->get_speed() > Player2->get_speed());
    // while(Player1->get_hp() > 0 && Player2->get_hp() > 0){
    //     cout << "Round: " << Round << endl;
    //     if(Play1First){

    //     }
    //     else{

    //     }
    //     Round++;
    // }

    return 0;
}