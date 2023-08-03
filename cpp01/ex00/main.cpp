#include "Zombie.hpp"

int main(void) {
	Zombie* zombieOnHeap = newZombie("zombieOnHeap");
	zombieOnHeap->announce();
	delete zombieOnHeap;

	randomChump("randomChump");
}
