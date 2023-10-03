#include <iostream>

#include "whatever.hpp"

int	main() {
	int	a(42);
	int	b(675);

	std::cout << "a: " << a << "\nb: " << b << '\n' << std::endl;
	swap<int>(a, b);
	std::cout << "a: " << a << "\nb: " << b << '\n' << std::endl;

	std::cout << "Min: " << min(a, b) << std::endl;
	std::cout << "Max: " << max(a, b) << '\n' << std::endl;

	const int	aConst(a);
	const int	bConst(b);

	std::cout << "Testing min max with const variables" << std::endl;
	std::cout << "Min: " << min(aConst, bConst) << std::endl;
	std::cout << "Max: " << max(aConst, bConst) << std::endl;
}
