#ifndef SCALAR_CONVERTER_H
# define SCALAR_CONVERTER_H

#include <string>

class ScalarConverter {
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);

	~ScalarConverter();

	ScalarConverter&	operator=(const ScalarConverter& other);

public:
	static void	convert(const std::string& literalString);
};

#endif