#include <string>
#include <iostream>

int main(void) {
	std::string		string = "HI THIS IS BRAIN";
	std::string*	stringPTR = &string;
	std::string&	stringREF = string;

	std::cout << "The memory address of the string variable: " << &string << '\n'
			  << "The memory address held by stringPTR: " << stringPTR << '\n'
			  << "The memory address held by stringREF: " << &stringREF << '\n'
			  << '\n'
			  << "The value of the string variable: " << string << '\n'
			  << "The value pointed to by stringPTR: " << *stringPTR << '\n'
			  << "The value pointed to by stringREF: " << stringREF << std::endl;
}
