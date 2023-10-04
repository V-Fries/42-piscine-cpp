#include <iostream>

#include "Span.h"

int main()
{
	int					arr[] = {42, 3, 17, 9, 11};
	Span				span = Span(sizeof(arr) / sizeof(*arr) * 2);

	span.addNumbers(arr, arr + sizeof(arr) / sizeof(*arr));
	std::cout << span << std::endl;

	int					arr2[] = {5413, 4453, 23, 45, 135};
	std::vector<int>	vector(arr2, arr2 + sizeof(arr2) / sizeof(*arr2));
	span.addNumbers(vector.begin(), vector.end());
	std::cout << span << std::endl;

	try {
		span.addNumber(12);
		std::cerr << "Error: sixth elem was added to a size 5 Span" << std::endl;
	} catch (std::exception& e) {
		std::cout << "Successfully throw an exception (" << e.what() << ") when trying to add "
					 "a sixth elem to a size 5 Span" << std::endl;
	}
	if (span.shortestSpan() == 2)
		std::cout << "Successfully found shortest span 2 in Span" << std::endl;
	else
		std::cerr << "Error: failed to find correct shortest span" << std::endl;
	if (span.longestSpan() == 5410)
		std::cout << "Successfully found longest span 5410 in Span" << std::endl;
	else
		std::cerr << "Error: failed to find correct longest span" << std::endl;

	Span spanSize1(1);

	spanSize1.addNumber(34);
	try {
		spanSize1.shortestSpan();
		std::cerr << "Error: spanSize1.shortestSpan was called without exception" << std::endl;
	} catch (std::exception& e) {
		std::cout << "Successfully thrown an error on spanSize1.shortestSpan call: " << e.what() << std::endl;
	}
	try {
		spanSize1.longestSpan();
		std::cerr << "Error: spanSize1.longestSpan was called without exception" << std::endl;
	} catch (std::exception& e) {
		std::cout << "Successfully thrown an error on spanSize1.longestSpan call: " << e.what() << std::endl;
	}

	Span spanSize0(0);

	try {
		spanSize0.shortestSpan();
		std::cerr << "Error: spanSize0.shortestSpan was called without exception" << std::endl;
	} catch (std::exception& e) {
		std::cout << "Successfully thrown an error on spanSize0.shortestSpan call: " << e.what() << std::endl;
	}
	try {
		spanSize0.longestSpan();
		std::cerr << "Error: spanSize0.longestSpan was called without exception" << std::endl;
	} catch (std::exception& e) {
		std::cout << "Successfully thrown an error on spanSize0.longestSpan call: " << e.what() << std::endl;
	}

	return 0;
}
