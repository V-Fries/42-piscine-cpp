#include <iostream>
#include <vector>
#include <list>

#include "easyfind.hpp"

int	main() {
	int					intArr[] = {23, 5432, 543, 26, 42, 43, 64, 66432, 66};


	std::vector<int>	intVector(intArr, intArr + sizeof(intArr) / sizeof(*intArr));
	try {
		easyfind(intVector, 42);
		std::cout << "Successfully found 42 in intVector" << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Error: Failed to find 42 in intVector" << std::endl;
	}
	try {
		easyfind(intVector, 9999999);
		std::cout << "Error: found 9999999 in intVector despite it not existing" << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Successfully failed to find 9999999 in intVector" << std::endl;
	}

	std::list<int>		intList(intArr, intArr + sizeof(intArr) / sizeof(*intArr));
	try {
		easyfind(intList, 42);
		std::cout << "Successfully found 42 in intList" << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Error: Failed to find 42 in intList" << std::endl;
	}
	try {
		easyfind(intList, 9999999);
		std::cout << "Error: found 9999999 in intList despite it not existing" << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Successfully failed to find 9999999 in intList" << std::endl;
	}
}
