#include <iostream>
#include <limits>

#include "ClapTrap.h"

ClapTrap::ClapTrap():
	_name("Unnamed"),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0) {
	std::cerr << "ClapTrap " << this->_name << " was created by default constructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap):
	_name(clapTrap._name),
	_hitPoints(clapTrap._hitPoints),
	_energyPoints(clapTrap._energyPoints),
	_attackDamage(clapTrap._attackDamage) {
	std::cerr << "ClapTrap " << this->_name << " was created by copy constructor" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name):
	_name(name),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0) {
	std::cerr << "ClapTrap " << this->_name << " was created by std::string name constructor" << std::endl;
}


ClapTrap::~ClapTrap() {
	std::cerr << "ClapTrap " << this->_name << " destructor was called" << std::endl;
}


ClapTrap&	ClapTrap::operator=(const ClapTrap& right) {
	std::cerr << "ClapTrap " << this->_name << " assignment operator was called, it will be overwriten by "
			  << right._name << std::endl;
	if (this == &right)
		return *this;
	this->_name = right._name;
	this->_hitPoints = right._hitPoints;
	this->_energyPoints = right._energyPoints;
	this->_attackDamage = right._attackDamage;
	return *this;
}


void		ClapTrap::attack(const std::string& target) {
	if (this->_hitPoints == 0) {
		std::cout << "ClapTrap " << this->_name << " can't attack as it is out of health\n"
				  << target << " was not attacked" << std::endl;
		return;
	}
	if (this->_energyPoints == 0) {
		std::cout << "ClapTrap " << this->_name << " can't attack as it is out of energy points\n"
				  << target << " was not attacked" << std::endl;
		return;
	}
	
	this->_energyPoints -= 1;

	std::cout << "ClapTrap " << this->_name << " attacked " << target << ", "
			  << target << " lost " << this->_attackDamage << " hit points\n"
			  << "ClapTrap " << this->_name << " has " << this->_energyPoints << " energy points left" << std::endl;

	if (this->_energyPoints == 0)
		std::cout << this->_name << " is out of energy points" << std::endl;
}

void		ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints == 0) {
		std::cout << "ClapTrap " << this->_name << " can't take domage as it is out of health" << std::endl;
		return;
	}

	if (amount >= this->_hitPoints)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;

	std::cout << "ClapTrap " << this->_name << " lost " << amount << " hit points\n"
			  << "ClapTrap " << this->_name << " new health is " << this->_hitPoints << std::endl;
	
	if (this->_hitPoints == 0)
		std::cout << "ClapTrap " << this->_name << " is out of health" << std::endl;
}

void		ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energyPoints == 0) {
		std::cout << "ClapTrap " << this->_name << " can't be repaired as it is out of energy points\n";
		return;
	}
	if (this->_hitPoints == 0) {
		std::cout << "ClapTrap " << this->_name << " can't be repaired as it is damaged too badly\n";
		return;
	}

	if (this->_hitPoints > std::numeric_limits<unsigned int>::max() - amount) {
		std::cerr << "Warning " << "ClapTrap " << this->_name << " hit points overflowed during repair,"
				  	" setting hit points to " << std::numeric_limits<unsigned int>::max()
				  << std::endl;
		this->_hitPoints = std::numeric_limits<unsigned int>::max();
	}
	else
		this->_hitPoints += amount;

	this->_energyPoints -= 1;

	std::cout << "ClapTrap " << this->_name << " healed by " << amount << " hit points, current health is "
				<< this->_hitPoints << '\n'
			  << "ClapTrap " << this->_name << " has " << this->_energyPoints << " Energy points left" << std::endl;

	if (this->_energyPoints == 0)
		std::cout << "ClapTrap " << this->_name << " is out of energy points" << std::endl;
}
