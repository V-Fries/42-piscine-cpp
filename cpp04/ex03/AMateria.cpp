#include "AMateria.hpp"
#include "ICharacter.hpp"

#include <iostream>

AMateria::AMateria(): _type("Unknown") {}

AMateria::AMateria(const AMateria& other): _type(other._type) {}

AMateria::AMateria(const std::string& type): _type(type) {}


AMateria::~AMateria() {}


AMateria&	AMateria::operator=(const AMateria& rightValue) {
	if (this == &rightValue) return *this;

	this->_type = rightValue._type;
	return *this;
}


const std::string& AMateria::getType() const {
	return this->_type;
}


void		AMateria::use(ICharacter& target) {
	std::cout << "* shoots using an unknown materia at " << target.getName() << " *" << std::endl;
}
