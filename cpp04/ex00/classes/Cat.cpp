#include <iostream>

#include "Cat.h"

Cat::Cat():
	Animal("Cat")
{
	std::cerr << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other):
	Animal(other) {
	*this = other;
	std::cerr << "Cat copy constructor called" << std::endl;
}

Cat::~Cat() {
	std::cerr << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	if (this == &other)
		return *this;
	this->_type = other._type;
	return *this;
}

void	Cat::makeSound() const {
	std::cout << "Meow" << std::endl;
}
