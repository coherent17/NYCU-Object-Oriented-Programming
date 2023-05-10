#ifndef _VAMPIRE_H_
#define _VAMPIRE_H_

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
        int maxHP;
        string DEFAULT_ICON;
        string ATTACK_ICON;
        string DEFENSE_ICON;
        string SHORT_ATTACK_ICON;
        
    public:
        Vampire(int playerID, int hp, int attack, int defense, int speed, float lifeSteal);
        ~Vampire();
        float get_lifeSteal()override;
        int get_maxHP()override;
        string get_DEFAULT_ICON()override;
        string get_ATTACK_ICON()override;
        string get_DEFENSE_ICON()override;
        string get_SHORT_ATTACK_ICON()override;
};

#endif