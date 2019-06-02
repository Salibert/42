#include "PowerFist.hpp"

PowerFist::PowerFist(void) : AWeapon("Power Fist", 8, 50) {return ;}

PowerFist::PowerFist(std::string & name, int apcost, int damage) : AWeapon("Power Fist", 8, 50) {
    (void)name;
    (void)apcost;
    (void)damage;
    return ;
}

PowerFist::PowerFist(PowerFist const & rhs) : AWeapon(rhs) {
    (void)rhs;
    return;
}

PowerFist::~PowerFist(void) {return ;}

void PowerFist::attack(void) const {
    std::cout << " * pschhh... SBAM! *" << std::endl;
    return;
}

PowerFist & PowerFist::operator=(PowerFist const & rhs) {
    if(this != &rhs) {
        this->_name = rhs.getName();
        this->_damage = rhs.getDamage();
        this->_APCost = rhs.getAPCost();
    }
    return *this;
}