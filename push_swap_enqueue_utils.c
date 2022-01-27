#include "push_swap.h"

static int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_atol(const char *s)
{
	int			i;
	int			sign;
	long long	ret;

	i = 0;
	sign = 1;
	ret = 0;
	while (ft_isspace(s[i]))
		++i;
	if (s[i] == '+')
		++i;
	else if (s[i] == '-')
	{
		++i;
		sign = -1;
	}
	while (ft_isdigit(s[i]))
	{
		ret = ret * 10 + sign * (s[i++] - '0');
		if (ret > INT_MAX || ret < INT_MIN)
			ft_error();
	}
	return ((int)ret);
}
