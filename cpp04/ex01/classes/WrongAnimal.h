#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

#include <string>

class WrongAnimal {
protected:
	std::string	type;

public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& other);
	WrongAnimal(const std::string& type);

	~WrongAnimal();

	WrongAnimal& operator=(const WrongAnimal& other);

	const std::string&	getType() const;
	void				makeSound() const;
};

#endif
