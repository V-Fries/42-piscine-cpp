#include "RPN.hpp"

#include <iostream>
#include <stdexcept>

static void	handlePlus(RPN::Stack& operands);
static void	handleMinus(RPN::Stack& operands);
static void	handleProduct(RPN::Stack& operands);
static void	handleDivision(RPN::Stack& operands);
static bool	doesStringFollowExpectedSyntax(const std::string& RPNCalculation);

RPN::RPN() {}

RPN::RPN(const RPN& other) {static_cast<void>(other);}


RPN::~RPN() {}


RPN&	RPN::operator=(const RPN& rightValue) {static_cast<void>(rightValue); return *this;}

RPN::OperandType	RPN::solveRPNCalculation(const std::string& RPNCalculation) {
	RPN::Stack	operands;

	if (doesStringFollowExpectedSyntax(RPNCalculation) == false) {
		throw (std::invalid_argument("RPNCalculation is incorrect"));
	}

	for (size_t i = 0; i < RPNCalculation.length(); i += 2) {
		switch (RPNCalculation[i]) {
			case '+':
				handlePlus(operands);
				break;
			case '-':
				handleMinus(operands);
				break;
			case '*':
				handleProduct(operands);
				break;
			case '/':
				handleDivision(operands);
				break;
			default:
				operands.push(static_cast<RPN::OperandType>(RPNCalculation[i] - '0'));
				break;
		}
	}

	if (operands.size() != 1) {
		throw (std::invalid_argument("Not enough operators for the number of operands"));
	}

	return (operands.top());
}

static bool	doesStringFollowExpectedSyntax(const std::string& RPNCalculation) {
	for (size_t i = 0; i < RPNCalculation.length(); i++) {
		switch (i % 2) {
			case 0:
				if (RPNCalculation[i] != '+' && RPNCalculation[i] != '-'
						&& RPNCalculation[i] != '*' && RPNCalculation[i] != '/'
						&& !std::isdigit(static_cast<unsigned char>(RPNCalculation[i])))
					return false;
				break;
			case 1:
				if (RPNCalculation[i] != ' ')
					return false;
				break;
		}
	}
	return true;
}

static void	handlePlus(RPN::Stack& operands) {
	if (operands.size() < 2)
		throw (std::invalid_argument("RPNCalculation has a + without 2 operands"));
	RPN::OperandType firstOperand = operands.top();
	operands.pop();
	RPN::OperandType result = operands.top() + firstOperand;
	operands.pop();
	operands.push(result);
}

static void	handleMinus(RPN::Stack& operands) {
	if (operands.size() < 2)
		throw (std::invalid_argument("RPNCalculation has a - without 2 operands"));
	RPN::OperandType firstOperand = operands.top();
	operands.pop();
	RPN::OperandType result = operands.top() - firstOperand;
	operands.pop();
	operands.push(result);
}

static void	handleProduct(RPN::Stack& operands) {
	if (operands.size() < 2)
		throw (std::invalid_argument("RPNCalculation has a * without 2 operands"));
	RPN::OperandType firstOperand = operands.top();
	operands.pop();
	RPN::OperandType result = operands.top() * firstOperand;
	operands.pop();
	operands.push(result);
}

static void	handleDivision(RPN::Stack& operands) {
	if (operands.size() < 2)
		throw (std::invalid_argument("RPNCalculation has a / without 2 operands"));
	RPN::OperandType firstOperand = operands.top();
	operands.pop();
	RPN::OperandType result = operands.top() / firstOperand;
	operands.pop();
	operands.push(result);
}
