#include "Peon.hpp"

Peon::Peon(void) { return; }

Peon::Peon(std::string const & name) : Victim(name) {
    std::cout << "Zog zog." << std::endl;
    return;
}

Peon::Peon(Peon const & rhs) : Victim(rhs) {
    std::cout << "Zog zog." << std::endl;
    return;
}

Peon::~Peon(void) {
    std::cout << "Bleuark..." << std::endl;
    return;
}

void Peon::getPolymorphed(void) const {
    std::cout << this->get_name() << " has been turned into a pink pony !" << std::endl;
    return ;
}

Peon & Peon::operator=(Peon const & rhs) {
    if (this != &rhs)
        this->set_name(rhs.get_name());
    return *this;
}