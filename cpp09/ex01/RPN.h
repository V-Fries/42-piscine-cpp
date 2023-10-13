#pragma once

#include <string>

class RPN {
public:
	RPN();
	RPN(const RPN& other);

	~RPN();

	RPN&	operator=(const RPN& rightValue);

	static void	solveRPNCalculation(const std::string& RPNCalculation);
};
