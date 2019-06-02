#ifndef PLAYERWEAPON_H
# define PLAYERWEAPON_H
# include "AWeapon.hpp"

class PlayerWeapon : public AWeapon {
    private:
        /* forbidden constructor*/
        PlayerWeapon(std::string & name, int damage);
        PlayerWeapon(PlayerWeapon const & rsh);
    public:
        PlayerWeapon(void);
        virtual ~PlayerWeapon(void);
        virtual void attack(void) const;

        PlayerWeapon & operator=(PlayerWeapon const & rhs);
};
#endif