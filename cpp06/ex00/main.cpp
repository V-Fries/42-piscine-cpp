#include <iostream>

#include "ScalarConverter.h"

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Unexpected argument count, expected:\n\t./ex00 literal" << std::endl;
		return 1;
	}

	const std::string	argument(argv[1]);

	if (argument.length() == 0) {
		std::cerr << "Argument shouldn't be empty" << std::endl;
		return 2;
	}

	ScalarConverter::convert(argument);
}
