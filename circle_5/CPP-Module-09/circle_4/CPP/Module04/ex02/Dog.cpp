#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "[Dog] Default constructor called\n";
	type = "Dog";
	brain = new Brain();
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
	brain = new Brain(*src.brain);
	return (*this);
}

Dog::~Dog()
{
	std::cout << "[Dog] Destructor called\n";
	delete brain;
}

void Dog::makeSound() const
{
	std::cout << type << " sounds woof\n";
}

void Dog::setBrain(std::string idea, unsigned int n)
{
	std::cout << "[Dog] setBrain called\n";
	if (n > 100)
	{
		std::cout << "Number of Ideas cannot be more than 100\n";
		return ;
	}
	for (int i = 0; i < (int)n; ++i)
		brain->setIdeas(idea, i);
}

Brain* Dog::getBrain()
{
	return (brain);
}

void Dog::printBrain()
{
	std::cout << "PrintBrainStart\n---------------------\n";
	for (int i = 0; i < 100; ++i) {
		if (brain->getIdeas(i) != "")
			std::cout << brain->getIdeas(i) << '\n';
	}
	std::cout << "PrintBrainDone\n---------------------\n";
}