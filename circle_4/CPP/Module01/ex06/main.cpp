#include "Harl.hpp"

void	check_leak(void)
{
	system("leaks harlFilter");
}

int main()
{
//	atexit(check_leak);
	std::string input;
	Harl harl = Harl();

	std::cin >> input;
	harl.complain(input);

	return (0);
}