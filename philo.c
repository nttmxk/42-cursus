#include "philo.h"

int main(int argc, char *argv[])
{
	t_info	info;

	if (argc < 5 || argc > 6 || handle_input(argv, &info))
		return (ft_error());
	return (philo_start(&info));
}

/*
 * 	idea:
 * 			1. &info->mutex
 * 			2. memeset error
 * 			3. gettimeofday error
 */

int	philo_start(t_info *info)
{
	pthread_t th[MAX_T];
	t_arg arg;

	if (pthread_mutex_init(&(info->mutex), NULL) || pthread_mutex_lock(&(info->mutex)))
		return (1);
	arg.info = info;
	for (int i = 0; i < (int)info->NOP; ++i)
	{
		printf("THREAD CREATE\n");
		arg.i = (i + 1);
		if (pthread_create(&th[i], NULL, philo, &arg) != 0)
			exit(0); // NON
		pthread_detach(th[i]);
	}
	if (pthread_mutex_unlock(&(info->mutex)))
		exit(0); // NON
	// join? detach?
	return (0); // just for now
}

void *philo(void *a)
{
	t_arg *arg;

	arg = (t_arg *)a;
	do {
		printf("philo start\n");
		take_chopsticks(arg);
		printf("just took chopsticks\n");
		print_info(arg->info, arg->i, 0); // taken a fork
		print_info(arg->info, arg->i, 1); // EATING
		usleep(arg->info->TTE);
		gettimeofday(&(arg->last_meal), NULL); // if error occurred?

		put_chopsticks(arg);
		print_info(arg->info, arg->i, 2); //sleep;
		usleep(arg->info->TTS);
		check_starve(arg);
		print_info(arg->info, arg->i, 3); // thinking
	} while(!arg->info->kill);
	return (0);
}

void take_chopsticks(t_arg *arg)
{
	unsigned int	i;
	int cond;

	cond = 1;
	i = arg->i;
	while (cond)
	{
		printf("time2: %zu\n", ft_gettime(arg->info->start));
		pthread_mutex_lock(&(arg->info->mutex));
		if (arg->info->fork[i] && arg->info->fork[((i + 1) % arg->info->NOP)])
		{
			printf("take chopsticks\n");
			arg->info->fork[i] = 0;
			arg->info->fork[((i + 1) % arg->info->NOP)] = 0;
			cond = 0;
		}
		printf("time3: %zu\n", ft_gettime(arg->info->start));
		pthread_mutex_unlock(&(arg->info->mutex));
		if (cond)
			usleep(50);
		if (arg->info->kill)
		{
			printf("KILLLLLLL\n");
			exit(1); // NON
		}
//		else
//			check_starve(arg);
		printf("after chk starving\n");
	}
}

void check_starve(t_arg *arg)
{
	if (ft_gettime(arg->last_meal) >= arg->info->TTD) // starving check
	{
		arg->info->kill = 1;
		exit(1); // NON
	}
}

void put_chopsticks(t_arg *arg)
{
	unsigned int	i;

	i = arg->i;
	pthread_mutex_lock(&(arg->info->mutex));
	arg->info->fork[i] = 1;
	arg->info->fork[((i + 1) % arg->info->NOP)] = 1;
	pthread_mutex_unlock(&(arg->info->mutex));
}