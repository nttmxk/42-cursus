#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {
protected:
	std::string		name;
	unsigned int 	points_hit;
	unsigned int 	points_energy;
	unsigned int 	damage;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &src);
	ClapTrap& operator=(const ClapTrap &src);
	~ClapTrap();
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	std::string getName() const;
	void setDamage(unsigned int damage);
	unsigned int getHit() const;
	unsigned int getEnergy() const;
	unsigned int getDamage() const;
};

#endif
