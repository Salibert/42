#include "Squad.hpp"

Squad::Squad(void) {
    std::cout << "* teleports from space *" << std::endl;
    return;
}

Squad::Squad(const Squad & src) {
    (void)src;
    return;
}

Squad::~Squad(void) {
    std::cout << "I’ll be back ..." << std::endl;
    return;
}

Squad & Squad::operator=(const Squad & rhs) {
    if (this != &rhs) {
        this->_count = rhs.getCount();
        this->_company = rhs.getCompany();
    }
    return *this;
}