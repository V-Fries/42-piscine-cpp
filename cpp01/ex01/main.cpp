#include <iostream>

#include "Zombie.hpp"

#define SIZE 9

int main(void) {
	Zombie* hoardOfZombies = zombieHorde(SIZE, "hoardOfZombiesMember");

	for (int i = 0; i < SIZE; i++)
	{
		std::cout << "Zombie number " << i << ": ";
		hoardOfZombies[i].announce();
	}
	delete[] hoardOfZombies;
}
