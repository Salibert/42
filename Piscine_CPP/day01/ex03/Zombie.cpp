#include "Zombie.hpp"

Zombie::Zombie(void) {
    std::string s;
    int len = Zombie::_random.length() - 1;
    for (int i = 0; i < 10; ++i) {
        s += Zombie::_random[rand() % len];
    }
    std::cout << "A new zombie is coming" << std::endl;
    this->_name = s;
    this->_type = 0;
    this->health = 100;
    return ;
}

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

std::string Zombie::_random = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";