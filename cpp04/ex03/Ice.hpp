#pragma once

#include "AMateria.hpp"

#include <string>

class Ice : public AMateria {
public:
	Ice();
	Ice(const Ice& other);

	~Ice();

	Ice&	operator=(const Ice& rightValue);

	AMateria*	clone() const;
	void		use(ICharacter& target);
};
