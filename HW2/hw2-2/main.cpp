#define ATTACK 1
#define DEFENSE 2

#define MAGE 1
#define WARRIOR 2
#define VAMPIRE 3

#include "Role.h"
#include "Mage.h"
#include "Warrior.h"
#include "Vampire.h"
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
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
    srand(time(NULL));
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
            Player1 = new Mage(1);
            break;
        case 2:
            Player1 = new Warrior(1);
            break;
        case 3:
            Player1 = new Vampire(1);
            break;
        default:
            Player1 = nullptr;
            break;
    }

    switch(p2_choice){
        case 1:
            Player2 = new Mage(2);
            break;
        case 2:
            Player2 = new Warrior(2);
            break;
        case 3:
            Player2 = new Vampire(2);
            break;
        default:
            Player2 = nullptr;
            break;
    }

    cout << "Player 1: " << *Player1 << endl;
    cout << "Player 2: " << *Player2 << endl;
    cout << endl;

    int Round = 1;

    //check is Player1 play first or not
    bool Play1 = (Player1->get_speed() > Player2->get_speed());

    while(Player1->get_hp() > 0 && Player2->get_hp() > 0){
        cout << "Round: " << ceil(Round / 2.0) << endl;
        if(Play1) cout << "player 1's turn" << endl;
        else cout << "player 2's turn" << endl;

        //4 conditions
        if(Player1->get_isDenfense() == false && Player2->get_isDenfense() == false) concat(Player1->get_DEFAULT_ICON(), Player2->get_DEFAULT_ICON(), 6, 8);
        else if(Player1->get_isDenfense() == true && Player2->get_isDenfense() == false) concat(Player1->get_DEFENSE_ICON(), Player2->get_DEFAULT_ICON(), 6, 7);
        else if(Player1->get_isDenfense() == false && Player2->get_isDenfense() == true) concat(Player1->get_DEFAULT_ICON(), Player2->get_DEFENSE_ICON(), 6, 7);
        else if(Player1->get_isDenfense() == true && Player2->get_isDenfense() == true) concat(Player1->get_DEFENSE_ICON(), Player2->get_DEFENSE_ICON(), 6, 6);

        cout << "    p1: " << Player1->get_hp() << "       " << "p2: " << Player2->get_hp() << endl;
        cout << "1. Attack" << endl;
        cout << "2. Defense" << endl;
        int choice; cin >> choice;

        if(Play1){
            if(choice == ATTACK){
                int P2_hp_lost = 0;
                int P1_attack = 0;
                switch(p1_choice){
                    case MAGE:
                        if(Player2->get_isDenfense() == true){
                            P2_hp_lost = Player1->get_magicAttack() + ((Player1->get_attack() > Player2->get_defense()) ? Player1->get_attack() - Player2->get_defense() : 0);
                        }
                        else if(Player2->get_isDenfense() == false) P2_hp_lost = Player1->get_magicAttack() + Player1->get_attack();
                        break;
                    
                    case WARRIOR:
                        P1_attack =  (rand() % 100 < 100 * Player1->get_critRate()) ? Player1->get_attack() * 2 : Player1->get_attack();
                        if(Player2->get_isDenfense() == true){
                            if(P1_attack > Player2->get_defense()) P2_hp_lost = P1_attack - Player2->get_defense();
                        }
                        else if(Player2->get_isDenfense() == false)  P2_hp_lost = P1_attack;
                        break;
                    
                    case VAMPIRE:
                        P1_attack =  Player1->get_attack() + Player1->get_lifeSteal() * VAMPIRE_HP;
                        if(Player2->get_isDenfense() == true){
                            if(P1_attack > Player2->get_defense()) P2_hp_lost = P1_attack - Player2->get_defense();
                        }
                        else if(Player2->get_isDenfense() == false)  P2_hp_lost = P1_attack;
                        Player1->set_hp((Player1->get_lifeSteal() * VAMPIRE_HP + Player1->get_hp() > VAMPIRE_HP) ? VAMPIRE_HP : Player1->get_lifeSteal() * VAMPIRE_HP + Player1->get_hp());
                        break;
                    
                    default:
                        break;
                }


                if(Player2->get_isDenfense() == true){
                    concat(Player1->get_SHORT_ATTACK_ICON(), Player2->get_DEFENSE_ICON(), 10, 1);
                    Player2->set_isDenfense(false);

                }
                else{
                    concat(Player1->get_ATTACK_ICON(), Player2->get_DEFAULT_ICON(), 10, 0);
                }

                //update the Player 2 hp and check if the game end
                if(P2_hp_lost >= Player2->get_hp()){
                    cout << "Player 2 lose" << endl;
                    break;
                }
                else{
                    Player2->set_hp(Player2->get_hp() - P2_hp_lost);
                }
            }
            else if(choice == DEFENSE){
                Player1->set_isDenfense(true);
            }
        }
        else{
            if(choice == ATTACK){
                int P1_hp_lost = 0;
                int P2_attack = 0;
                switch(p2_choice){
                    case MAGE:
                        if(Player1->get_isDenfense() == true){
                            P1_hp_lost = Player2->get_magicAttack() + ((Player2->get_attack() > Player1->get_defense()) ? Player2->get_attack() - Player1->get_defense() : 0);
                        }
                        else if(Player1->get_isDenfense() == false) P1_hp_lost = Player2->get_magicAttack() + Player2->get_attack();
                        break;
                    
                    case WARRIOR:
                        P2_attack =  (rand() % 100 < 100 * Player2->get_critRate()) ? Player2->get_attack() * 2 : Player2->get_attack();
                        if(Player1->get_isDenfense() == true){
                            if(P2_attack > Player1->get_defense()) P1_hp_lost = P2_attack - Player1->get_defense();
                        }
                        else if(Player1->get_isDenfense() == false)  P1_hp_lost = P2_attack;
                        break;
                    
                    case VAMPIRE:
                        P2_attack =  Player2->get_attack() + Player2->get_lifeSteal() * VAMPIRE_HP;
                        if(Player1->get_isDenfense() == true){
                            if(P2_attack > Player1->get_defense()) P1_hp_lost = P2_attack - Player1->get_defense();
                        }
                        else if(Player1->get_isDenfense() == false)  P1_hp_lost = P2_attack;
                        Player2->set_hp((Player2->get_lifeSteal() * VAMPIRE_HP + Player2->get_hp() > VAMPIRE_HP) ? VAMPIRE_HP : Player2->get_lifeSteal() * VAMPIRE_HP + Player2->get_hp());
                        break;
                    
                    default:
                        break;
                }

                if(Player1->get_isDenfense() == true){
                    concat(Player1->get_DEFENSE_ICON(), Player2->get_SHORT_ATTACK_ICON(), 6, 1);
                    Player1->set_isDenfense(false);
                }
                else{
                    concat(Player1->get_DEFAULT_ICON(), Player2->get_ATTACK_ICON(), 6, 0);
                }
                //update the Player 1 hp and check if the game end
                if(P1_hp_lost >= Player1->get_hp()){
                    cout << "Player 1 lose" << endl;
                    break;
                }
                else{
                    Player1->set_hp(Player1->get_hp() - P1_hp_lost);
                }
            }
            else if(choice == DEFENSE){
                Player2->set_isDenfense(true);
            }
        }

        Play1 = !Play1;
        Round++;
    }

    return 0;
}