#include "BitcoinExchange.hpp"
#include <iostream>

void check_leaks()
{
	system("leaks btc");
}

int main(int argc, char **argv)
{
//	check_leaks();

//	if (argc != 2)
//	{
//		std::cout << "Input error\n";
//		return (1);
//	}

	BitcoinExchange btc;
	btc.run(argv[1]);
//	btc.print_map();

	return (0);
}
