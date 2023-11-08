#ifndef AANIMAL_H
# define AANIMAL_H

#include <string>

class AAnimal {
protected:
	std::string	type;

public:
	AAnimal();
	AAnimal(const AAnimal& other);
	AAnimal(const std::string& type);

	virtual ~AAnimal();

	AAnimal& operator=(const AAnimal& other);

	const std::string&	getType() const;
	virtual void		makeSound() const = 0;
};

#endif
