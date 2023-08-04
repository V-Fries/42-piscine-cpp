#include <iostream>
#include <cmath>

#include "Fixed.h"

Fixed::Fixed():
	_value(0) {
	std::cerr << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	std::cerr << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int nb):
	_value(nb << this->_fractional_bits) {
	std::cerr << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float nb):
	_value(roundf(nb * (1 << this->_fractional_bits))) {
	std::cerr << "Float constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cerr << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& other) {
	std::cerr << "Copy assignment operator called" << std::endl;
	if (&other == this)
		return *this;
	this->setRawBits(other.getRawBits());
	return *this;
}

int		Fixed::getRawBits() const {
	return this->_value;
}

void	Fixed::setRawBits(const int raw) {
	this->_value = raw;
}

float	Fixed::toFloat(void) const {
	return (float)this->_value / (1 << this->_fractional_bits);
}

int		Fixed::toInt(void) const {
	return this->_value >> this->_fractional_bits;
}

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed_point)
{
	os << fixed_point.toFloat();
	return os;
}
