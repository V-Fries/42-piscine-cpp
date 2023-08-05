#include <iostream>

#include "FragTrap.h"

FragTrap::FragTrap():
	ClapTrap() {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;

	std::cerr << "FragTrap " << this->_name << " was created by default constructor" << std::endl;
}

FragTrap::FragTrap(const std::string name):
	ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;

	std::cerr << "FragTrap " << this->_name << " was created by std::string name constructor" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other):
	ClapTrap(other) {
	*this = other;

	std::cerr << "FragTrap " << this->_name << " was created by copy constructor" << std::endl;
}


FragTrap::~FragTrap() {
	std::cerr << "FragTrap " << this->_name << " destructor was called" << std::endl;
}


FragTrap&	FragTrap::operator=(const FragTrap& other) {
	std::cerr << "FragTrap " << this->_name << " assignment operator was called, it will be overwriten by "
			  << other._name << std::endl;
	if (this == &other)
		return *this;
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return *this;
}


void	FragTrap::attack(const std::string& target) {
	if (this->_hitPoints == 0) {
		std::cout << "FragTrap " << this->_name << " can't attack as it is out of health\n"
				  << target << " was not attacked" << std::endl;
		return;
	}
	if (this->_energyPoints == 0) {
		std::cout << "FragTrap " << this->_name << " can't attack as it is out of energy points\n"
				  << target << " was not attacked" << std::endl;
		return;
	}
	
	this->_energyPoints -= 1;

	std::cout << "FragTrap " << this->_name << " attacked " << target << ", "
			  << target << " lost " << this->_attackDamage << " hit points\n"
			  << "FragTrap " << this->_name << " has " << this->_energyPoints << " energy points left" << std::endl;

	if (this->_energyPoints == 0)
		std::cout << "FragTrap " << this->_name << " is out of energy points" << std::endl;
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << this->_name << " requests a high fives" << std::endl;
}
