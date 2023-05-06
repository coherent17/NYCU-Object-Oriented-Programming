#ifndef _VAMPIRE_H_
#define _VAMPIRE_H_

#define VAMPIRE_HP 80
#define VAMPIRE_ATTACK 25
#define VAMPIRE_DEFENSE 15
#define VAMPIRE_SPEED 7
#define VAMPIRE_LIFESTEAL 0.1

#define VAMPIRE_DEFAULT_ICON1\
    "  _  "\
    " (v) "\
    "/-+-/"\
    "  |  "\
    " / \\ ";

#define VAMPIRE_DEFAULT_ICON2\
    "  _  "\
    " (v) "\
    "\\-+-\\"\
    "  |  "\
    " / \\ ";

#define VAMPIRE_ATTACK_ICON1\
    "  _      "\
    " (v)     "\
    "/-+-----o"\
    "  |      "\
    " / \\     ";

#define VAMPIRE_ATTACK_ICON2\
    "      _  "\
    "     (v) "\
    "o-----+-\\"\
    "      |  "\
    "     / \\ ";

#define VAMPIRE_DEFENSE_ICON1\
    "  _   "\
    " (v)  "\
    "/-+--)"\
    "  |   "\
    " / \\  ";

#define VAMPIRE_DEFENSE_ICON2\
    "   _  "\
    "  (v) "\
    "(--+-\\"\
    "   |  "\
    "  / \\ ";

#define VAMPIRE_SHORT_ATTACK_ICON1\
    "  _    "\
    " (v)   "\
    "/-+---o"\
    "  |    "\
    " / \\   ";

#define VAMPIRE_SHORT_ATTACK_ICON2\
    "    _  "\
    "   (v) "\
    "o---+-\\"\
    "    |  "\
    "   / \\ ";

#include "Role.h"

class Vampire: public Role{
    private:
        float lifeSteal;
        string DEFAULT_ICON;
        string ATTACK_ICON;
        string DEFENSE_ICON;
        string SHORT_ATTACK_ICON;
        
    public:
        Vampire(int);
        ~Vampire();
        void printInfo(ostream& out)const override;
        float get_lifeSteal()override;
        string get_DEFAULT_ICON()override;
        string get_ATTACK_ICON()override;
        string get_DEFENSE_ICON()override;
        string get_SHORT_ATTACK_ICON()override;
};

#endif