#include "Cure.hpp"
#include "ICharacter.hpp"

#include <iostream>

Cure::Cure(): AMateria("cure") {}

Cure::Cure(const Cure& other): AMateria(other) {}


Cure::~Cure() {}


Cure&	Cure::operator=(const Cure& rightValue) {
	if (this == &rightValue)
		return *this;
	AMateria::operator=(rightValue);
	return *this;
}


AMateria*	Cure::clone() const {
	return new Cure(*this);
}

void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
