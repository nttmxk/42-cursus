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

	now = ft_getms();
	if (now == 0)
		exit(1); // NON
	pthread_mutex_lock(&(info->mutex));
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
	pthread_mutex_unlock(&(info->mutex));
}

size_t ft_getms(void)
{
	struct timeval now;

	if (gettimeofday(&now, NULL))
		return (0);
	return (now.tv_sec * 1000 + now.tv_usec / 1000);
}