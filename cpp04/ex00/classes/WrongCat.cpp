#include <iostream>

#include "WrongCat.h"

WrongCat::WrongCat():
	WrongAnimal("Cat")
{
	std::cerr << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other):
	WrongAnimal(other) {
	*this = other;
	std::cerr << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat() {
	std::cerr << "WrongCat destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	if (this == &other)
		return *this;
	this->_type = other._type;
	return *this;
}

void	WrongCat::makeSound() const {
	std::cout << "Meow" << std::endl;
}
