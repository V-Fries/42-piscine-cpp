#include "Ice.hpp"
#include "ICharacter.hpp"

#include <iostream>

Ice::Ice(): AMateria("ice") {}

Ice::Ice(const Ice& other): AMateria(other) {}


Ice::~Ice() {}


Ice&	Ice::operator=(const Ice& rightValue) {
	if (this == &rightValue) return *this;

	AMateria::operator=(rightValue);
	return *this;
}


AMateria*	Ice::clone() const {
	return new Ice(*this);
}

void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
