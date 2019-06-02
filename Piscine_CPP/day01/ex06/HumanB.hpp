#ifndef HUMANB_H
# define HUMANB_H

# include "Weapon.hpp"

class HumanB {
    Weapon* _weapon;
    std::string const _name;

    public:
        HumanB(std::string name);
        ~HumanB(void);
        void setWeapon(Weapon& weapon);
        void attack(void) const;
};
#endif