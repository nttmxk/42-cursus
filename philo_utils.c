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
	size_t t;

	t = ft_getms() - info->start;
	pthread_mutex_lock(&(info->mutex));
	if (type == 0)
		printf("%zums %d has taken a fork\n", t, i);
	else if (type == 1)
		printf("%zums %d is eating\n", t, i);
	else if (type == 2)
		printf("%zums %d is sleeping\n", t, i);
	else if (type == 3)
		printf("%zums %d is thinking\n", t, i);
	else
		printf("%zums %d died\n", t, i);
	pthread_mutex_unlock(&(info->mutex));
}

size_t ft_getms(void)
{
	struct timeval now;

	gettimeofday(&now, NULL); // if error, -1 returned
	return (now.tv_sec * 1000 + now.tv_usec / 1000);
}

//size_t	ft_gettime(struct timeval s)
//{
//	struct timeval	now;
//
//	gettimeofday(&now, NULL); // if error, -1 returned
//	printf("%ld %ld %d %d\n", now.tv_sec, s.tv_sec, now.tv_usec, s.tv_usec);
//	return ((now.tv_sec - s.tv_sec) * 1000 + (now.tv_usec - s.tv_usec) / 1000);
//}