#include "server_bonus.h"

void	ft_error(void)
{
	write(2, "Crash!\n", 7);
	exit(1);
}

void	print_pid(void)
{
	char	*s;

	write(1, "Server PID: ", 12);
	s = ft_itoa(getpid());
	if (!s)
		ft_error();
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
	free(s);
}

char	*ft_itoa(int n)
{
	int		i;
	int		j;
	char	temp[12];
	char	*ret;

	i = 12;
	if (n == 0)
		temp[--i] = '0';
	while (n != 0)
	{
		j = n % 10;
		temp[--i] = j + '0';
		n /= 10;
	}
	ret = malloc(12 - i + 1, sizeof(char));
	if (!ret)
		return (NULL);
	j = -1;
	while (i < 12)
		ret[++j] = temp[i++];
	ret[++j] = '\0';
	return (ret);
}