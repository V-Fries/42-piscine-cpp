#include "Character.hpp"

#include <iostream>

Character::Character():
	_name("Unknown") {
	for (int i = 0; i < _inventorySize; i++) {
		_inventory[i] = NULL;
		_isEquipped[i] = true;
	}
}

Character::Character(const Character& other):
	_name(other._name) {
	for (int i = 0; i < _inventorySize; i++) {
		if (other._inventory[i] != NULL)
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
		_isEquipped[i] = other._isEquipped[i];
	}
}

Character::Character(const std::string& name):
	_name(name) {
	for (int i = 0; i < _inventorySize; i++) {
		_inventory[i] = NULL;
		_isEquipped[i] = true;
	}
}


Character::~Character() {
	for (int i = 0; i < _inventorySize; i++) {
		delete _inventory[i];
	}
}


Character&	Character::operator=(const Character& rightValue) {
	if (this == &rightValue) return *this;

	_name = rightValue._name;
	for (int i = 0; i < _inventorySize; i++) {
		if (_inventory[i] != NULL) {
			delete _inventory[i];
		}
		if (rightValue._inventory[i] != NULL) {
			_inventory[i] = rightValue._inventory[i]->clone();
		}
		else {
			_inventory[i] = NULL;
		}
	}

	return *this;
}

bool	Character::isIndexValid(int idx) const {
	return idx >= 0 && idx < _inventorySize;
}

const std::string& Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < _inventorySize; i++) {
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
			return;
		}
	}
	delete m;
	std::cerr << "Inventory is full" << std::endl;
}

void Character::unequip(int idx) {
	if (!isIndexValid(idx)) {
		std::cerr << "Index is out of bounds" << std::endl;
		return;
	}

	if (_inventory[idx] == NULL) {
		std::cerr << "Can't unequip an empty slot" << std::endl;
		return;
	}
	if (!_isEquipped[idx]) {
		std::cerr << "Can't unequip an allready unequipped materia" << std::endl;
		return;
	}

	_isEquipped[idx] = false;
}

void	Character::use(int idx, ICharacter& target) {
	if (!isIndexValid(idx)) {
		std::cerr << "Index is out of bounds" << std::endl;
		return;
	}

	if (_inventory[idx] == NULL) {
		std::cerr << "Can't use an empty slot" << std::endl;
		return;
	}
	if (!_isEquipped[idx]) {
		std::cerr << "Can't use an unequipped materia" << std::endl;
		return;
	}

	_inventory[idx]->use(target);
}
