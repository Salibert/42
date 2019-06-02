#ifndef POWERFIST_H
# define POWERFIST_H
# include "AWeapon.hpp"

class PowerFist : public AWeapon {
    private:
        /* forbidden constructor*/
        PowerFist(std::string & name, int apcost, int damage);
        PowerFist(PowerFist const & rsh);
    public:
        PowerFist(void);
        virtual ~PowerFist(void);
        virtual void attack(void) const;

        PowerFist & operator=(PowerFist const & rhs);
};
#endif