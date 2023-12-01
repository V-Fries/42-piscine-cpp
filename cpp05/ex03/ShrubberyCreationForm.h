#ifndef SHRUBBERY_CREATION_FORM_H
# define SHRUBBERY_CREATION_FORM_H

#include "AForm.h"

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
private:
	const std::string	_target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);

	~ShrubberyCreationForm();

	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);

	void	execute(const Bureaucrat& executor) const;
};

#endif