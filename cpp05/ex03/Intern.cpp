#include "Intern.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"

typedef enum FormType {
	PRESIDENTIAL_PARDON_FORM,
	ROBOTOMY_REQUEST_FORM,
	SHRUBBERY_CREATION_FORM,
	NUMBER_OF_FORM_TYPES,
	BAD_FORM_TYPE
}	FormType;

static FormType	getFormType(const std::string& name);

Intern::Intern() {}
Intern::Intern(const Intern& other) {static_cast<void>(other);}

Intern&	Intern::operator=(const Intern& other) {
	return *this;
	static_cast<void>(other);
}

AForm*	Intern::makeForm(const std::string& name, const std::string& target) {
	const FormType	formType = getFormType(name);
	AForm*			result;

	switch (formType) {
		case PRESIDENTIAL_PARDON_FORM:
			result = new PresidentialPardonForm(target);
			std::cout << "Intern creates " << result->getName() << std::endl;
			return result;
		case ROBOTOMY_REQUEST_FORM:
			result = new RobotomyRequestForm(target);
			std::cout << "Intern creates " << result->getName() << std::endl;
			return result;
		case SHRUBBERY_CREATION_FORM:
			result = new ShrubberyCreationForm(target);
			std::cout << "Intern creates " << result->getName() << std::endl;
			return result;
		default:
			std::cerr << "Intern failed to create " << name << std::endl;
			return NULL;
	}
}

static FormType	getFormType(const std::string& name) {
	std::string	types[NUMBER_OF_FORM_TYPES] = {"PresidentialPardonForm",
											   "RobotomyRequestForm",
											   "ShrubberyCreationForm"};

	for (int i = 0; i < NUMBER_OF_FORM_TYPES; i++) {
		if (types[i] == name)
			return static_cast<FormType>(i);
	}
	return BAD_FORM_TYPE;
}
