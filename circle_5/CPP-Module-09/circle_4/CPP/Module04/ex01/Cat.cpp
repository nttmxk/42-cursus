#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "[Cat] Default constructor called\n";
	type = "Cat";
	brain = new Brain();
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
	brain = new Brain(*src.brain);
	return (*this);
}

Cat::~Cat()
{
	std::cout << "[Cat] Destructor called\n";
	delete brain;
}

void Cat::makeSound() const
{
	std::cout << type << " sounds meow\n";
}

void Cat::setBrain(std::string idea, unsigned int n)
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

Brain* Cat::getBrain()
{
	return (brain);
}

void Cat::printBrain()
{
	std::cout << "PrintBrainStart\n---------------------\n";
	for (int i = 0; i < 100; ++i) {
		if (brain->getIdeas(i) != "")
			std::cout << brain->getIdeas(i) << '\n';
	}
	std::cout << "PrintBrainDone\n---------------------\n";
}