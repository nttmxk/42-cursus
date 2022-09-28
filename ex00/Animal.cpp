#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "[Animal] Default constructor called\n";
	type = "Animal";
}

Animal::Animal(const Animal &src)
{
	std::cout << "[Animal] Copy constructor called\n";
	*this = src;
}

Animal& Animal::operator=(const Animal &src)
{
	std::cout << "[Animal] Copy assignment operator called\n";
	type = src.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "[Animal] Destructor called\n";
}

void Animal::makeSound() const
{
	std::cout << type << " sounds default animal sound\n";
}

std::string Animal::getType() const
{
	return (type);
}