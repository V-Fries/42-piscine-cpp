#include <iostream>

#include "Harl.hpp"

int main(void)
{
	Harl harl("This is a debug message",
			  "This is an info message",
			  "This is a warning message",
			  "This is an error message");

	harl.complain("DEBUG");
	std::cout << std::endl;

	harl.complain("INFO");
	std::cout << std::endl;

	harl.complain("WARNING");
	std::cout << std::endl;

	harl.complain("ERROR");
	std::cout << std::endl;

	harl.complain("Unexisting");
}
