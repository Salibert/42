#ifndef ALIENWEAPON_H
# define ALIENWEAPON_H

# include "AWeapon.hpp"

class AlienWeapon : public AWeapon {
    private:
        /* forbidden constructor*/
        AlienWeapon(std::string & name, int damage);
        AlienWeapon(AlienWeapon const & rsh);
    public:
        AlienWeapon(void);
        virtual ~AlienWeapon(void);
        virtual void attack(void) const;

        AlienWeapon & operator=(AlienWeapon const & rhs);
};
#endif