#ifndef AFORM_H
# define AFORM_H

#include <iostream>

#include "Bureaucrat.h"

class AForm {
private:
	const std::string			_name;
	bool						_isSigned;
	const Bureaucrat::GradeInt	_gradeRequiredToSign;
	const Bureaucrat::GradeInt	_gradeRequiredToExecute;

	class FormIsAlreadySigned : public std::exception {
		const char*	what() const throw();
	};

	class FormIsntSigned : public std::exception {
		const char*	what() const throw();
	};


protected:
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


public:
	AForm();
	AForm(const std::string &name, const Bureaucrat::GradeInt gradeRequiredToSign,
		 const Bureaucrat::GradeInt gradeRequiredToExecute);
	AForm(const AForm& other);

	~AForm();

	const AForm&	operator=(const AForm& other);

	const std::string&		getName() const;
	bool					getIsSigned() const;
	Bureaucrat::GradeInt	getGradeRequiredToSign() const;
	Bureaucrat::GradeInt	getGradeRequiredToExecute() const;

	void			beSigned(const Bureaucrat& bureaucrat);
	void			checkExecuteRequirement(const Bureaucrat& executor) const;
	virtual void	execute(const Bureaucrat& executor) const = 0;
};

std::ostream&	operator<<(std::ostream& os, const AForm& form);

#endif