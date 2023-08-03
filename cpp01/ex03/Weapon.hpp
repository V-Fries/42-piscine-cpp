#pragma once

#include <string>

class Weapon {
public:
	Weapon();
	Weapon(const std::string &type);

	const std::string&	getType() const;
	void				setType(const std::string &newType);

private:
	std::string _type;
};

std::ostream&	operator<<(std::ostream& os, const Weapon& weapon);