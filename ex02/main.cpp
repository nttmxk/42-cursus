#include "PmergeMe.hpp"
#include <iostream>

void check_leaks()
{
	system("leaks PmergeMe");
}

int main(int argc, char **argv)
{
//	check_leaks();

//	PmergeMe test;
//	try {
//		test.sortTest();
//	} catch (std::exception &e) {
//		std::cout << e.what() << '\n';
//	}

	if (argc < 2 || argc > 10000000)
	{
		std::cout << "Error\n";
		return (1);
	}
	PmergeMe pm;

	try {
		pm.sort(argc - 1, argv);
	} catch (std::exception &e) {
		std::cout << e.what() << '\n';
	}
	return (0);
}