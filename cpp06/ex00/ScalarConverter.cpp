#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cerrno>
#include <cmath>
#include <limits>

#include "ScalarConverter.h"

#define DECIMAL_PRECISION 4

static void	convertCharacter(const char character);
static void	printChar(const double literal);
static void	printInt(const double literal);
static void	printFloat(const double literal);
static void	printDouble(const double literal);

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {static_cast<void>(other);}
ScalarConverter::~ScalarConverter() {}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& other) {
	static_cast<void>(other);
	return *this;
}

void	ScalarConverter::convert(const std::string& literalString) {
	if (literalString.length() == 1)
		return convertCharacter(literalString[0]);

	char*			lastTreatedChar;
	const double	literal = std::strtod(literalString.c_str(), &lastTreatedChar);

	const bool	lastCharIsF = *lastTreatedChar == 'f' && lastTreatedChar[1] == '\0';
	const bool	stringDidntContainALiteral = *lastTreatedChar != '\0' && lastCharIsF == false;

	if (errno == ERANGE || stringDidntContainALiteral || std::isspace(literalString[0])) {
		std::cerr << "Invalid value" << std::endl;
		return;
	}

	printChar(literal);
	printInt(literal);
	printFloat(literal);
	printDouble(literal);
}

static void	convertCharacter(const char character) {
	const bool	charIsPrintable = std::isprint(static_cast<unsigned char>(character));

	if (charIsPrintable)
		std::cout << "char: " << character << '\n';
	else
		std::cout << "char: " << "Non displayable" << '\n';
	std::cout << "int: " << static_cast<int>(character) << '\n'
			  << std::setprecision(DECIMAL_PRECISION) << std::fixed
			  << "float: " << static_cast<float>(character) << "f\n"
			  << "double: " << static_cast<double>(character) << std::endl;
}

static void	printChar(const double literal) {
	
	std::cout << "char: ";
	if (std::isnan(literal) || std::isinf(literal))
		std::cout << "Impossible";
	else if (literal < static_cast<double>(std::numeric_limits<char>::min()))
		std::cout << "Underflow";
	else if (literal > static_cast<double>(std::numeric_limits<char>::max()))
		std::cout << "Overflow";
	else if (!std::isprint(static_cast<unsigned char>(literal)))
		std::cout << "Non displayable";
	else
		std::cout << static_cast<char>(literal);
	std::cout << std::endl;
}

static void	printInt(const double literal) {
	std::cout << "int: ";
	if (std::isnan(literal) || std::isinf(literal))
		std::cout << "Impossible";
	else if (literal < static_cast<double>(std::numeric_limits<int>::min()))
		std::cout << "Underflow";
	else if (literal > static_cast<double>(std::numeric_limits<int>::max()))
		std::cout << "Overflow";
	else
		std::cout << static_cast<int>(literal);
	std::cout << std::endl;
}

static void	printFloat(const double literal) {
	std::cout << "float: ";
	std::cout << std::setprecision(DECIMAL_PRECISION) << std::fixed;
	if (std::isnan(literal) || std::isinf(literal))
		std::cout << static_cast<float>(literal) << 'f';
	else if (literal < -static_cast<double>(std::numeric_limits<float>::max()))
		std::cout << "Underflow";
	else if (literal > static_cast<double>(std::numeric_limits<float>::max()))
		std::cout << "Overflow";
	else
		std::cout << static_cast<float>(literal) << 'f';
	std::cout << std::endl;
}

static void	printDouble(const double literal) {
	std::cout << "double: " << std::setprecision(DECIMAL_PRECISION) << std::fixed
			  << literal << std::endl;
}
