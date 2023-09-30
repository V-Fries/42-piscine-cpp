#pragma once

#include "AForm.h"

class Bureaucrat;

class RobotomyRequestForm : public AForm {
private:
	const std::string	_target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& other);

	~RobotomyRequestForm();

	RobotomyRequestForm&	operator=(const RobotomyRequestForm& other);

	void	execute(const Bureaucrat& executor) const;
};
