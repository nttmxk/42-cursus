#include "Harl.hpp"

void	check_leak(void)
{
	system("leaks harl_2");
}

int main()
{
	atexit(check_leak);
	Harl harl = Harl();

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("POPEYES");

	return (0);
}