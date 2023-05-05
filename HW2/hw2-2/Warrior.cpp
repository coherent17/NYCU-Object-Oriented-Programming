#include "Warrior.h"

Warrior::Warrior():Role(WARRIOR_HP, WARRIOR_ATTACK, WARRIOR_DEFENSE, WARRIOR_SPEED, false), critRate(WARRIOR_CRIT_RATE){

}

Warrior::~Warrior(){

}

void Warrior::printInfo(ostream& out)const{
    cout << "Warrior" << endl;
    Role::printInfo(out);
    out << "Crit Rate: " << critRate;
}