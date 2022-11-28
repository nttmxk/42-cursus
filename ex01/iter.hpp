#ifndef ITER_HPP

# define ITER_HPP
# include <iostream>

template <typename T>
void	iter(T* arr, unsigned int len, void (*func)(T const &))
{
	for (unsigned int i = 0; i < len; ++i)
		func(arr[i]);
}

template <typename T>
void printArr(T &a)
{
	std::cout << a << std::endl;
}

#endif
