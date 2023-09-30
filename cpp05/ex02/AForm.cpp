#include "AForm.h"

AForm::GradeTooHighException::GradeTooHighException(const std::string &errorMessage):
	std::exception(),
	_errorMessage(errorMessage)
{}

AForm::GradeTooHighException::~GradeTooHighException() throw() {}

const char*	AForm::GradeTooHighException::what() const throw() {
	return this->_errorMessage.c_str();
}

AForm::GradeTooLowException::GradeTooLowException(const std::string &errorMessage):
	std::exception(),
	_errorMessage(errorMessage)
{}

AForm::GradeTooLowException::~GradeTooLowException() throw() {}

const char*	AForm::GradeTooLowException::what() const throw() {
	return this->_errorMessage.c_str();
}

const char*	AForm::FormIsAlreadySigned::what() const throw() {
	return "the form is already signed";
}

const char*	AForm::FormIsntSigned::what() const throw() {
	return "the form isn't signed";
}

AForm::AForm():
	_name("Unknown form"),
	_isSigned(false),
	_gradeRequiredToSign(Bureaucrat::lowestGrade),
	_gradeRequiredToExecute(Bureaucrat::lowestGrade)
{}

AForm::AForm(const std::string &name, const Bureaucrat::GradeInt gradeRequiredToSign,
		const Bureaucrat::GradeInt gradeRequiredToExecute):
	_name(name),
	_isSigned(false),
	_gradeRequiredToSign(gradeRequiredToSign),
	_gradeRequiredToExecute(gradeRequiredToExecute)
{
	if (this->_gradeRequiredToSign < Bureaucrat::highestGrade)
		throw AForm::GradeTooHighException("gradeRequiredToSign is too high to create a new AForm");
	if (this->_gradeRequiredToExecute < Bureaucrat::highestGrade)
		throw AForm::GradeTooHighException("gradeRequiredToExecute is too high to create a new AForm");
	if (this->_gradeRequiredToSign > Bureaucrat::lowestGrade)
		throw AForm::GradeTooLowException("gradeRequiredToSign is too low to create a new AForm");
	if (this->_gradeRequiredToExecute > Bureaucrat::lowestGrade)
		throw AForm::GradeTooLowException("gradeRequiredToExecute is too low to create a new AForm");
}

AForm::AForm(const AForm& other):
	_name(other._name),
	_isSigned(other._isSigned),
	_gradeRequiredToSign(other._gradeRequiredToSign),
	_gradeRequiredToExecute(other._gradeRequiredToExecute)
{}

AForm::~AForm() {}

const AForm&	AForm::operator=(const AForm& other) {
	if (this == &other)
		return *this;
	this->_isSigned = other._isSigned;
	return *this;
}

const std::string&	AForm::getName() const {
	return this->_name;
}

bool	AForm::getIsSigned() const {
	return this->_isSigned;
}

Bureaucrat::GradeInt	AForm::getGradeRequiredToSign() const {
	return this->_gradeRequiredToSign;
}

Bureaucrat::GradeInt	AForm::getGradeRequiredToExecute() const {
	return this->_gradeRequiredToExecute;
}

void	AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (this->_isSigned)
		throw AForm::FormIsAlreadySigned();
	if (bureaucrat.getGrade() > this->_gradeRequiredToSign)
		throw AForm::GradeTooLowException("the bureaucrat grade is too low");
	this->_isSigned = true;
}

void	AForm::checkExecuteRequirement(const Bureaucrat& executor) const {
	if (this->_isSigned == false)
		throw AForm::FormIsntSigned();
	if (executor.getGrade() > this->getGradeRequiredToExecute())
		throw AForm::GradeTooLowException("the bureaucrat grade is too low");
}

std::ostream&	operator<<(std::ostream& os, const AForm& form) {
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
