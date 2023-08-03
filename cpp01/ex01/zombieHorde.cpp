#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	Zombie* zombieHordeToReturn = new Zombie[N]();

	for (int i = 0; i < N; i++)
		zombieHordeToReturn[i] = Zombie(name);
	return zombieHordeToReturn;
}
