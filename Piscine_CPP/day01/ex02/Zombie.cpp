#include "Zombie.hpp"

Zombie::Zombie(std::string name, int type) : _name(name), _type(type) {
    this->health = type * 10;
    std::cout << "A new zombie is coming" << std::endl;
    return ;
}

Zombie::~Zombie(void) {
    std::cout << this->_name << " is died " << std::endl;
    return ;
}

void Zombie::announce(void) {
    std::cout << "I AM " << this->_name << "(" << this->_type << ")" << " Braiiiiiiinnnssss..." << std::endl;
 }