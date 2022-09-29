#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void check_leaks()
{
	system("leaks abstract");
}

int main()
{
//	atexit(check_leaks);

//	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();

	delete j;
	delete i;

	return 0;
}