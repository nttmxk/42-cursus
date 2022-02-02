#include "client.h"
//////////
#include <string.h>
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	ret;

	i = 0;
	sign = 1;
	ret = 0;
	while (ft_isdigit(str[i]))
		ret = ret * 10 + sign * (str[i++] - '0');
	return (ret);
}
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

//////////


void ft_error(void)
{
	write(1, "Input is incorrect.\n", 20);
//	write(1, "[Server PID] [String]\n", 22);
	exit(1);
}

void ft_check_input(char *s)
{
	int	i;

	i = -1;
	if (s[++i])
	{
		if (!ft_isdigit(s[i]))
			ft_error();
	}
	if (i > 4)
		ft_error();
}

void dispatch(int pid, int i)
{
	char c = i + '0';

	write(1, &c, 1);
	if (i == 0)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(1000);
}

void _send(int pid, char c, int i)
{
	if (!c)
	{
		while (++i <= 8)
			dispatch(pid, 0);
		return ;
	}
	_send(pid, c / 2, ++i);
	dispatch(pid, c % 2);
}

void ft_send(int pid, char *s)
{
	int	i;
	int size;

	if (pid > PID_MAX) // chk
		ft_error();
//	kill(pid, SIGUSR1);
//	pause();
	size = ft_strlen(s);
	i = -1;
	while (++i < size)
	{
		_send(pid, s[i], 0);
		write(1, "\n", 1);
	}
//	_send(pid, pid, 0);  // for bonus
	_send(pid, 0, 0); // '\0'
}

int main(int argc, char *argv[])
{
	if (argc != 3)
		ft_error();
	ft_check_input(argv[1]);
	ft_send(ft_atoi(argv[1]), argv[2]);
	return (0);
}
