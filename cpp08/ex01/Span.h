#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>

class Span {
private:
	std::vector<int>	_vector;
	unsigned int		_size;
public:
	Span();
	Span(const Span& other);
	Span(unsigned int size);

	~Span();

	Span&		operator=(const Span& rightValue);
	int&		operator[](size_t index);
	const int&	operator[](size_t index) const;

	unsigned int			getSize() const;
	const std::vector<int>&	getVector() const;

	void	addNumber(int number);
	template <typename T>
	void	addNumbers(T begin, const T end) {
		while (begin != end) {
			this->addNumber(*begin);
			begin++;
		}
	}

	int	shortestSpan() const;
	int	longestSpan() const;
};

std::ostream&	operator<<(std::ostream& os, const Span& span);

#endif