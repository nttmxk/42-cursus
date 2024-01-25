#include "Harl.hpp"
#include <string>

void	Harl::complain( std::string level )
{
	void		(Harl::*f[4])(void) = { &Harl::debug,
										&Harl::info,
										&Harl::warning,
										&Harl::error
	};
	std::string operation[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	std::string *indexptr;
	int			index;

	indexptr = find(operation, operation + 4, level);
	index = indexptr - operation;
	switch (index)
	{
		case 0:
			(this->*f[0])();
			std::cout << '\n';
		case 1:
			(this->*f[1])();
			std::cout << '\n';
		case 2:
			(this->*f[2])();
			std::cout << '\n';
		case 3:
			(this->*f[3])();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}

void	Harl::debug( void )
{
	std::cout << "[DEBUG]: I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}
void	Harl::info( void )
{
	std::cout << "[INFO]: I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n";
}
void	Harl::warning( void )
{
	std::cout << "[WARNING]: I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\n";
}
void	Harl::error( void )
{
	std::cout << "[ERROR]: This is unacceptable! I want to speak to the manager now.\n";
}