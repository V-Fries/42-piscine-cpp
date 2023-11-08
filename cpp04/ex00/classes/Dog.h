#ifndef DOG_H
# define DOG_H

#include <string>

#include "Animal.h"

class Dog : public Animal {
public:
	Dog();
	Dog(const Dog& other);

	~Dog();

	Dog& operator=(const Dog& other);

	void	makeSound() const;
};

#endif
