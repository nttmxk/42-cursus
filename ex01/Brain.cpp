#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "[Brain] Default constructor called\n";
}

Brain::Brain(const Brain &src)
{
	std::cout << "[Brain] Copy constructor called\n";
	*this = src;
}

Brain& Brain::operator=(const Brain &src)
{
	std::cout << "[Brain] Copy assignment operator called\n";
	for (int i = 0; i < 100; ++i) {
		ideas[i] = src.ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "[Brain] Destructor called\n";
}

std::string Brain::getIdeas(unsigned int i)
{
	if (i > 100)
		return "";
	return (ideas[i]);
}

void Brain::setIdeas(std::string idea, unsigned int i)
{
	if (i > 100)
		return ;
	ideas[i] = idea;
}
