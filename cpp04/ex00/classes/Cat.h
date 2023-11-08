#ifndef CAT_H
# define CAT_H

#include <string>

#include "Animal.h"

class Cat : public Animal {
public:
	Cat();
	Cat(const Cat& other);

	~Cat();

	Cat& operator=(const Cat& other);

	void	makeSound() const;
};

#endif
