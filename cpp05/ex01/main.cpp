#include <iostream>

#include "Bureaucrat.h"
#include "Form.h"

#define CORRECT_GRADE 4

int	main() {
	try {
		Form	form("name", 151, CORRECT_GRADE);
		std::cerr << "Error: successfully created form with incorect gradeRequiredToSign"
				  << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Form	form("name", 0, CORRECT_GRADE);
		std::cerr << "Error: successfully created form with incorect gradeRequiredToSign"
				  << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Form	form("name", CORRECT_GRADE, 151);
		std::cerr << "Error: successfully created form with incorect gradeRequiredToExecute"
				  << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Form	form("name", CORRECT_GRADE, 0);
		std::cerr << "Error: successfully created form with incorect gradeRequiredToExecute"
				  << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	Form		correctForm("Cool form", 42, 43);
	std::cout << '\n' << correctForm << '\n' << std::endl;

	Bureaucrat	bureaucratThatCantSign("bureaucratThatCantSign", Bureaucrat::lowestGrade);

	bureaucratThatCantSign.signForm(correctForm);

	Bureaucrat	bureaucratThatCanSign("bureaucratThatCanSign", Bureaucrat::highestGrade);

	bureaucratThatCanSign.signForm(correctForm);
	bureaucratThatCanSign.signForm(correctForm);
}
