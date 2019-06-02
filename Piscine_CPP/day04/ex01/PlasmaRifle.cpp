#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle(void) : AWeapon("Plasma Rifle", 5, 21) {return ;}

PlasmaRifle::PlasmaRifle(std::string & name, int apcost, int damage) : AWeapon("Plasma Rifle", 5, 21) {
    (void) name;
    (void) apcost;
    (void) damage;
    return ;
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const & rhs) : AWeapon(rhs) {
    (void) rhs;
    return;
}

PlasmaRifle::~PlasmaRifle(void) {return ;}

void PlasmaRifle::attack(void) const {
    std::cout << "* piouuu piouuu piouuu *" << std::endl;
    return;
}

PlasmaRifle & PlasmaRifle::operator=(PlasmaRifle const & rhs) {
    if(this != &rhs) {
        this->_name = rhs.getName();
        this->_damage = rhs.getDamage();
        this->_APCost = rhs.getAPCost();
    }
    return *this;
}