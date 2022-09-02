#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::Zombie()
{
	std::cout << "<default> BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << name << " died for real\n";
}

void Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}