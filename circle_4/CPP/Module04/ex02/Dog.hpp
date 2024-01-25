#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal {
private:
	Brain* brain;

public:
	Dog();
	~Dog();
	Dog(const Dog &src);
	Dog& operator=(const Dog &src);
	void makeSound() const;
	void setBrain(std::string idea, unsigned int n);
	Brain* getBrain();
	void printBrain();
};

#endif
