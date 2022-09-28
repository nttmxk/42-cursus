#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void check_leaks()
{
	system("leaks animal");
}

int main()
{
//	atexit(check_leaks);
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	const WrongAnimal* a = new WrongAnimal();
	const WrongAnimal* b = new WrongCat();
	std::cout << b->getType() << " " << std::endl;
	b->makeSound();
	a->makeSound();

	delete meta;
	delete j;
	delete i;
	delete a;
	delete b;

	return 0;
}