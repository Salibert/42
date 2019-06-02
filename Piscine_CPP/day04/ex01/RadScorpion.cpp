#include "RadScorpion.hpp"

RadScorpion::~RadScorpion(void) { return; }

RadScorpion::RadScorpion(void) : Enemy(80, "RadScorpion") {
    std::cout << "* click click click *" << std::endl;
    return;
}

RadScorpion::RadScorpion(int hp, std::string const & type) : Enemy(80, "RadScorpion") {
    (void)hp;
    (void)type;
    std::cout << "* click click click *" << std::endl;
    return;
}

void RadScorpion::deathDisplay(void) const {
    std::cout << "* SPROTCH *" << std::endl;
    return;
}

RadScorpion::RadScorpion(RadScorpion const & rhs) : Enemy(80, "RadScorpion") {
    (void)rhs;
    std::cout << "* click click click *" << std::endl;
    return;
}

std::string RadScorpion::getType(void) const { return this->_type;  }

int RadScorpion::getHitPoint(void) const { return this->_HitPoint;  }

RadScorpion & RadScorpion::operator=(RadScorpion const & rhs) {
    if (this != &rhs) {
        this->_HitPoint = rhs.getHitPoint();
        this->_type = rhs.getType();
    }
    return *this;
}