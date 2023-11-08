#ifndef CAT_H
# define CAT_H

#include <string>

#include "AAnimal.h"
#include "Brain.h"

class Cat : public AAnimal {
private:
	Brain	*_brain;
public:
	Cat();
	Cat(const Cat& other);

	~Cat();

	Cat& operator=(const Cat& other);

	void	makeSound() const;

	void				addIdea(const std::string& idea);
	const std::string&	getIdea(const IdeasSizeUInt index) const;
};

#endif
