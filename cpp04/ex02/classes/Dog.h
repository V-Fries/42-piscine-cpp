#pragma once

#include <string>

#include "AAnimal.h"
#include "Brain.h"

class Dog : public AAnimal {
private:
	Brain	*_brain;
public:
	Dog();
	Dog(const Dog& other);

	~Dog();

	Dog& operator=(const Dog& other);

	void	makeSound() const;

	void				addIdea(const std::string& idea);
	const std::string&	getIdea(const IdeasSizeUInt index) const;
};
