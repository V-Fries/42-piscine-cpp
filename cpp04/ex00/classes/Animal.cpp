#include <iostream>

#include "Animal.h"

Animal::Animal():
	_type("Unknown animal")
{
	std::cerr << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& other) {
	*this = other;
	std::cerr << "Animal copy constructor called" << std::endl;
}

Animal::Animal(const std::string& type):
	_type(type)
{
	std::cerr << "Animal std::string constructor called" << std::endl;
}

Animal::~Animal() {
	std::cerr << "Animal destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
	if (this == &other)
		return *this;
	this->_type = other._type;
	return *this;
}

const std::string&	Animal::getType() const {
	return this->_type;
}

void	Animal::makeSound() const {
	std::cout << "An animal made a sound" << std::endl;
}
