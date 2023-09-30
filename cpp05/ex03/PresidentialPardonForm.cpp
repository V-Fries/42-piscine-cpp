#include "PresidentialPardonForm.h"
#include "Bureaucrat.h"

PresidentialPardonForm::PresidentialPardonForm():
	AForm("PresidentialPardonForm", 25, 5),
	_target("Unknown target")
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target):
	AForm("PresidentialPardonForm", 25, 5),
	_target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other):
	AForm(other),
	_target(other._target)
{}


PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	this->AForm::operator=(other);
	return *this;
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	this->checkExecuteRequirement(executor);
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
