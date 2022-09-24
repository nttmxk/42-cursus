#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap Default constructor called\n";
	name = "[Scav Default]";
	points_hit = 100;
	points_energy = 50;
	damage = 20;
	keeper_mode = false;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap name constructor called\n";
	this->name = name;
	points_hit = 100;
	points_energy = 50;
	damage = 20;
	keeper_mode = false;
}

ScavTrap::ScavTrap(const ScavTrap &src)
{
	std::cout << "ScavTrap Copy constructor called\n";
	*this = src;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &src)
{
	std::cout << "ScavTrap Copy assignment operator called\n";
	name = src.getName();
	points_hit = src.getHit();
	points_energy = src.getEnergy();
	damage = src.getDamage();
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called\n";
}

void ScavTrap::attack(const std::string& target)
{
	if (getEnergy() == 0)
	{
		std::cout << "ScavTrap " << getName() << " have not enough energy!\n";
		return ;
	}
	points_energy--;
	std::cout << "ScavTrap " << getName() << " attacks " << target << \
	", causing " << getDamage() << " points of damage!\n";
}

void ScavTrap::guardGate()
{
	if (keeper_mode)
	{
		std::cout << "ScavTrap " << getName() << " is already in Gatekeeper mode\n";
		return ;
	}
	std::cout << "ScavTrap " << getName() << " is now in Gatekeeper mode\n";
	keeper_mode = true;
}