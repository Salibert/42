#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine(void) {
    std::cout << "Tactical Marine ready for battle" << std::endl;
    return;
}

TacticalMarine::TacticalMarine(TacticalMarine const & src) {
    (void)src;
    return;
}

TacticalMarine::~TacticalMarine(void) {
    std::cout << "Aaargh ..." << std::endl;
    return;
}

TacticalMarine* TacticalMarine::clone(void) const {
    return new TacticalMarine( *this );
}

void TacticalMarine::battleCry(void) const {
    std::cout << "For the holy PLOT !" << std::endl;
    return;
}

void TacticalMarine::rangedAttack(void) const {
    std::cout << "* does nothing *" << std::endl;
    return;
}

void TacticalMarine::meleeAttack(void) const {
    std::cout << "* attacks with chainfists *" << std::endl;
    return;
}

TacticalMarine & TacticalMarine::operator=(const TacticalMarine & rhs) {
    (void)rhs;
    return *this;
}