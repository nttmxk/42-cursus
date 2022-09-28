#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "[WrongAnimal] Default constructor called\n";
	type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	std::cout << "[WrongAnimal] Copy constructor called\n";
	*this = src;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &src)
{
	std::cout << "[WrongAnimal] Copy assignment operator called\n";
	type = src.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "[WrongAnimal] Destructor called\n";
}

void WrongAnimal::makeSound() const
{
	std::cout << type << " sounds default WrongAnimal sound\n";
}

std::string WrongAnimal::getType() const
{
	return (type);
}