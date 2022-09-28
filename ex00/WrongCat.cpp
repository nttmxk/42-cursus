#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "[WrongCat] Default constructor called\n";
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &src)
{
	std::cout << "[WrongCat] Copy constructor called\n";
	*this = src;
}

WrongCat& WrongCat::operator=(const WrongCat &src)
{
	std::cout << "[WrongCat] Copy assignment operator called\n";
	type = src.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "[WrongCat] Destructor called\n";
}

void WrongCat::makeSound() const
{
	std::cout << type << " sounds WrongMeow\n";
}