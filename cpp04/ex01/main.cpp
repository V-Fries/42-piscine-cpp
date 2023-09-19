#include <iostream>

#include "classes/Cat.h"
#include "classes/Dog.h"
#include "classes/WrongCat.h"

int	main() {
	Animal*	animals[4];
	size_t	animalsSize = sizeof(animals) / sizeof(*animals);

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

	std::cout << std::endl << std::endl << std::endl << std::endl;
	Cat	test_ideas;
	std::cout << std::endl << "Fail to get idea: ";
	try {
		std::cout << test_ideas.getIdea(1) << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl << "Add too many ideas: ";
	try {
		for (int i = 0; i < 110; i++)
			test_ideas.addIdea("Cool idea");
		std::cerr << "If this is printed an error occured" << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl << "Get idea: ";
	try {
		std::cout << test_ideas.getIdea(0) << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl << "Get idea with stupid index: ";
	try {
		std::cout << test_ideas.getIdea(255) << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}
