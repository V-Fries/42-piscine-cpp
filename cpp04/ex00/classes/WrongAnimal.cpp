#include <iostream>

#include "WrongAnimal.h"

WrongAnimal::WrongAnimal():
	type("Unknown animal")
{
	std::cerr << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	*this = other;
	std::cerr << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type):
	type(type)
{
	std::cerr << "WrongAnimal std::string constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cerr << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	if (this == &other)
		return *this;
	this->type = other.type;
	return *this;
}

const std::string&	WrongAnimal::getType() const {
	return this->type;
}

void	WrongAnimal::makeSound() const {
	std::cout << "An animal made a sound" << std::endl;
}
