#include "AlienWeapon.hpp"

AlienWeapon::AlienWeapon(void) : AWeapon("Plasma Rifle", 1) {return ;}

AlienWeapon::AlienWeapon(std::string & name, int damage) : AWeapon("Plasma Rifle", 1) {
    (void) name;
    (void) damage;
    return ;
}

AlienWeapon::AlienWeapon(AlienWeapon const & rhs) : AWeapon(rhs) {
    (void) rhs;
    return;
}

AlienWeapon::~AlienWeapon(void) {
    return ;
}

void AlienWeapon::attack(void) const { return; }

AlienWeapon & AlienWeapon::operator=(AlienWeapon const & rhs) {
    if(this != &rhs) {
        this->_Name = rhs.getName();
        this->_Damage = rhs.getDamage();
    }
    return *this;
}