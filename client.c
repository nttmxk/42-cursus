/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinoh <jinoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:48:10 by jinoh             #+#    #+#             */
/*   Updated: 2022/02/03 12:48:12 by jinoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void	dispatch(int pid, int i);
static void	_send(int pid, char c, int i);

int	main(int argc, char *argv[])
{
	if (argc != 3)
		ft_error();
	ft_check_input(argv[1]);
	ft_send(ft_atoi(argv[1]), argv[2]);
	return (0);
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

static void	dispatch(int pid, int i)
{
	if (i == 0)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(125);
}

static void	_send(int pid, char c, int i)
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