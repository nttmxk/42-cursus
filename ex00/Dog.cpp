#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "[Dog] Default constructor called\n";
	type = "Dog";
}

Dog::Dog(const Dog &src)
{
	std::cout << "[Dog] Copy constructor called\n";
	*this = src;
}

Dog& Dog::operator=(const Dog &src)
{
	std::cout << "[Dog] Copy assignment operator called\n";
	type = src.type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "[Dog] Destructor called\n";
}

void Dog::makeSound() const
{
	std::cout << type << " sounds woof\n";
}