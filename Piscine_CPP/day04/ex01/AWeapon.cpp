#include "AWeapon.hpp"

AWeapon::~AWeapon(void) { return; }

AWeapon::AWeapon(void) : _name(""), _damage(0), _APCost(0) { return; }

AWeapon::AWeapon(std::string const & name, int apcost, int damage) : _name(name), _damage(damage), _APCost(apcost) { return; }

AWeapon::AWeapon(AWeapon const & rhs) { *this = rhs; return; }

std::string AWeapon::getName(void) const{ return this->_name; }

int AWeapon::getDamage(void) const{ return this->_damage; }

int AWeapon::getAPCost(void) const{ return this->_APCost; }

AWeapon & AWeapon::operator=(AWeapon const & rhs) {
    if(this != &rhs) {
        this->_name = rhs.getName();
        this->_damage = rhs.getDamage();
        this->_APCost = rhs.getAPCost();
    }
    return *this;
}