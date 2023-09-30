#include <fstream>

#include "ShrubberyCreationForm.h"
#include "Bureaucrat.h"

ShrubberyCreationForm::ShrubberyCreationForm():
	AForm("ShrubberyCreationForm", 145, 137),
	_target("Unknown target")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target):
	AForm("ShrubberyCreationForm", 145, 137),
	_target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other):
	AForm(other),
	_target(other._target)
{}


ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	this->AForm::operator=(other);
	return *this;
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	this->checkExecuteRequirement(executor);
	const std::string		fileName = this->_target + "_shrubbery";
	std::ofstream			outputFile;

	outputFile.open(fileName.c_str());
	if (!outputFile.is_open()) {
		std::cerr << "Failed to open outputFile " << this->_target + "_shrubbery" << std::endl;
		return ;
	}
	outputFile << "               ,@@@@@@@,\n"
			"       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
			"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
			"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
			"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
			"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
			"   `&%\\ ` /%&'    |.|        \\ '|8'\n"
			"       |o|        | |         | |\n"
			"       |.|        | |         | |\n"
			"jgs \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n"
			"\nhttps://ascii.co.uk/art/tree" << std::endl;
	outputFile.close();
}
