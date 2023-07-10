#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
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
