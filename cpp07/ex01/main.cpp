#include <iostream>

#include "iter.hpp"

#define ARR_SIZE 10

static void	printArray(const int* arr, const size_t size);

template <typename T>
void	increment(T& elem) {
	elem++;
}

template <typename T>
void	decrement(T& elem) {
	elem--;
}

int	main() {
	int*	arr = new int[ARR_SIZE];

	for (int i = 0; i < ARR_SIZE; i++)
		arr[i] = i;

	printArray(arr, ARR_SIZE);

	std::cout << "Incrementing array" << std::endl;
	iter<int>(arr, ARR_SIZE, &increment);
	std::cout << std::endl;

	printArray(arr, ARR_SIZE);

	std::cout << "Incrementing array" << std::endl;
	iter<int>(arr, ARR_SIZE, &decrement);
	std::cout << std::endl;
	
	printArray(arr, ARR_SIZE);
}

template <typename T>
void	printElem(const T& elem) {
	std::cout << elem << ", ";
}

static void	printArray(const int* arr, const size_t size) {
	std::cout << "Printing array:" << std::endl;
	iter<int>(arr, size, &printElem);
	std::cout << '\n' << std::endl;
}
