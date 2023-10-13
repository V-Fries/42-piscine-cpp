#include "RPN.h"

#include <iostream>
#include <stack>
#include <cstdint>

RPN::RPN() {}

RPN::RPN(const RPN& other) {static_cast<void>(other);}


RPN::~RPN() {}


RPN&	RPN::operator=(const RPN& rightValue) {static_cast<void>(rightValue);}


void	RPN::solveRPNCalculation(const std::string& RPNCalculation) {
	std::stack<std::uint8_t>	operands;

	for (size_t i = 0; i < RPNCalculation.length(); i++) {
		if (i % 2)
	}
}
