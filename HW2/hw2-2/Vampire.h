#ifndef _VAMPIRE_H_
#define _VAMPIRE_H_

#define VAMPIRE_HP 80
#define VAMPIRE_ATTACK 25
#define VAMPIRE_DEFENSE 15
#define VAMPIRE_SPEED 7
#define VAMPIRE_LIFESTEAL 0.1

#include "Role.h"

class Vampire: public Role{
    private:
        float lifeSteal;
        
    public:
        Vampire();
        ~Vampire();
        void printInfo(ostream& out)const override;
};

#endif