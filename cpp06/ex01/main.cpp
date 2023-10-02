#include "Serializer.h"

int	main() {
	Data	test;

	test.x = 42;
	test.y = 53;
	test.z = 13;
	std::cout << "Printing test: " << test << std::endl;

	uintptr_t	uintPtr = Serializer::serialize(&test);

	std::cout << "test address:\t" << &test
		<< "\nuintPtr value:\t0x" << std::hex << uintPtr << std::endl;

	Data*	uintPtrDeserialized = Serializer::deserialize(uintPtr);

	std::cout << "test address:\t\t\t" << &test
		<< "\nuintPtrDeserialized value:\t" << uintPtrDeserialized << std::endl;

	std::cout << "Printing *uintPtrDeserialized: " << *uintPtrDeserialized << std::endl;
}
