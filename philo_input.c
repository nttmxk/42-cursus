#include "philo.h"

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
	info->kill = 0;
	if (i > 5)
		info->NOT = (unsigned int) ft_atol(argv[5]);
	gettimeofday(&(info->start), NULL); // error?
	printf("time: %zu\n", ft_gettime(info->start));
	memset(info->fork, 1, (info->NOP + 2) * sizeof(char)); // error?
	return (0);
}

int ft_error(void)
{
	printf("Arguments:\n"
		   "number of philosophers\ntime to die\ntime to eat\n"
		   "time_to_sleep\n[number of times each philosopher must eat]\n");
	return (1);
}