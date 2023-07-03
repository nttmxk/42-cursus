#include "BitcoinExchange.hpp"
#include <iostream>

void check_leaks()
{
	system("leaks btc");
}

int main(int argc, char **argv)
{
	check_leaks();

	if (argc != 2)
	{
		std::cout << "Input error\n";
		return (1);
	}

	return (0);
}
