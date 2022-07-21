#include "philo.h"

unsigned long long	ft_atol(const char *str)
{
	unsigned long long	ret;
	int				i;

	i = 0;
	ret = 0;
	while (str[i] >= '0' && str[i] <= '9')
		ret = ret * 10 + (str[i++] - '0');
	return (ret);
}

void print_info(t_info *info, unsigned int i, int type)
{
	size_t	now;

	if (pthread_mutex_lock(&(info->mutex)))
		ft_exit(info);
	if (info->kill)
		return ;
	now = ft_getms();
	if (now == 0)
		ft_exit(info);
	if (type == 0)
		printf("%zums %d has taken a fork\n", now - info->start, i);
	else if (type == 1)
		printf("%zums %d is eating\n", now - info->start, i);
	else if (type == 2)
		printf("%zums %d is sleeping\n", now - info->start, i);
	else if (type == 3)
		printf("%zums %d is thinking\n", now - info->start, i);
	else
		printf("%zums %d died\n", now - info->start, i);
	if (pthread_mutex_unlock(&(info->mutex)))
		ft_exit(info);
}

size_t ft_getms(void)
{
	struct timeval now;

	if (gettimeofday(&now, NULL))
		return (0);
	return (now.tv_sec * 1000 + now.tv_usec / 1000);
}

int	ft_error(t_info *info)
{
	printf("Arguments:\n"
		   "number of philosophers\ntime to die\ntime to eat\n"
		   "time_to_sleep\n[number of times each philosopher must eat]\n");
	return (ft_exit(info));
}

int	ft_exit(t_info *info)
{
	info->kill = 1;
	pthread_mutex_unlock(&(info->mutex));
	usleep(100);
	printf("Error has occurred.\n");
	free(info);
	info = NULL;
	return (1);
}