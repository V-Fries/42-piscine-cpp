#include <iostream>

#include "AAnimal.h"

AAnimal::AAnimal():
	_type("Unknown animal")
{
	std::cerr << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) {
	*this = other;
	std::cerr << "AAnimal copy constructor called" << std::endl;
}

AAnimal::AAnimal(const std::string& type):
	_type(type)
{
	std::cerr << "AAnimal std::string constructor called" << std::endl;
}

AAnimal::~AAnimal() {
	std::cerr << "AAnimal destructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
	if (this == &other)
		return *this;
	this->_type = other._type;
	return *this;
}

const std::string&	AAnimal::getType() const {
	return this->_type;
}

void	AAnimal::makeSound() const {
	std::cout << "An animal made a sound" << std::endl;
}
