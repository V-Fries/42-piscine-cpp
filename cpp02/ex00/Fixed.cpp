#include <iostream>

#include "Fixed.h"

Fixed::Fixed():
	_value(0) {
	std::cerr << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed& other):
	_value(other._value) {
	std::cerr << "Copy constructor called" << std::endl;
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
	std::cerr << "getRawBits member function called" << std::endl;
	return this->_value;
}

void	Fixed::setRawBits(const int raw) {
	std::cerr << "setRawBits member function called" << std::endl;
	this->_value = raw;
}
