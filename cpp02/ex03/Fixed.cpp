#include <iostream>
#include <cmath>

#include "Fixed.h"


Fixed::Fixed():
	_value(0) {
}

Fixed::Fixed(const Fixed& other) {
	*this = other;
}

Fixed::Fixed(const int nb):
	_value(nb << this->_fractional_bits) {
}

Fixed::Fixed(const float nb):
	_value(roundf(nb * (1 << this->_fractional_bits))) {
}


Fixed::~Fixed() {
}


Fixed&	Fixed::operator=(const Fixed& other) {
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


Fixed&			Fixed::min(Fixed& a, Fixed& b) {
	return a < b ? a : b;
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) {
	return a < b ? a : b;
}

Fixed&			Fixed::max(Fixed& a, Fixed& b) {
	return a > b ? a : b;
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) {
	return a > b ? a : b;
}


bool	Fixed::operator>(const Fixed& right) const {
	return this->_value > right._value;
}

bool	Fixed::operator<(const Fixed& right) const {
	return this->_value < right._value;
}

bool	Fixed::operator>=(const Fixed& right) const {
	return this->_value >= right._value;
}

bool	Fixed::operator<=(const Fixed& right) const {
	return this->_value <= right._value;
}

bool	Fixed::operator==(const Fixed& right) const {
	return this->_value == right._value;
}

bool	Fixed::operator!=(const Fixed& right) const {
	return this->_value != right._value;
}


Fixed	Fixed::operator+(const Fixed& right) const {
	return Fixed(this->toFloat() + right.toFloat());
}

Fixed	Fixed::operator-(const Fixed& right) const {
	return Fixed(this->toFloat() - right.toFloat());
}

Fixed	Fixed::operator*(const Fixed& right) const {
	return Fixed(this->toFloat() * right.toFloat());
}

Fixed	Fixed::operator/(const Fixed& right) const {
	return Fixed(this->toFloat() / right.toFloat());
}


Fixed&	Fixed::operator++() {
	this->_value += 1;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed	tmp(*this);

	this->operator++();
	return tmp;
}

Fixed&	Fixed::operator--() {
	this->_value -= 1;
	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed	tmp(*this);

	this->operator--();
	return tmp;
}

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}
