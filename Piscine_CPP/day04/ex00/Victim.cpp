#include "Victim.hpp"

Victim::Victim(void) { return; }

Victim::~Victim(void) {
    std::cout << "Victim " << this->get_name() << " just died for no apparent reason !" << std::endl;
    return;
}

Victim::Victim(std::string const & name) : _name(name) {
    std::cout << "Some random victim called " << name <<" just popped !" << std::endl;
    return;
}
Victim::Victim(Victim const & rhs) {
    *this = rhs;
    return;
}

void Victim::set_name(std::string const & name) {
    this->_name = name;
    return;
}

std::string Victim::get_name(void) const {
    return this->_name;
}

void Victim::getPolymorphed(void) const {
    std::cout << this->get_name() << " has been turned into a cute little sheep !" << std::endl;
    return ;
}

Victim & Victim::operator=(Victim const & rhs) {
    if (this != &rhs)
        this->set_name(rhs.get_name());
    return *this;
}

std::ostream & operator<<(std::ostream & o, Victim const & rhs) {
    o << "I'm " << rhs.get_name() << " and I like otters !" << std::endl;
    return o;
}