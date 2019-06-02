#ifndef CHARACTER_H
# define CHARACTER_H

# include "Enemy.hpp"
# include "AWeapon.hpp"
# include <iostream>

class Character {
    private:
        std::string _name;
        int _AP;
        AWeapon* _weapon;
        /* forbidden constructor */
        Character(void);
    public:
        Character(std::string const & name);
        Character(Character const & rhs);
        ~Character(void);
        std::string getName(void) const;
        int getAP(void) const;
        AWeapon* getWeapon(void) const;
        void setAP(int amount);
        void recoverAP(void);
        void equip(AWeapon* weapon);
        void attack(Enemy* enemy);

        Character & operator=(Character const & rhs);
};
    std::ostream & operator<<(std::ostream & o, Character const & wahiba);
#endif