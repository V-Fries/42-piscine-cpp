#pragma once

#include <string>
#include <stack>

class RPN {
public:
	typedef double					OperandType;
	typedef std::stack<OperandType>	Stack;

	RPN();
	RPN(const RPN& other);

	~RPN();

	RPN&	operator=(const RPN& rightValue);

	static OperandType	solveRPNCalculation(const std::string& RPNCalculation);
};
