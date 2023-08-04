#include <iostream>

#include "ScavTrap.h"

ScavTrap::ScavTrap():
	ClapTrap() {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;

	std::cerr << "ScavTrap " << this->_name << " was created by default constructor" << std::endl;
}

ScavTrap::ScavTrap(const std::string name):
	ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;

	std::cerr << "ScavTrap " << this->_name << " was created by std::string name constructor" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other):
	ClapTrap(other) {
	*this = other;

	std::cerr << "ScavTrap " << this->_name << " was created by copy constructor" << std::endl;
}


ScavTrap::~ScavTrap() {
	std::cerr << "ScavTrap " << this->_name << " destructor was called" << std::endl;
}


ScavTrap&	ScavTrap::operator=(const ScavTrap& other) {
	std::cerr << "ScavTrap " << this->_name << " assignment operator was called, it will be overwriten by "
			  << other._name << std::endl;
	if (this == &other)
		return *this;
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return *this;
}


void	ScavTrap::attack(const std::string& target) {
	if (this->_hitPoints == 0) {
		std::cout << "ScavTrap " << this->_name << " can't attack as it is out of health\n"
				  << target << " was not attacked" << std::endl;
		return;
	}
	if (this->_energyPoints == 0) {
		std::cout << "ScavTrap " << this->_name << " can't attack as it is out of energy points\n"
				  << target << " was not attacked" << std::endl;
		return;
	}
	
	this->_energyPoints -= 1;

	std::cout << "ScavTrap " << this->_name << " attacked " << target << ", "
			  << target << " lost " << this->_attackDamage << " hit points\n"
			  << "ScavTrap " << this->_name << " has " << this->_energyPoints << " energy points left" << std::endl;

	if (this->_energyPoints == 0)
		std::cout << "ScavTrap " << this->_name << " is out of energy points" << std::endl;
}

void	ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode" << std::endl;
}
