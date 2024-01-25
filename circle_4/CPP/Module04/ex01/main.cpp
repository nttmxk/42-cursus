#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void check_leaks()
{
	system("leaks brain");
}

int main()
{
//	atexit(check_leaks);
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	Animal* a[4];

	std::cout << "-------------------------\nAnimal array create start\n\n";
	for (int idx = 0; idx < 4; ++idx) {
		if (idx < 2) {
			a[idx] = new Dog();
		}
		else {
			a[idx] = new Cat();
		}
	}
	std::cout << "-------------------------\nAnimal array assign done\n\n";

	for (int idx = 0; idx < 4; ++idx) {
		a[idx]->makeSound();
		delete a[idx];
	}
	std::cout << "-------------------------\nAnimal array delete done\n\n";

	Dog* b = new Dog();
	b->setBrain("Dog's IDEA", 10);
	Dog* c = new Dog(*b);

	std::cout << b << '\n' << c << '\n';
	std::cout << b->getBrain() << std::endl;
	std::cout << c->getBrain() << std::endl;
	c->setBrain("New IDEA", 5);

	b->printBrain();
	c->printBrain();

	delete b;
	delete c;

	return 0;
}