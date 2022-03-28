#include "philo.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	t_info	info;

	if (argc < 5 || argc > 6 || handle_input(argv, &info))
		return (ft_error());
	return (philo_start(&info));
}

int	philo_start(t_info *info)
{
	;
}

void philo()
{
	do {
		//think;
		take_chopsticks(i);
		//eat;
		put_chopsticks(i);
		//sleep;
	} while(1);
}

void take_chopsticks(int i)
{
	wait(mutex);
	state[i] = HUNGRY;
	test(i);
	signal(mutex);
	wait(self[i]);
}

void put_chopsticks(int i)
{
	wait(mutex);
	state[i] = THINKING;
	test(LEFT);
	test(RIGHT);
	signal(mutex);
}

void test(int i)
{
	if (state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING)
	{
		state[i] = EATING;
		signal(self[i]);
	}
}


int ft_error(void)
{
	printf("Arguments:\n"
		   "number of philosophers\ntime to die\ntime to eat\n"
		   "time_to_sleep\n[number of times each philosopher must eat]");
	return (1);
}

int handle_input(char *argv[], t_info *info) {
	int i;
	int j;

	i = 0;
	while (argv[++i]) {
		j = -1;
		while (argv[i][++j]) {
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (1);
		}
		if (j > 10 || ft_atol(argv[i]) > 4294967295ULL)
			return (1);
	}
	info->NOP = (unsigned int) ft_atol(argv[1]);
	info->TTD = (unsigned int) ft_atol(argv[2]);
	info->TTE = (unsigned int) ft_atol(argv[3]);
	info->TTS = (unsigned int) ft_atol(argv[4]);
	if (i > 5)
		info->NOT = (unsigned int) ft_atol(argv[5]);
	return (0);
}