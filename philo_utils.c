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
	return (ft_fail(info));
}

int	ft_fail(t_info *info)
{
	info->kill = 1;
	pthread_mutex_unlock(&info->mutex);
	printf("Error has occurred.\n");
	usleep(100);
	free(info);
	info = NULL;
	return (1);
}

void *philo_err(t_info *info)
{
	if (info)
	{
		info->kill = 1;
		pthread_mutex_unlock(&info->mutex);
	}
	return (0);
}