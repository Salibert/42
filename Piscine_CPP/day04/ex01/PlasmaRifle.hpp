#ifndef PLASMARIFLE_H
# define PLASMARIFLE_H
# include "AWeapon.hpp"

class PlasmaRifle : public AWeapon {
    private:
        /* forbidden constructor*/
        PlasmaRifle(std::string & name, int apcost, int damage);
        PlasmaRifle(PlasmaRifle const & rsh);
    public:
        PlasmaRifle(void);
        virtual ~PlasmaRifle(void);
        virtual void attack(void) const;

        PlasmaRifle & operator=(PlasmaRifle const & rhs);
};
#endif