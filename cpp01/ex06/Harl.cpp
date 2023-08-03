#include <iostream>

#include "Harl.hpp"

const char*	Harl::_levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

Harl::Harl(const std::string& debugMessage, const std::string& infoMessage,
		   const std::string& warningMessage, const std::string& errorMessage):
	_debugMessage(debugMessage),
	_infoMessage(infoMessage),
	_warningMessage(warningMessage),
	_errorMessage(errorMessage)
{
	return ;
}

void Harl::complain(std::string level)
{
	try {
		const int case_number = Harl::getLevelIndex(level);
		switch (case_number) {
			case 0:
				this->debug();
				break;
			case 1:
				this->info();
				break;
			case 2:
				this->warning();
				break;
			case 3:
				this->error();
				break;
		}
	} catch (std::runtime_error& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

void	Harl::debug(void)
{
	std::cout << this->_debugMessage << std::endl;
	this->info();
}

void	Harl::info(void)
{
	std::cout << this->_infoMessage << std::endl;
	this->warning();
}

void	Harl::warning(void)
{
	std::cout << this->_warningMessage << std::endl;
	this->error();
}

void	Harl::error(void)
{
	std::cout << this->_errorMessage << std::endl;
}

int		Harl::getLevelIndex(std::string& level)
{
	for (int i = 0; i < 4; i++)
		if (level.compare(Harl::_levels[i]) == 0)
			return i;
	throw std::runtime_error("Unknow Harl level: " + level);
}
