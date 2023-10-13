#include "BitcoinExchange.h"

#include <iostream>

int	main(int argc, char** argv) {
	if (argc < 2) {
		std::cerr << "Error: need an argument" << std::endl;
		return 1;
	}

	try {
		BitcoinExchange	bitcoinExchange("data.csv");
		bitcoinExchange.evaluatePrices(argv[1]);
		return 0;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 2;
	}
}
