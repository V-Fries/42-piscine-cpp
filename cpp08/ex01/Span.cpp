#include <stdexcept>
#include <algorithm>
#include <limits>
#include <ostream>

#include "Span.h"

Span::Span():
	_vector(),
	_size(0)
{}

Span::Span(const Span& other):
	_vector(other._vector),
	_size(other._size)
{}

Span::Span(unsigned int size):
	_vector(),
	_size(size)
{}


Span::~Span() {}


Span&	Span::operator=(const Span& rightValue) {
	if (this == &rightValue)
		return *this;
	this->_size = rightValue._size;
	this->_vector = rightValue._vector;
	return *this;
}

int&	Span::operator[](size_t index) {
	if (index >= this->_vector.size())
		throw std::length_error("Index is larger then current Span size");
	return (this->_vector[index]);
}

const int&	Span::operator[](size_t index) const {
	if (index >= this->_vector.size())
		throw std::length_error("Index is larger then current Span size");
	return (this->_vector[index]);
}


unsigned int			Span::getSize() const {
	return this->_size;
}

const std::vector<int>&	Span::getVector() const {
	return this->_vector;
}


void	Span::addNumber(int number) {
	if (this->_vector.size() >= this->_size)
		throw std::length_error("Span is already filled");
	this->_vector.push_back(number);
}


int	Span::shortestSpan() const {
	if (this->_vector.size() < 2)
		throw std::invalid_argument("Span is too short to find the shortest span");

	Span	tmp(*this);
	std::sort(tmp._vector.begin(), tmp._vector.end());

	int							shortestSpan = std::numeric_limits<int>::max();
	for (std::vector<int>::iterator it = tmp._vector.begin() + 1;
		it != tmp._vector.end();
		it++) {
		if (*it - it[-1] < shortestSpan) {
			shortestSpan = *it - it[-1];
		}
	}
	return shortestSpan;
}

int	Span::longestSpan() const {
	if (this->_vector.size() < 2)
		throw std::invalid_argument("Span is too short to find the longest span");

	Span	tmp(*this);
	std::sort(tmp._vector.begin(), tmp._vector.end());

	return (tmp._vector.end()[-1] - *tmp._vector.begin());
}


std::ostream&	operator<<(std::ostream& os, const Span& span) {
	os << "Span: _size(" << span.getSize() << "), _vector(";

	const std::vector<int>	vector = span.getVector();
	for (unsigned int i = 0; i < vector.size() - 1; i++)
		os << vector[i] << ", ";
	os << vector[vector.size() - 1];

	os << ')' << std::endl;

	return os;
}
