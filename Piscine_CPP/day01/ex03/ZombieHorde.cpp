#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int n) : _len_horde(n) {    
    this->_horde = new Zombie[n];
    std::cout << "A horde of " << n << " zombie is born" << std::endl;
    return;
}

ZombieHorde::~ZombieHorde(void) {
    delete [] this->_horde;
    std::cout << "A horde is died" << std::endl;
    return;
}

void ZombieHorde::announce(void) {
    for (int i=0;  i < this->_len_horde; i++) {
        this->_horde[i].announce();
    }
    return;
}