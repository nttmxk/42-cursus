#ifndef Cat_HPP
# define Cat_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal {
private:
	Brain* brain;

public:
	Cat();
	~Cat();
	Cat(const Cat &src);
	Cat& operator=(const Cat &src);
	void makeSound() const;
	void setBrain(std::string idea, unsigned int n);
	Brain* getBrain();
	void printBrain();
};

#endif
