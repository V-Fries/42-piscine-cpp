#ifndef EASY_FIND_HPP
# define EASY_FIND_HPP

#include <algorithm>

template <typename T>
typename T::iterator	easyfind(T &container, const int toFind)
{
	typename T::iterator it = std::find(container.begin(), container.end(), toFind);
	if (it == container.end())
		throw (std::exception());
	return it;
}

template <typename T>
const typename T::iterator	easyfind(const T &container, const int toFind)
{
	const typename T::iterator it = std::find(container.begin(), container.end(), toFind);
	if (it == container.end())
		throw (std::exception());
	return it;
}

#endif