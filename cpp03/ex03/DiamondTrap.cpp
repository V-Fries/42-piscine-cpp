#include <iostream>

#include "DiamondTrap.h"

DiamondTrap::DiamondTrap():
	_name("Unnamed") {

	std::cerr << "DiamondTrap " << this->_name << " default constructor called" << std::endl;

	this->ClapTrap::_name = this->_name + "_clap_name";
	this->_hitPoints = this->FragTrap::_hitPoints;
	this->_energyPoints = this->ScavTrap::_energyPoints;
	this->_attackDamage = this->FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other):
	ClapTrap(other),
	ScavTrap(other),
	FragTrap(other) {

	std::cerr << "DiamondTrap " << this->_name << " copy constructor called" << std::endl;

	*this = other;
}

DiamondTrap::DiamondTrap(const std::string &name):
	_name(name) {

	std::cerr << "DiamondTrap " << this->_name << " std::string name constructor called" << std::endl;

	this->ClapTrap::_name = this->_name + "_clap_name";
	this->_hitPoints = this->FragTrap::_hitPoints;
	this->_energyPoints = this->ScavTrap::_energyPoints;
	this->_attackDamage = this->FragTrap::_attackDamage;
}


DiamondTrap::~DiamondTrap() {
	std::cerr << "DiamondTrap " << this->_name << " desctructor called" << std::endl;
}


DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other) {
	if (this == &other)
		return *this;

	std::cerr << "DiamondTrap " << this->_name << " assignment operator called" << std::endl;

	if (this != &other)
	{
		this->_name = other._name;
		ClapTrap::_name = other.ClapTrap::_name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}


void DiamondTrap::whoAmI() {
	std::cout << "This DiamondTrap is called " << this->_name
			  << " it's ClapTrap name is " << this->ClapTrap::_name << std::endl;
}
