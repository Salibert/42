#include "SuperMutant.hpp"

SuperMutant::~SuperMutant(void) {
    std::cout << "Aaargh ..." << std::endl;
    return;
}

SuperMutant::SuperMutant(void) : Enemy(170, "Super Mutant") {
    std::cout << "Gaaah. Me want smash heads !" << std::endl;
    return;
}

SuperMutant::SuperMutant(int hp, std::string const & type) : Enemy(170, "Super Mutant") {
    (void)hp;
    (void)type;
    std::cout << "Gaaah. Me want smash heads !" << std::endl;
    return;
}

void SuperMutant::deathDisplay(void) const {
    std::cout << "Aaargh ..." << std::endl;
    return;
}

SuperMutant::SuperMutant(SuperMutant const & rhs) : Enemy(170, "Super Mutant") {
    (void)rhs;
    std::cout << "Gaaah. Me want smash heads !" << std::endl;
    return;
}

std::string SuperMutant::getType(void) const { return this->_type;  }

int SuperMutant::getHitPoint(void) const { return this->_HitPoint;  }

void SuperMutant::takeDamage(int amount) {
    if (this->getHitPoint() && (this->getHitPoint() - amount) <= 0)
        this->deathDisplay();
    if ( amount < 3 )
        return;
    amount -= 3;
    if (amount <= this->getHitPoint())
        this->_HitPoint -= amount;
    else
        this->_HitPoint = 0;
    return;
}

SuperMutant & SuperMutant::operator=(SuperMutant const & rhs) {
    if (this != &rhs) {
        this->_HitPoint = rhs.getHitPoint();
        this->_type = rhs.getType();
    }
    return *this ;
}
