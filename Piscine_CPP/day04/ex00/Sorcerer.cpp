#include "Sorcerer.hpp"

Sorcerer::Sorcerer(void) { return; }

Sorcerer::~Sorcerer(void) {
    std::cout  << this->get_name() << ", " << this->get_title() << ", is dead. Consequences will never be the same !" << std::endl;
    return;
}

Sorcerer::Sorcerer(std::string const & name, std::string const & title) : _name(name), _title(title) {
    std::cout  << name << ", " << title << ", is born !" << std::endl;
    return;
}
Sorcerer::Sorcerer(Sorcerer const & rhs) {
    *this = rhs;
    return;
}

void Sorcerer::set_name(std::string const & name) {
    this->_name = name;
    return;
}

void Sorcerer::set_title(std::string const & title) {
    this->_title = title;
    return;
}

std::string Sorcerer::get_name(void) const {
    return this->_name;
}

std::string Sorcerer::get_title(void) const {
    return this->_title;
}

void Sorcerer::polymorph(Victim const & v) const {
    v.getPolymorphed();
    return ;
}

Sorcerer & Sorcerer::operator=(Sorcerer const & rhs) {
    if (this != &rhs)
        this->set_name(rhs.get_name());
    return *this;
}

std::ostream & operator<<(std::ostream & o, Sorcerer const & rhs) {
    o << "I'm " << rhs.get_name() << ", " << rhs.get_title() << " and I like otters !" << std::endl;
    return o;
}