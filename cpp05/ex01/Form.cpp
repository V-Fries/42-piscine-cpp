#include "Form.h"

Form::GradeTooHighException::GradeTooHighException(const std::string &errorMessage):
	std::exception(),
	_errorMessage(errorMessage)
{}

Form::GradeTooHighException::~GradeTooHighException() throw() {}

const char*	Form::GradeTooHighException::what() const throw() {
	return this->_errorMessage.c_str();
}

Form::GradeTooLowException::GradeTooLowException(const std::string &errorMessage):
	std::exception(),
	_errorMessage(errorMessage)
{}

Form::GradeTooLowException::~GradeTooLowException() throw() {}

const char*	Form::GradeTooLowException::what() const throw() {
	return this->_errorMessage.c_str();
}

const char*	Form::FormIsAlreadySigned::what() const throw() {
	return "the form is already signed";
}

Form::Form():
	_name("Unknown form"),
	_isSigned(false),
	_gradeRequiredToSign(Bureaucrat::lowestGrade),
	_gradeRequiredToExecute(Bureaucrat::lowestGrade)
{}

Form::Form(const std::string &name, const Bureaucrat::GradeInt gradeRequiredToSign,
		const Bureaucrat::GradeInt gradeRequiredToExecute):
	_name(name),
	_isSigned(false),
	_gradeRequiredToSign(gradeRequiredToSign),
	_gradeRequiredToExecute(gradeRequiredToExecute)
{
	if (this->_gradeRequiredToSign < Bureaucrat::highestGrade)
		throw Form::GradeTooHighException("gradeRequiredToSign is too high to create a new Form");
	if (this->_gradeRequiredToExecute < Bureaucrat::highestGrade)
		throw Form::GradeTooHighException("gradeRequiredToExecute is too high to create a new Form");
	if (this->_gradeRequiredToSign > Bureaucrat::lowestGrade)
		throw Form::GradeTooLowException("gradeRequiredToSign is too low to create a new Form");
	if (this->_gradeRequiredToExecute > Bureaucrat::lowestGrade)
		throw Form::GradeTooLowException("gradeRequiredToExecute is too low to create a new Form");
}

Form::Form(const Form& other):
	_name(other._name),
	_isSigned(other._isSigned),
	_gradeRequiredToSign(other._gradeRequiredToSign),
	_gradeRequiredToExecute(other._gradeRequiredToExecute)
{}

Form::~Form() {}

const Form&	Form::operator=(const Form& other) {
	if (this == &other)
		return *this;
	this->_isSigned = other._isSigned;
	return *this;
}

const std::string&	Form::getName() const {
	return this->_name;
}

bool	Form::getIsSigned() const {
	return this->_isSigned;
}

Bureaucrat::GradeInt	Form::getGradeRequiredToSign() const {
	return this->_gradeRequiredToSign;
}

Bureaucrat::GradeInt	Form::getGradeRequiredToExecute() const {
	return this->_gradeRequiredToExecute;
}

void	Form::beSigned(const Bureaucrat& bureaucrat) {
	if (this->_isSigned)
		throw Form::FormIsAlreadySigned();
	if (bureaucrat.getGrade() > this->_gradeRequiredToSign)
		throw Form::GradeTooLowException("the bureaucrat grade is too low");
	this->_isSigned = true;
}

std::ostream&	operator<<(std::ostream& os, const Form& form) {
	if (form.getIsSigned()) {
		os << form.getName() << " was signed by a bureaucrat of rank "
		   << form.getGradeRequiredToSign() << " and can be executed by a bureaucrat of rank "
		   << form.getGradeRequiredToExecute() << '.';
	} else {
		os << form.getName() << " wasn't signed yet, it requires a bureaucrat of rank "
		   << form.getGradeRequiredToSign() << " to sign it, and a bureaucrat of rank "
		   << form.getGradeRequiredToExecute() << " to execute it.";
	}
	return os;
}
