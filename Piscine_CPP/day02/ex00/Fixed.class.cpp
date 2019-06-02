#include "Fixed.class.hpp"

Fixed::Fixed(void) : _fixed(0) {
    std::cout << "Default constructor called" << std::endl;
    return;
}

Fixed::Fixed(Fixed const & src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
    return;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
    return;
}

Fixed & Fixed::operator=(Fixed const & rhs) {
    std::cout << "Assignation operator called" << std::endl;
    if (this != &rhs)
        this->_fixed = rhs.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixed;
}

void Fixed::setRawBits(int const raw) {
    this->_fixed = raw;
    return;
}