#include <iostream>

#include "Animal.h"

Animal::Animal():
	type("Unknown animal")
{
	std::cerr << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& other) {
	*this = other;
	std::cerr << "Animal copy constructor called" << std::endl;
}

Animal::Animal(const std::string& type):
	type(type)
{
	std::cerr << "Animal std::string constructor called" << std::endl;
}

Animal::~Animal() {
	std::cerr << "Animal destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
	if (this == &other)
		return *this;
	this->type = other.type;
	return *this;
}

const std::string&	Animal::getType() const {
	return this->type;
}

void	Animal::makeSound() const {
	std::cout << "An animal made a sound" << std::endl;
}
