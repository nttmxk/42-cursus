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