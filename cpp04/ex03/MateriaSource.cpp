#include "MateriaSource.hpp"

#include <iostream>

MateriaSource::MateriaSource() {
	for (int i = 0; i < _inventorySize; i++) {
		_inventory[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	for (int i = 0; i < _inventorySize; i++) {
		_inventory[i] = other._inventory[i];
	}
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < _inventorySize; i++) {
		delete _inventory[i];
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rightValue) {
	if (this == &rightValue) return *this;

	for (int i = 0; i < _inventorySize; i++) {
		delete _inventory[i];
		_inventory[i] = rightValue._inventory[i]->clone();
	}

	return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < _inventorySize; i++) {
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
			return;
		}
	}
	delete m;
	std::cerr << "Error: inventory is full" << std::endl;
}

AMateria* MateriaSource::createMateria(const std::string& type) {
	for (int i = 0; i < _inventorySize; i++) {
		if (_inventory[i] != NULL && _inventory[i]->getType() == type) {
			return _inventory[i]->clone();
		}
	}
	std::cerr << "Error: materia not found" << std::endl;
	return NULL;
}
