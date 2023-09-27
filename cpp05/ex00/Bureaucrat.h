#pragma once

#include <ostream>

class Bureaucrat
{
public:
	typedef short GradeInt;

	static const GradeInt	lowestGrade = 150;
	static const GradeInt	highestGrade = 1;


private:
	std::string	_name;
	GradeInt	_grade;

	class GradeTooHighException : public std::exception {
		const char*	what() const throw();
	};

	class GradeTooLowException : public std::exception {
		const char*	what() const throw();
	};


public:
	Bureaucrat();
	Bureaucrat(const std::string& name, GradeInt grade);
	Bureaucrat(const Bureaucrat& bureaucrat);

	~Bureaucrat();

	Bureaucrat&	operator=(const Bureaucrat& bureaucrat);

	const std::string&	getName() const;
	GradeInt			getGrade() const;
	void				incrementGrade();
	void				decrementGrade();
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
