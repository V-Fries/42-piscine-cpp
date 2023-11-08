#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>

class ICharacter;

class AMateria {
protected:
	std::string	_type;

public:
	AMateria();
	AMateria(const AMateria& other);
	AMateria(const std::string& type);

	virtual ~AMateria();

	AMateria&	operator=(const AMateria& rightValue);

	const std::string& getType() const;

	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);
};

#endif
