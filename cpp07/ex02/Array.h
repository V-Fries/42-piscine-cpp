#include <iostream>

template <typename T>
class Array {
private:
	T*				_array;
	unsigned int	_size;

public:
	Array():
		_array(NULL),
		_size(0)
	{}

	Array(const Array& other):
		_array(new T[other._size]),
		_size(other._size) {

		for (unsigned int i = 0; i < this->_size; i++)
			this->_array[i] = other._array[i];
	}

	Array(const unsigned int n):
		_array(new T[n]()),
		_size(n) {
	}

	~Array() {delete[] this->_array;}


	Array&	operator=(const Array& rightValue) {
		if (this == &rightValue)
			return *this;

		delete[] this->_array;

		this->_array = new T[rightValue._size];
		this->_size = rightValue._size;
		for (unsigned int i = 0; i < this->_size; i++)
			this->_array[i] = rightValue._array[i];
		return *this;
	}

	T&	operator[](size_t i) {
		if (i >= this->_size)
			throw std::exception();
		return (this->_array[i]);
	}

	const T&	operator[](size_t i) const {
		if (i >= this->_size)
			throw std::exception();
		return (this->_array[i]);
	}

	unsigned int	size() const {
		return this->_size;
	}

	void	setAllElems(const T& value) {
		for (unsigned int i = 0; i < this->_size; i++)
			this->_array[i] = value;
	}
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& arr) {
	if (arr.size() == 0) {
		os << "NULL";
		return os;
	}

	for (unsigned int i = 0; i < arr.size() - 1; i++)
		os << arr[i] << ", ";
	os << arr[arr.size() - 1];
	return os;
}
