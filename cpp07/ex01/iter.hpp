#ifndef ITER_HPP
# define ITER_HPP

#include <cstdlib>

template <typename T>
void	iter(T* array, const size_t size, void (*f)(T& elem)) {
	std::cout << "mutable iter was called" << std::endl;

	if (f == NULL)
		return ;

	const T*	limit = array + size;

	while (array < limit) {
		f(*array);
		array++;
	}
}

template <typename T>
void	iter(const T* array, const size_t size, void (*f)(const T& elem)) {
	std::cout << "const iter was called" << std::endl;

	if (f == NULL)
		return ;

	const T*	limit = array + size;

	while (array < limit) {
		f(*array);
		array++;
	}
}

#endif