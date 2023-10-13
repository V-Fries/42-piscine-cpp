#include "RPN.hpp"

#include <iostream>

int	main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << "Error: need an argument" << std::endl;
		return 1;
	}

	try {
		const RPN::OperandType result = RPN::solveRPNCalculation(argv[1]);
		std::cout << result << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}
