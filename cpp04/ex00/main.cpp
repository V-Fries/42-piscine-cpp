#include <iostream>

#include "classes/Cat.h"
#include "classes/Dog.h"
#include "classes/WrongCat.h"

int	main() {
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		const Animal testCopyConstructor(*meta);
		std::cout << testCopyConstructor.getType() << std::endl;
		testCopyConstructor.makeSound();

		delete meta;
		delete j;
		delete i;


		Cat	stackCat;
		stackCat.makeSound();

		Cat*	heapCat = new Cat(stackCat);
		heapCat->makeSound();

		Dog stackDog;
		stackDog.makeSound();

		Dog*	heapDog = new Dog(stackDog);
		heapDog->makeSound();

		Animal* animals[] = {&stackCat, &stackDog, heapCat, heapDog};
		for (size_t a = 0; a < sizeof(animals) / sizeof(*animals); a++)
			animals[a]->makeSound();
		delete heapCat;
		delete heapDog;
	}
	{
		std::cout << "\n\n\nWrongCat:" << std::endl;
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		meta->makeSound();

		const WrongAnimal testCopyConstructor(*meta);
		std::cout << testCopyConstructor.getType() << std::endl;
		testCopyConstructor.makeSound();
		delete meta;
		delete i;


		WrongCat	stackCat;
		stackCat.makeSound();

		WrongCat*	heapCat = new WrongCat(stackCat);
		heapCat->makeSound();

		WrongAnimal* animals[] = {&stackCat, heapCat};
		for (size_t a = 0; a < sizeof(animals) / sizeof(*animals); a++)
			animals[a]->makeSound();
		delete heapCat;
	}
}
