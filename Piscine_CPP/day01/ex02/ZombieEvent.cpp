#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(int type) : _type(type) {
    std::cout << "The zombies arrive" << std::endl;
    return ;
}

ZombieEvent::~ZombieEvent(void) {
    std::cout << "Good night" << std::endl;
    return ;
}

Zombie* ZombieEvent::newZombie(std::string name) {
    Zombie* new_zombie = new Zombie(name, this->_type);
    new_zombie->announce();
    return new_zombie;
}

void ZombieEvent::setZombieType(int type) {
    this->_type = type;
}

void ZombieEvent::randomChump(void) {
    std::string s;
    int len = ZombieEvent::_random.length() - 1;
    for (int i = 0; i < 10; ++i) {
        s += ZombieEvent::_random[rand() % len];
    }
    Zombie make_to_die = Zombie(s, this->_type);
    make_to_die.announce();
}

std::string ZombieEvent::_random = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
