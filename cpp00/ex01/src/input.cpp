#include <string>
#include <iostream>
#include <limits>

#define EOF_FOUND "End of input reached"

static void printPrompt(std::string prompt);

std::string getLine(std::string prompt) {
	printPrompt(prompt);

	std::string line;
	std::getline(std::cin, line);
	if (std::cin.eof()) {
		throw std::runtime_error(EOF_FOUND);
	} else if (std::cin.fail()) {
		throw std::runtime_error("Input failed");
	}
	return (line);
}

int	getInt(std::string prompt) {
	printPrompt(prompt);

	int input;
	while (true) {
		std::cin >> input;
		if (std::cin.eof()) {
			throw std::runtime_error(EOF_FOUND);
		} else if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Input needs to be an intenger" << std::endl;
			printPrompt(prompt);
		} else {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return input;
		}
	}
}

static void printPrompt(std::string prompt) {
	std::cout << prompt << std::flush;
}
