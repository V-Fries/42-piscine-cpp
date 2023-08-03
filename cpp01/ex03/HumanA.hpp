#pragma once

#include "Weapon.hpp"

class HumanA {
public:
	HumanA(const std::string& name, Weapon& weapon);

	void attack();

private:
	std::string	_name;
	Weapon&		_weapon;
};
