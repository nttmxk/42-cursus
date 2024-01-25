#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {
protected:
	std::string type;

public:
	Animal();
	virtual ~Animal();
	Animal(const Animal &src);
	Animal& operator=(const Animal &src);
	virtual void makeSound() const = 0;
	std::string getType() const;
};

#endif
