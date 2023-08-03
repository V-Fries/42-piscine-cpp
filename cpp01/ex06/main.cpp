#include <iostream>

#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Bad parameter count, expected:\n\t./harlFilter HARL_LVL"
				  << std::endl;
		return 1;
	}

	Harl harl("This is a debug message",
			  "This is an info message",
			  "This is a warning message",
			  "This is an error message");

	harl.complain(argv[1]);
}
