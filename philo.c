#include "philo.h"

int main(int argc, char *argv[])
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (!info)
		return (1);
	if (argc < 5 || argc > 6 || handle_input(argv, info))
		return (ft_error(info));
	return (philo_start(info));
}

/*
 * 	idea:
 * 			[] pthread error handling
 * 			[] t_info free handling -> ft_exit(info)
 * 			[] Don't use exit -> ft_exit(info)
 * 			[] action and print info merge, no need to be seperated.
 * 			
 */

int	philo_start(t_info *info)
{
	pthread_t	th[MAX_T];
	t_arg		arg[MAX_T];

	if (pthread_mutex_init(&(info->mutex), NULL) || pthread_mutex_lock(&(info->mutex)))
		return (ft_exit(info));
	for (int i = 0; i < (int)info->NOP; ++i)
	{
//		printf("THREAD CREATE\n");
		arg[i].info = info;
		arg[i].i = (i + 1);
		arg[i].num_meal = 0;
		if (pthread_create(&th[i], NULL, philo, &arg[i]) != 0)
			return (ft_exit(info));
		pthread_detach(th[i]);
	}
	if (pthread_mutex_unlock(&(info->mutex)))
		return (ft_exit(info));
	return (0); // just for now
}

void *philo(void *a)
{
	t_arg *arg;

	arg = (t_arg *)a;
//	printf("%d time at start point: %zu\n", arg->i, arg->info->start);
	while(!arg->info->kill && arg->last_meal != arg->info->NOT)
	{
//		printf("philo begins\n");
		take_chopsticks(arg);
//		printf("just took chopsticks\n");
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
//		printf("%d time2: %zu\n", arg->i, arg->info->start);
		pthread_mutex_lock(&(arg->info->mutex));
		if (arg->info->fork[i] && arg->info->fork[((i + 1) % arg->info->NOP)])
		{
			arg->info->fork[i] = 0;
			arg->info->fork[((i + 1) % arg->info->NOP)] = 0;
			cond = 0;
		}
//		printf("%d time3: %zu\n", arg->i, arg->info->start);
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
//		printf("after chk starving\n");
	}
}

void check_starve(t_arg *arg)
{
	size_t	now;

	now = ft_getms();
	if (now == 0)
		exit(1); // NON
	if (now - arg->last_meal >= arg->info->TTD) // starving check
	{
		arg->info->kill = 1;
		exit(1); // NON
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