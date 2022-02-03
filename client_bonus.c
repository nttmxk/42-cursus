#include "client_bonus.h"

static void	_dispatch(int pid, int i);
static void	_send(int pid, char c, int i);

int	main(int argc, char *argv[])
{
	if (argc != 3)
		ft_error();
	ft_check_input(argv[1]);
	ft_send(ft_atoi(argv[1]), argv[2]);
	return (0);
}

void	sig_handler(int signo)
{
	if (signo == SIGUSR1)
		return ;
	else
	{
		write(2, "Crash!\n", 7);
		exit(1);
	}
}

void	ft_send(int pid, char *s)
{
	int	i;
	int	size;

	if (pid > PID_MAX)
		ft_error();
	size = ft_strlen(s);
	i = -1;
	while (++i < size)
		_send(pid, s[i], 0);
	_send(pid, 0, 0);
}

static void	_dispatch(int pid, int i)
{
	if (i == 0)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	signal(SIGUSR1, (void *)sig_handler);
	signal(SIGUSR2, (void *)sig_handler);
	pause();
}

static void	_send(int pid, char c, int i)
{
	if (!c)
	{
		while (++i <= 8)
			_dispatch(pid, 0);
		return ;
	}
	_send(pid, c / 2, ++i);
	_dispatch(pid, c % 2);
}