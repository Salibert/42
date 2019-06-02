#include "PlayerWeapon.hpp"

PlayerWeapon::PlayerWeapon(void) : AWeapon("Plasma Rifle", 100) {return ;}

PlayerWeapon::PlayerWeapon(std::string & name, int damage) : AWeapon("Plasma Rifle", 100) {
    (void) name;
    (void) damage;
    return ;
}

PlayerWeapon::PlayerWeapon(PlayerWeapon const & rhs) : AWeapon(rhs) {
    (void) rhs;
    return;
}

PlayerWeapon::~PlayerWeapon(void) {return ;}

void PlayerWeapon::attack(void) const { return; }

PlayerWeapon & PlayerWeapon::operator=(PlayerWeapon const & rhs) {
    if(this != &rhs) {
        this->_Name = rhs.getName();
        this->_Damage = rhs.getDamage();
    }
    return *this;
}