#include <iostream>

#include "Dog.h"

Dog::Dog():
	Animal("Dog")
{
	std::cerr << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other):
	Animal(other) {
	*this = other;
	std::cerr << "Dog copy constructor called" << std::endl;
}

Dog::~Dog() {
	std::cerr << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	if (this == &other)
		return *this;
	this->_type = other._type;
	return *this;
}

void	Dog::makeSound() const {
	std::cout << "Woof" << std::endl;
}
