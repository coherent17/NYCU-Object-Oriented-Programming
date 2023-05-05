#ifndef _WARRIOR_H_
#define _WARRIOR_H_

#define WARRIOR_HP 120
#define WARRIOR_ATTACK 30
#define WARRIOR_DEFENSE 20
#define WARRIOR_SPEED 10
#define WARRIOR_CRIT_RATE 0.2

#include "Role.h"

class Warrior: public Role{
    private:
        float critRate;

    public:
        Warrior();
        ~Warrior();
        void printInfo(ostream& out)const override;
};

#endif