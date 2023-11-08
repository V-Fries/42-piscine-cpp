#include <iostream>

#include "WrongAnimal.h"

WrongAnimal::WrongAnimal():
	_type("Unknown animal")
{
	std::cerr << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	*this = other;
	std::cerr << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type):
	_type(type)
{
	std::cerr << "WrongAnimal std::string constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cerr << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	if (this == &other)
		return *this;
	this->_type = other._type;
	return *this;
}

const std::string&	WrongAnimal::getType() const {
	return this->_type;
}

void	WrongAnimal::makeSound() const {
	std::cout << "An animal made a sound" << std::endl;
}
