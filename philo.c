#include "philo.h"

int main(int argc, char *argv[])
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (!info)
		return (1);
	if (argc < 5 || argc > 6 || handle_input(argv, info))
		return (ft_error(info));
	return (philo_set(info));
}

int	philo_set(t_info *info)
{
	pthread_t		th[MAX_T];
	t_arg			arg[MAX_T];

	if (pthread_mutex_init(&(info->mutex), NULL) || pthread_mutex_lock(&(info->mutex)))
		return (ft_exit(info));
	for (int i = 0; i < info->NOP; ++i)
	{
//		printf("THREAD CREATE\n");
		arg[i].info = info;
		arg[i].i = (i + 1);
		arg[i].num_meal = 0;
		if (pthread_create(&th[i], NULL, philo_start, &arg[i]) != 0 || pthread_detach(th[i]))
			return (ft_exit(info));
	}
	if (pthread_mutex_unlock(&(info->mutex)))
		ft_exit(info);
	philo_monitor(info);
	return (0);
}

void philo_monitor(t_info *info)
{
	while (!info->kill)
	{
		if (usleep(1))
			info->kill = 1;
	}
	usleep(100);
	free(info);
	info = NULL;
}