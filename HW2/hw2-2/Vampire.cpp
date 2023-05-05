#include "Vampire.h"

Vampire::Vampire():Role(VAMPIRE_HP, VAMPIRE_ATTACK, VAMPIRE_DEFENSE, VAMPIRE_SPEED, false), lifeSteal(VAMPIRE_LIFESTEAL){

}

Vampire::~Vampire(){

}

void Vampire::printInfo(ostream& out)const{
    cout << "Vampire" << endl;
    Role::printInfo(out);
    out << "Life Steal: " << lifeSteal;
}