#include "ft_printf_bonus.h"

int	ft_nbrlen(int num)
{
	int	i;

	if (num == 0)
		return (1);
	i = 0;
	while (num != 0)
	{
		num /= 10;
		++i;
	}
	return (i);
}

void	ft_putnbr(long long n)
{
	char	k;

	if (n < 0)
		n *= -1;
	if (n >= 10)
		ft_putnbr(n / 10);
	k = (n % 10) + '0';
	write(1, &k, 1);
}

void	ft_putunbr(unsigned int n)
{
	char	k;

	if (n >= 10)
		ft_putunbr(n / 10);
	k = (n % 10) + '0';
	write(1, &k, 1);
}

int	ft_unbrlen(unsigned int num)
{
	int	i;

	if (num == 0)
		return (1);
	i = 0;
	while (num != 0)
	{
		num /= 10;
		++i;
	}
	return (i);
}
