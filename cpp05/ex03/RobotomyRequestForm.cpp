#include <cstdlib>

#include "RobotomyRequestForm.h"
#include "Bureaucrat.h"

RobotomyRequestForm::RobotomyRequestForm():
	AForm("RobotomyRequestForm", 72, 45),
	_target("Unknown target")
{
	srand (time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target):
	AForm("RobotomyRequestForm", 72, 45),
	_target(target)
{
	srand (time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other):
	AForm(other),
	_target(other._target)
{
	srand (time(NULL));
}


RobotomyRequestForm::~RobotomyRequestForm() {}


RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	this->AForm::operator=(other);
	return *this;
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	this->checkExecuteRequirement(executor);
	std::cout << "DrDrrDrrrDrrr" << std::endl;
	if (std::rand() % 2)
		std::cout << this->_target << " has been robotomized" << std::endl;
	else
		std::cout << this->_target << " has failed to be robotomized" << std::endl;
}
