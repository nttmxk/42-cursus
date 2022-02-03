#include "server.h"

void	sig_handler(int signo)
{
	static unsigned char	buf[500];
	static int				ch;
	static int				i;
	static int				bit;

	if (bit == 8)
	{
		bit = 0;
		buf[i++] = ch;
		ch = 0;
	}
	if (signo == SIGUSR1)
		++bit;
	else if (signo == SIGUSR2)
		ch += 1 << (8 - ++bit);
	if (i > 499 || (bit == 8 && ch == '\0'))
	{
		write(1, buf, i);
		write(1, "\n", 1);
		i = 0;
	}
}

int	main(void)
{
	printf("Server PID: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, (void *)sig_handler);
		signal(SIGUSR2, (void *)sig_handler);
		pause();
	}
	return (0);
}
