#include <iostream>

#include "Cat.h"
#include "Brain.h"

Cat::Cat():
	AAnimal("Cat"),
	_brain(new Brain)
{
	std::cerr << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other):
	_brain(NULL)
{
	*this = other;
	std::cerr << "Cat copy constructor called" << std::endl;
}

Cat::~Cat() {
	delete this->_brain;
	std::cerr << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	if (this == &other)
		return *this;

	delete this->_brain;
	this->_brain = new Brain(*other._brain);
	this->type = other.type;
	return *this;
}

void	Cat::makeSound() const {
	std::cout << "Meow" << std::endl;
}

void	Cat::addIdea(const std::string& idea) {
	this->_brain->addIdea(idea);
}

const std::string&	Cat::getIdea(const IdeasSizeUInt index) const {
	return this->_brain->getIdea(index);
}
