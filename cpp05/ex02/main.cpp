#include <iostream>

#include "Bureaucrat.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"

int	main() {
	PresidentialPardonForm	presidentialPardonForm("PresidentialPardonFormTarget");
	RobotomyRequestForm		robotomyRequestForm("RobotomyRequestFormTarget");
	ShrubberyCreationForm	shrubberyCreationForm("ShrubberyCreationFormTarget");

	std::cout << presidentialPardonForm << '\n'
			  << robotomyRequestForm << '\n'
			  << shrubberyCreationForm << '\n' << std::endl;

	Bureaucrat	lowestRankBureaucrat("lowestRankBureaucrat", Bureaucrat::lowestGrade);
	Bureaucrat	highestRankBureaucrat("highestRankBureaucrat", Bureaucrat::highestGrade);

	lowestRankBureaucrat.signForm(presidentialPardonForm);
	lowestRankBureaucrat.signForm(robotomyRequestForm);
	lowestRankBureaucrat.signForm(shrubberyCreationForm);

	std::cout << '\n'
			  << presidentialPardonForm << '\n'
			  << robotomyRequestForm << '\n'
			  << shrubberyCreationForm << '\n' << std::endl;

	highestRankBureaucrat.executeForm(presidentialPardonForm);
	highestRankBureaucrat.executeForm(robotomyRequestForm);
	highestRankBureaucrat.executeForm(shrubberyCreationForm);

	std::cout << std::endl;

	highestRankBureaucrat.signForm(presidentialPardonForm);
	highestRankBureaucrat.signForm(robotomyRequestForm);
	highestRankBureaucrat.signForm(shrubberyCreationForm);

	std::cout << '\n'
			  << presidentialPardonForm << '\n'
			  << robotomyRequestForm << '\n'
			  << shrubberyCreationForm << '\n' << std::endl;

	lowestRankBureaucrat.executeForm(presidentialPardonForm);
	lowestRankBureaucrat.executeForm(robotomyRequestForm);
	lowestRankBureaucrat.executeForm(shrubberyCreationForm);

	std::cout << std::endl;

	highestRankBureaucrat.executeForm(presidentialPardonForm);
	std::cout << std::endl;
	highestRankBureaucrat.executeForm(robotomyRequestForm);
	std::cout << std::endl;
	highestRankBureaucrat.executeForm(shrubberyCreationForm);
}
