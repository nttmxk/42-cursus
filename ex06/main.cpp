#include "Harl.hpp"

int main()
{
	std::string input;
	Harl harl = Harl();

	std::cin >> input;
	harl.complain(input);

	return (0);
}