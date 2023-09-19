#pragma once

#include <string>

class Animal {
protected:
	std::string	type;

public:
	Animal();
	Animal(const Animal& other);
	Animal(const std::string& type);

	virtual ~Animal();

	Animal& operator=(const Animal& other);

	const std::string&	getType() const;
	virtual void		makeSound() const;
};
