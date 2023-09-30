#pragma once

#include <string>

class AForm;

class Intern {
public:
	Intern();
	Intern(const Intern& other);

	Intern&	operator=(const Intern& other);

	static AForm*	makeForm(const std::string& name, const std::string& target);
};
