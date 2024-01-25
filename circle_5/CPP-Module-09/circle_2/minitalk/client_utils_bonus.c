/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinoh <jinoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:59:15 by jinoh             #+#    #+#             */
/*   Updated: 2022/02/03 17:50:40 by jinoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (ft_isdigit(str[i]))
		ret = ret * 10 + (str[i++] - '0');
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

void	ft_error(void)
{
	write(2, "Input is incorrect.\n", 20);
	write(2, "[Server PID] [String]\n", 22);
	exit(1);
}

void	ft_check_input(char *s)
{
	int	i;

	i = -1;
	if (!s[0])
		ft_error();
	while (s[++i])
	{
		if (!ft_isdigit(s[i]))
			ft_error();
	}
	if (i > 5)
		ft_error();
}
