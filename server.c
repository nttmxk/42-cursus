/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinoh <jinoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:48:26 by jinoh             #+#    #+#             */
/*   Updated: 2022/02/03 16:50:43 by jinoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	main(void)
{
	print_pid();
	signal(SIGUSR1, (void *)sig_handler);
	signal(SIGUSR2, (void *)sig_handler);
	while (1)
		pause();
	return (0);
}

void	sig_handler(int signo)
{
	static char	buf[500];
	static int	i;
	static int	bit;

	if (bit == 8)
	{
		bit = 0;
		buf[++i] = 0;
	}
	if (signo == SIGUSR1)
		++bit;
	else if (signo == SIGUSR2)
		buf[i] += 1 << (8 - ++bit);
	if (bit == 8 && (i > 495 || buf[i] == '\0'))
	{
		write(1, buf, i + 1);
		write(1, "\n", 1);
		i = -1;
	}
}
