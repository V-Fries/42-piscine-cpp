#include <iostream>

#include "Bureaucrat.h"
#include "Intern.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"

int	main() {
	Intern					intern;
	PresidentialPardonForm*	presidentialPardonForm
		= dynamic_cast<PresidentialPardonForm*>(intern.makeForm("PresidentialPardonForm",
																"PresidentialPardonFormTarget"));
	RobotomyRequestForm*	robotomyRequestForm
		= dynamic_cast<RobotomyRequestForm*>(intern.makeForm("RobotomyRequestForm",
															 "RobotomyRequestFormTarget"));
	ShrubberyCreationForm*	shrubberyCreationForm
		= dynamic_cast<ShrubberyCreationForm*>(Intern::makeForm("ShrubberyCreationForm",
																"ShrubberyCreationFormTarget"));
	AForm*					badForm = Intern::makeForm("fewfgew", "Fewfwe");

	std::cout << '\n'
			  << *presidentialPardonForm << '\n' << '\n'
			  << *robotomyRequestForm << '\n' << '\n'
			  << *shrubberyCreationForm << '\n' << '\n'
			  << "badForm address: ";
	if (badForm == NULL)
		std::cout << "NULL" << std::endl;
	else
		std::cout << badForm << std::endl;

	delete presidentialPardonForm;
	delete robotomyRequestForm;
	delete shrubberyCreationForm;
}
