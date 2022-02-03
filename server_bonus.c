/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinoh <jinoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:22:28 by jinoh             #+#    #+#             */
/*   Updated: 2022/02/03 17:36:22 by jinoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

int	main(void)
{
	struct sigaction	act1;

	print_pid();
	set_sig(&act1);
	sigaction(SIGUSR1, &act1, NULL);
	sigaction(SIGUSR2, &act1, NULL);
	while (1)
		pause();
	return (0);
}

int	check_pid(siginfo_t *info, int *pid)
{
	if (*pid == 0)
		*pid = info->si_pid;
	else if (*pid != info->si_pid)
	{
		kill(*pid, SIGUSR2);
		kill(info->si_pid, SIGUSR2);
		return (1);
	}
	return (0);
}

void	sig_handler(int signo, siginfo_t *info, void *context)
{
	static unsigned char	buf[500];
	static int				i;
	static int				bit;
	static int				pid;

	(void)context;
	if (bit == 8)
	{
		bit = 0;
		buf[++i] = 0;
	}
	if (signo == SIGUSR1)
		++bit;
	else if (signo == SIGUSR2)
		buf[i] += 1 << (8 - ++bit);
	if (check_pid(info, &pid))
		ft_error();
	if (bit == 8 && ((i > 494 && check_uni(buf, i)) || buf[i] == '\0'))
	{
		write(1, buf, i + 1);
		write(1, "\n", 1);
		i = -1;
		pid = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	check_uni(unsigned char buf[], int i)
{
	if (buf[i] < 128)
		return (1);
	else if (buf[i] < 192)
	{
		if (buf[i - 3] >= 240)
			return (1);
		else if (buf[i - 2] < 240)
			return (1);
		else if (buf[i - 1] < 224)
			return (1);
	}
	return (0);
}

void	set_sig(struct sigaction *act)
{
	act->sa_sigaction = sig_handler;
	act->sa_flags = SA_SIGINFO;
}
