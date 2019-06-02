#include "Fixed.class.hpp"

/* Constructor */

Fixed::Fixed(void) : _fixed(0) {
    return;
}

Fixed::Fixed(int const fixed) : _fixed(fixed * (1 << Fixed::_fixed_8bits)) {
    return;
}

Fixed::Fixed(float const fixed) : _fixed(roundf(fixed * (1 << Fixed::_fixed_8bits))) {
    return;
}

Fixed::Fixed(Fixed const & src) {
    *this = src;
    return;
}

/* Destructor */

Fixed::~Fixed(void) {    
    return;
}

/* Operator */

Fixed & Fixed::operator=(Fixed const & rhs) {
    if (this != &rhs)
        this->_fixed = rhs.getRawBits();
    return *this;
}

Fixed Fixed::operator+(Fixed const & rhs) const {
    return Fixed(float(this->toFloat() + rhs.toFloat()));
}

Fixed & Fixed::operator++(void) {
    this->setRawBits(this->getRawBits() + 1);
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp = Fixed(*this);
    this->setRawBits(this->getRawBits() + 1);
    return tmp;
}

Fixed & Fixed::operator--(void) {
    this->setRawBits(this->getRawBits() - 1);
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp = Fixed(*this);
    this->setRawBits(this->getRawBits() - 1);
    return tmp;
}

Fixed Fixed::operator-(Fixed const & rhs) const {
    return Fixed(float(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(Fixed const & rhs) const {
    return Fixed(float(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(Fixed const & rhs) const {
    return Fixed(float(this->toFloat() / rhs.toFloat()));
}

bool Fixed::operator>(Fixed const & rhs) const {
    return (this->getRawBits() > rhs.getRawBits());
}

bool Fixed::operator<(Fixed const & rhs) const {
    return (this->getRawBits() < rhs.getRawBits());
}

bool Fixed::operator<=(Fixed const & rhs) const {
    return (this->getRawBits() <= rhs.getRawBits());
}

bool Fixed::operator>=(Fixed const & rhs) const {
    return (this->getRawBits() >= rhs.getRawBits());
}

bool Fixed::operator!=(Fixed const & rhs) const {
    return (this->getRawBits() != rhs.getRawBits());
}

bool Fixed::operator==(Fixed const & rhs) const {
    return (this->getRawBits() == rhs.getRawBits());
}

/* Member functions*/

float Fixed::toFloat(void) const {
    return (float)(this->_fixed) / (1 << Fixed::_fixed_8bits);
}

int Fixed::toInt(void) const {
    return (int)(this->_fixed / (1 << Fixed::_fixed_8bits));
}

int Fixed::getRawBits(void) const {
    return this->_fixed;
}

void Fixed::setRawBits(int const raw) {
    this->_fixed = raw;
    return;
}

Fixed const & Fixed::max(Fixed const & a, Fixed const & b) {
    return a > b ? a : b;
}

Fixed const & Fixed::min(Fixed const & a, Fixed const & b) {
    return a < b ? a : b;
}

Fixed & Fixed::max(Fixed & a, Fixed & b) {
    return a > b ? a : b;
}

Fixed & Fixed::min(Fixed & a, Fixed & b) {
    return a < b ? a : b;
}

std::ostream & operator<<(std::ostream & o, Fixed const & wahiba) {
    o << wahiba.toFloat();
    return o;
}