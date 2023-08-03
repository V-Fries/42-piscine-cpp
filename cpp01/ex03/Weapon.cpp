#include "Weapon.hpp"

Weapon::Weapon(const std::string &type) {
	this->_type = type;
}

const std::string& Weapon::getType() const {
	return this->_type;
}

void Weapon::setType(const std::string &newType) {
	this->_type = newType;
}

std::ostream&	operator<<(std::ostream& os, const Weapon& weapon) {
	const std::string& weaponType = weapon.getType();
	os << weaponType;
	return os;
}
