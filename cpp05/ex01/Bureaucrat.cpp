#include "Bureaucrat.h"
#include "Form.h"

Bureaucrat::Bureaucrat():
	_name("Unknown"),
	_grade(Bureaucrat::lowestGrade)
{
}

Bureaucrat::Bureaucrat(const std::string& name, Bureaucrat::GradeInt grade):
	_name(name),
	_grade(grade)
{
	if (grade > Bureaucrat::lowestGrade)
		throw Bureaucrat::GradeTooLowException();
	if (grade < Bureaucrat::highestGrade)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat):
	_name(bureaucrat._name),
	_grade(bureaucrat._grade)
{
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& bureaucrat) {
	if (this == &bureaucrat)
		return *this;
	this->_grade = bureaucrat._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {
}

const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

const std::string&	Bureaucrat::getName() const {
	return (this->_name);
}

Bureaucrat::GradeInt	Bureaucrat::getGrade() const {
	return (this->_grade);
}

void	Bureaucrat::incrementGrade() {
	if (--this->_grade < Bureaucrat::highestGrade) {
		this->_grade++;
		throw Bureaucrat::GradeTooHighException();
	}
}

void	Bureaucrat::decrementGrade() {
	if (++this->_grade > Bureaucrat::lowestGrade) {
		this->_grade--;
		throw Bureaucrat::GradeTooLowException();
	}
}

void	Bureaucrat::signForm(Form& form) {
	try {
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	} catch (std::exception& e) {
		std::cout << this->_name << " couldn't sign " << form.getName()
				  << " because " << e.what() << std::endl;
	}
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << '.';
	return os;
}
