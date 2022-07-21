#include "philo.h"

/*
 * 	idea:
 * 			[] pthread error handling
 * 			[] t_info free handling -> ft_exit(info)
 * 			[] Don't use exit -> ft_exit(info)
 * 			[] action and print info merge, no need to be seperated.
 *			[] &info->mutex
 */

void *philo_start(void *a)
{
	t_arg *arg;

	arg = (t_arg *)a;
	pthread_mutex_lock(&(arg->info->mutex));
	pthread_mutex_unlock(&(arg->info->mutex));
	if (arg->info == NULL)
		return ;

	while (!arg->info->kill && arg->last_meal != arg->info->NOT)
	{
		take_chopsticks(arg);

		print_info(arg->info, arg->i, 0); // taken a fork
		print_info(arg->info, arg->i, 1); // EATING
		arg->num_meal++;
		if (usleep(arg->info->TTE))
			exit(1);

		arg->last_meal = ft_getms();
		if (arg->last_meal == 0)
			exit(1); // just for now

		put_chopsticks(arg);
		print_info(arg->info, arg->i, 2); //sleep;
		if (usleep(arg->info->TTS))
			exit(1);
		check_starve(arg);
		print_info(arg->info, arg->i, 3); // thinking
	}
	return (0);
}

void take_chopsticks(t_arg *arg)
{
	unsigned int	i;
	int cond;

	cond = 1;
	i = arg->i - 1;
	while (cond)
	{
		pthread_mutex_lock(&(arg->info->mutex));
		if (arg->info->fork[i] && arg->info->fork[((i + 1) % arg->info->NOP)])
		{
			arg->info->fork[i] = 0;
			arg->info->fork[((i + 1) % arg->info->NOP)] = 0;
			cond = 0;
		}
		pthread_mutex_unlock(&(arg->info->mutex));
		if (cond)
		{
			if (usleep(50))
				exit(1);
		}
		if (arg->info->kill)
		{
			printf("Someone got killed\n");
			exit(1); // NON
		}
		else
			check_starve(arg);
	}
}

void put_chopsticks(t_arg *arg)
{
	unsigned int	i;

	i = arg->i - 1;
	pthread_mutex_lock(&(arg->info->mutex));
	arg->info->fork[i] = 1;
	arg->info->fork[((i + 1) % arg->info->NOP)] = 1;
	pthread_mutex_unlock(&(arg->info->mutex));
}