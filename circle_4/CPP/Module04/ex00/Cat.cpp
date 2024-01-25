#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "[Cat] Default constructor called\n";
	type = "Cat";
}

Cat::Cat(const Cat &src)
{
	std::cout << "[Cat] Copy constructor called\n";
	*this = src;
}

Cat& Cat::operator=(const Cat &src)
{
	std::cout << "[Cat] Copy assignment operator called\n";
	type = src.type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "[Cat] Destructor called\n";
}

void Cat::makeSound() const
{
	std::cout << type << " sounds meow\n";
}