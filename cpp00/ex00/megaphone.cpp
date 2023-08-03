#include <iostream>
#include <string>

static void printCStringToUpper(char *string);

int	main(int argc, char **argv) {
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc; i++) {
		printCStringToUpper(argv[i]);
		if (i < argc - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

static void printCStringToUpper(char *string) {
	for (int y = 0; string[y] != '\0'; y++)
		std::cout << (char)toupper(string[y]);
}
