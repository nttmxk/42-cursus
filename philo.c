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
	pthread_t **th;
	t_arg arg;

	th = malloc(sizeof(pthread_t *) * info->NOP);
	if (th == NULL)
		return (1);
	if (pthread_mutex_init(&(info->mutex), NULL) || pthread_mutex_lock(&(info->mutex)))
		return (1);
	arg.info = info;
	for (int i = 0; i < (int)info->NOP; ++i)
	{
		arg.i = (i + 1);
		if (pthread_create(th[i], NULL, philo, &arg) < 0)
			exit(0); // NON
	}
	if (pthread_mutex_unlock(&(info->mutex)))
		exit(0); // NON
}

void *philo(void *a)
{
	t_arg *arg;

	arg = (t_arg *)a;
	do {
		take_chopsticks(arg);
		print_info(arg->info, arg->i, 0); // taken a fork
		print_info(arg->info, arg->i, 1); // EATING
		usleep(arg->info->TTE);
		gettimeofday(&(arg->last_meal), NULL); // if error occurred?

//		put_chopsticks(i);
		print_info(arg->info, arg->i, 2); //sleep;
		usleep(arg->info->TTS);
		print_info(arg->info, arg->i, 3); // thinking
	} while(1);
}

void take_chopsticks(t_arg *arg)
{
	unsigned int	i;
	int cond;

	cond = 1;
	i = arg->i;
	while (cond)
	{
		pthread_mutex_lock(&(arg->info->mutex));
		if (arg->info->fork[i] && arg->info->fork[((i + 1) % arg->info->NOP)])
		{
			arg->info->fork[i] = 0;
			arg->info->fork[((i + 1) % arg->info->NOP)] = 0;
		}
		pthread_mutex_unlock(&(arg->info->mutex));
		usleep(10);
		// starving check
	}
}
//
//void put_chopsticks(int i)
//{
//	pthread_mutex_lock(mutex);
//	state[i] = THINKING;
//	test(LEFT);
//	test(RIGHT);
//	pthread_mutex_unlock(mutex);
//}

void print_info(t_info *info,int i, int type)
{
	int t;

	t = ft_gettime(info->start);
	pthread_mutex_lock(&(info->mutex));
	if (type == 0)
		printf("%d %d has taken a fork", t, i);
	else if (type == 1)
		printf("%d %d is eating", t, i);
	else if (type == 2)
		printf("%d %d is sleeping", t, i);
	else if (type == 3)
		printf("%d %d is thinking", t, i);
	else
		printf("%d %d died", t, i);
	pthread_mutex_unlock(&(info->mutex));
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
	info->kill = 0;
	if (i > 5)
		info->NOT = (unsigned int) ft_atol(argv[5]);
	gettimeofday(&(info->start), NULL); // error?
	memset(info->fork, 1, (info->NOP + 2) * sizeof(char)); // error?
	return (0);
}

size_t	ft_gettime(struct timeval s)
{
	struct timeval	now;
	size_t			start;

	start = s.tv_sec * 1000 * 1000 + s.tv_usec;
	gettimeofday(&now, NULL); // if error, -1 returned
	return (now.tv_sec * 1000 * 1000 + now.tv_usec - start);
}