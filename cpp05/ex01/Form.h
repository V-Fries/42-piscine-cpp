#ifndef FORM_H
# define FORM_H

#include <iostream>

#include "Bureaucrat.h"

class Form {
private:
	const std::string			_name;
	bool						_isSigned;
	const Bureaucrat::GradeInt	_gradeRequiredToSign;
	const Bureaucrat::GradeInt	_gradeRequiredToExecute;

	class GradeTooHighException : public std::exception {
	private:
		const std::string	_errorMessage;
	public:

		GradeTooHighException(const std::string& errorMessage);
		~GradeTooHighException() throw();

		const char*	what() const throw();
	};

	class GradeTooLowException : public std::exception {
	private:
		const std::string	_errorMessage;
	public:

		GradeTooLowException(const std::string& errorMessage);
		~GradeTooLowException() throw();

		const char*	what() const throw();
	};

	class FormIsAlreadySigned : public std::exception {
		const char*	what() const throw();
	};

public:
	Form();
	Form(const std::string &name, const Bureaucrat::GradeInt gradeRequiredToSign,
		 const Bureaucrat::GradeInt gradeRequiredToExecute);
	Form(const Form& other);

	~Form();

	const Form&	operator=(const Form& other);

	const std::string&		getName() const;
	bool					getIsSigned() const;
	Bureaucrat::GradeInt	getGradeRequiredToSign() const;
	Bureaucrat::GradeInt	getGradeRequiredToExecute() const;

	void	beSigned(const Bureaucrat& bureaucrat);
};

std::ostream&	operator<<(std::ostream& os, const Form& form);

#endif