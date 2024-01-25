#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main()
{
	std::vector<int>	v;
	std::list<int>		l;
	std::deque<int>		d;

	for (int i = 0; i < 10; ++i) {
		v.push_back(i);
		l.push_back(i + 20);
		d.push_back(i + 40);
	}

	try {
		std::cout << *easyfind(v, 42) << std::endl;
//		easyfind(v, 84);
	} catch (std::exception &e) {
		std::cout << e.what();
	}

	try {
		std::cout << *easyfind(l, 42) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what();
	}

	try {
		std::cout << *easyfind(d, 42) << std::endl;
//		easyfind(d, 84);
	} catch (std::exception &e) {
		std::cout << e.what();
	}

	return (0);
}