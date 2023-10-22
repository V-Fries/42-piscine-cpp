#pragma once

#include "AMateria.hpp"

class Cure : public AMateria {
public:
	Cure();
	Cure(const Cure& other);

	~Cure();

	Cure&	operator=(const Cure& rightValue);

	AMateria*	clone() const;
	void		use(ICharacter& target);
};
