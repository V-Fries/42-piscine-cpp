#include <iostream>

#include "Brain.h"

Brain::Brain():
	_ideasIndex(0) {
	std::cerr << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& other):
	_ideasIndex(0)
{
	*this = other;
	std::cerr << "Brain copy constructor called" << std::endl;
}

Brain::~Brain() {
	std::cerr << "Brain destructor called" << std::endl;
}

Brain&	Brain::operator=(const Brain& other) {
	if (&other == this)
		return *this;
		
	for (IdeasSizeUInt i = 0; i < Brain::ideasSize; i++)
		this->_ideas[i] = other.getIdea(i);
	return *this;
}

void	Brain::addIdea(const std::string& idea) {
	if (this->_ideasIndex >= Brain::ideasSize)
		throw std::out_of_range("Brain::addIdea() ideas array is full");

	this->_ideas[this->_ideasIndex] = idea;
	this->_ideasIndex++;
}

const std::string&	Brain::getIdea(const IdeasSizeUInt index) const {
	if (index >= this->ideasSize)
		throw std::out_of_range("Brain::getIdea() index is out of bounds");
	if (index >= this->_ideasIndex)
		throw std::out_of_range("Brain::getIdea() this->ideas[index] is uninitialized");

	return this->_ideas[index];
}
