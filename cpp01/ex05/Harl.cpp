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
	this->_levelFunctions[0] = &Harl::debug;
	this->_levelFunctions[1] = &Harl::info;
	this->_levelFunctions[2] = &Harl::warning;
	this->_levelFunctions[3] = &Harl::error;
}

void Harl::complain(std::string level)
{
	try
	{
		const int index = Harl::getLevelIndex(level);
		(this->*_levelFunctions[index])();
	}
	catch (std::runtime_error& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

void	Harl::debug(void)
{
	std::cout << this->_debugMessage << std::endl;
}

void	Harl::info(void)
{
	std::cout << this->_infoMessage << std::endl;
}

void	Harl::warning(void)
{
	std::cout << this->_warningMessage << std::endl;
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
