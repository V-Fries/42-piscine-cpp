#pragma once

#include "AForm.h"

class Bureaucrat;

class PresidentialPardonForm : public AForm {
private:
	const std::string	_target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& other);

	~PresidentialPardonForm();

	PresidentialPardonForm&	operator=(const PresidentialPardonForm& other);

	void	execute(const Bureaucrat& executor) const;
};
