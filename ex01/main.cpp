#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Input error\n";
		return (1);
	}
	RPN rpn;
	try {
		rpn.calculate(argv[1]);
	} catch (std::exception &e) {
		std::cout << e.what() << '\n';
	}
	return (0);
}
