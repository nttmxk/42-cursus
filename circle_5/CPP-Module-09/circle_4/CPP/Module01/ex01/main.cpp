#include "Zombie.hpp"

void	check_leak(void)
{
	system("leaks brainz");
}

int main()
{
//	atexit(check_leak);
	int	N = 10;
	Zombie* zombies = zombieHorde(N, "Zombies");

	for (int i = 0; i < N; ++i)
		zombies[i].announce();
	delete[] zombies; // delete[] is used for an array of objects.
	return (0);
}