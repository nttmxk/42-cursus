#include "server.h"
///////////
#include <string.h> // substitute libft
///////////

void sig_handler(int signo)
{
	static unsigned char buf[1000];
	static int ch; // can I directly use buf?
	static int i;
	static int bit;

	if (bit == 8)
	{
		bit = 0;
		buf[i++] = ch;
		ch = 0;
	}
	if (signo == SIGUSR1) // recv_0
		++bit;
	else if (signo == SIGUSR2) // recv_1
		ch += 1 << (8 - ++bit);
	if (i > 500 || (bit == 8 && ch == '\0'))
	{
		write(1, buf, i);
		write(1, "\n", 1);
		i = 0;
	}
}

void set_sig(struct sigaction *act)
{
	act->sa_handler = sig_handler;
	act->sa_flags = SA_SIGINFO;
}

int main()
{
	struct sigaction act1;

	printf("Server PID: %d\n", getpid());
	while (1)
	{
//		set_sig(&act1);
//		sigaction(SIGUSR1, &act1, NULL)
		signal(SIGUSR1, (void *)sig_handler);
		signal(SIGUSR2, (void *)sig_handler);
		pause();
	}
	return (0);
}
