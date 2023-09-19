#include <iostream>

#include "classes/Cat.h"
#include "classes/Dog.h"
#include "classes/WrongCat.h"

int	main() {
	AAnimal*	animals[4];
	size_t		animalsSize = sizeof(animals) / sizeof(*animals);

	for (size_t i = 0; i < animalsSize; i++) {
		if (i % 2)
			animals[i] = new Cat;
		else
			animals[i] = new Dog;
		std::cout << std::endl;
	}

	std::cout << std::endl << std::endl;
	for (size_t i = 0; i < animalsSize; i++) {
		std::cerr << animals[i]->getType() << ": ";
		animals[i]->makeSound();
	}

	std::cout << std::endl << std::endl;
	for (size_t i = 0; i < animalsSize; i++) {
		delete animals[i];
		std::cout << std::endl;
	}

	// AAnimal test; This does not compile as AAnimal is an abstract class
	// test.makeSound();
}
