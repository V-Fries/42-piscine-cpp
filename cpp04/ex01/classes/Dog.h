#pragma once

#include <string>

#include "Animal.h"
#include "Brain.h"

class Dog : public Animal {
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
