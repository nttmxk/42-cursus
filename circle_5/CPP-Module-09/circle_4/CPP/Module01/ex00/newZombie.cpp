#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie *z = new Zombie(name);
	// std::bad_alloc is thrown when 'new' fails to allocate the requested storage space
	return (z);
}