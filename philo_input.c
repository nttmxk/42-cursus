#include "philo.h"

static int	set_input(char *argv[], t_info *info, int i);

int	handle_input(char *argv[], t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (1);
		}
		if (j > 10 || ft_atol(argv[i]) > 2147483647ULL)
			return (1);
	}
	if (set_input(argv, info, i))
		return (1);
	return (0);
}

static int	set_input(char *argv[], t_info *info, int i)
{
	info->NOP = (unsigned int) ft_atol(argv[1]);
	info->TTD = (unsigned int) ft_atol(argv[2]);
	info->TTE = (unsigned int) ft_atol(argv[3]);
	info->TTS = (unsigned int) ft_atol(argv[4]);
	info->kill = 0;
	if (i > 5)
		info->NOT = (unsigned int) ft_atol(argv[5]);
	else
		info->NOT = -1;
	info->start = ft_getms();
	if (info->start == 0)
		return (1);
	memset(info->fork, 1, (info->NOP + 2) * sizeof(char));
	return (0);
}

int	ft_exit(t_info *info)
{
	free(info);
	return (1);
}

int	ft_error(t_info *info)
{
	printf("Arguments:\n"
		   "number of philosophers\ntime to die\ntime to eat\n"
		   "time_to_sleep\n[number of times each philosopher must eat]\n");
	return (ft_exit(info));
}