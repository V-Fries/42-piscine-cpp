#include <iostream>

#include "Array.h"

template <typename T>
void	testArray(const unsigned int size, const T& firstValue,
				  const T& secondValue, const T& thirdValue) {
	Array<T>	arr(size);

	std::cout << "Printing arr: " << arr << std::endl;
	std::cout << "Setting all arr elems to " << firstValue << std::endl;
	arr.setAllElems(firstValue);
	std::cout << "Printing arr: " << arr << std::endl << std::endl;

	std::cout << "Creating copy of arr in arrCopy (Array<T> arrCopy(arr))" << std::endl;
	Array<T>	arrCopy(arr);
	std::cout << "Printing arrCopy: " << arrCopy << std::endl;
	std::cout << "Setting all arrCopy elems to " << secondValue << std::endl;
	arrCopy.setAllElems(secondValue);
	std::cout << "Printing arrCopy: " << arrCopy << std::endl << std::endl;

	std::cout << "Copying arr in arrCopy (arrCopy = arr)" << std::endl;
	arrCopy = arr;
	std::cout << "Printing arrCopy: " << arrCopy << std::endl << std::endl;

	std::cout << "Setting arr[" << 3 % size << "] to " << thirdValue << std::endl;
	arr[3 % size] = thirdValue;
	std::cout << "Printing arr: " << arr << std::endl;
	std::cout << "Printing arrCopy: " << arrCopy << std::endl << std::endl;

	std::cout << "Creating emptyArr" << std::endl;
	Array<T>	emptyArr;
	std::cout << "Printing emptyArr: " << emptyArr << std::endl << std::endl;

	try {
		std::cout << "Accessing an out of range index on a mutable array" << std::endl;
		std::cout << arr[size] << "Error: " << "was accessed from index size" << std::endl;
	} catch (std::exception& e) {
		std::cout << "Test passed successfully, exception was thrown" << std::endl;
	}
	std::cout << std::endl;
	try {
		const Array<T>*	arrConst = &arr;
		std::cout << "Accessing an out of range index on a const array" << std::endl;
		std::cout << (*arrConst)[size] << "Error: " << "was accessed from index size" << std::endl;
	} catch (std::exception& e) {
		std::cout << "Test passed successfully, exception was thrown" << std::endl;
	}
}

int	main() {
	std::cout << "Testing array with int" << '\n' << std::endl;
	testArray<int>(5, 42, -1, 3);

	std::cout << "\n\n\nTesting array with std::string" << '\n' << std::endl;
	testArray<std::string>(5, "Salut", "Non", "Si");
}
