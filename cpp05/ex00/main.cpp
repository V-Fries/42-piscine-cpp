#include <iostream>

#include "Bureaucrat.h"

int	main() {
	try {
		Bureaucrat	gradeToLow("name", 160);
		std::cerr << "Error Managed to create a bureaucrat with a grade that was too low"
				  << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat	gradeToHigh("name", 0);
		std::cerr << "Error Managed to create a bureaucrat with a grade that was too low"
				  << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}


	Bureaucrat	correctBureaucrat("Cool name", 4);

	try {
		while (true) {
			correctBureaucrat.incrementGrade();
			if (correctBureaucrat.getGrade() < Bureaucrat::highestGrade) {
				std::cerr << "Error managed to increment _grade below Bureaucrat::highestGrade"
						  << std::endl;
			}
		}
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		while (true) {
			correctBureaucrat.decrementGrade();
			if (correctBureaucrat.getGrade() > Bureaucrat::lowestGrade) {
				std::cerr << "Error managed to decrement _grade above Bureaucrat::highestGrade"
						  << std::endl;
			}
		}
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cerr << "Printing correctBureaucrat: " << correctBureaucrat << std::endl;
}
