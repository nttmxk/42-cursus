#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class ScavTrap : public ClapTrap {
private:
	bool keeper_mode;

public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &src);
	ScavTrap& operator=(const ScavTrap &src);
	~ScavTrap();
	void attack(const std::string& target);
	void guardGate();
};

#endif