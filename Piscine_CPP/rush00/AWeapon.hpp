#ifndef AWEAPON_HPP
# define AWEAPON_HPP

#include <iostream>

class AWeapon {

    protected:

        std::string _Name;
        int _Damage;

        AWeapon();

    public:

        AWeapon(std::string const & name, int damage);
        AWeapon(AWeapon const &weapon);
        virtual ~AWeapon();
        AWeapon	&operator=(AWeapon const & right);

        std::string getName() const;
        int getDamage() const;

        virtual void attack() const = 0;

};

#endif