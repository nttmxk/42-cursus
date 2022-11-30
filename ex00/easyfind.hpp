#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template <typename T>
typename T::iterator	easyfind(T& container, int key)
{
	typename T::iterator iter;

	iter = std::find(container.begin(), container.end(), key);
	if (iter != container.end())
		return (iter);
	throw std::runtime_error(std::to_string(key) + " is not in this container\n");
}

#endif