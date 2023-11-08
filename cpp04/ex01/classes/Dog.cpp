#include <iostream>

#include "Dog.h"
#include "Brain.h"

Dog::Dog():
	Animal("Dog"),
	_brain(new Brain)
{
	std::cerr << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other):
	Animal(other),
	_brain(NULL)
{
	*this = other;
	std::cerr << "Dog copy constructor called" << std::endl;
}

Dog::~Dog() {
	delete this->_brain;
	std::cerr << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	if (this == &other)
		return *this;

	delete this->_brain;
	this->_brain = new Brain(*other._brain);
	this->_type = other._type;
	return *this;
}

void	Dog::makeSound() const {
	std::cout << "Woof" << std::endl;
}

void				Dog::addIdea(const std::string& idea) {
	this->_brain->addIdea(idea);
}

const std::string&	Dog::getIdea(const IdeasSizeUInt index) const {
	return this->_brain->getIdea(index);
}
