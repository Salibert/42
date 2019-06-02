#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {
    return;
}

Weapon::~Weapon(void) {
    return;
}

void Weapon::setType(std::string type) {
    this->_type = type;
    return;
}

std::string& Weapon::getType(void) {
    return this->_type;
}