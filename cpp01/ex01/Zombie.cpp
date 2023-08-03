#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie() {
	return;
}

Zombie::Zombie(const std::string& name) {
	this->name = name;
}

Zombie& Zombie::operator=(const Zombie& other) {
	this->name = other.name;
	return *this;
}

void Zombie::announce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
