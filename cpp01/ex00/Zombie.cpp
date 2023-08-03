#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(const std::string& name) {
	this->name = name;
}

void Zombie::announce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
