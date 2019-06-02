#include "Fixed.class.hpp"

Fixed::Fixed(void) : _fixed(0) {
    std::cout << "Default constructor called" << std::endl;
    return;
}

Fixed::Fixed(int const fixed) : _fixed(fixed * (1<< Fixed::_fixed_8bits)) {
    std::cout << "Int constructor called" << std::endl;
    return;
}

Fixed::Fixed(float const fixed) : _fixed(roundf(fixed * (1 << Fixed::_fixed_8bits))) {
    std::cout << "Float constructor called" << std::endl;
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
        this->setRawBits(rhs.getRawBits());
    return *this;
}

float Fixed::toFloat(void) const {
    return (float)(this->_fixed) / (1 << Fixed::_fixed_8bits);
}

int Fixed::toInt(void) const {
    return this->_fixed / (1 << Fixed::_fixed_8bits);
}

int Fixed::getRawBits(void) const {
    return this->_fixed;
}

void Fixed::setRawBits(int const raw) {
    this->_fixed = raw;
    return;
}

std::ostream & operator<<(std::ostream & o, Fixed const & wahiba) {
    o << wahiba.toFloat();
    return o;
}