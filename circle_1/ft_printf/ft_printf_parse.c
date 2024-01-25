/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinoh <jinoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:31:20 by jinoh             #+#    #+#             */
/*   Updated: 2022/01/20 17:12:19 by jinoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_char(char c, int *cnt)
{
	(*cnt) += write(1, &c, 1);
}

void	ft_printf_str(char *str, int *cnt)
{
	if (str == NULL)
		str = "(null)";
	(*cnt) += write(1, str, ft_strlen(str));
}

void	ft_printf_int(int num, int *cnt)
{
	char	*str;

	str = ft_itoa(num);
	if (!str)
		return ;
	(*cnt) += write(1, str, ft_strlen(str));
	free(str);
}

void	ft_printf_uint(unsigned int num, int *cnt)
{
	char	*str;

	str = ft_itoa_u(num);
	if (!str)
		return ;
	(*cnt) += write(1, str, ft_strlen(str));
	free(str);
}

void	ft_printf_hexa(unsigned long long nbr, int mode, int *cnt)
{
	int				i;
	char			num[32];
	char			*base;

	if (mode == 1)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	i = -1;
	while (nbr >= 16)
	{
		num[++i] = base[nbr % 16];
		nbr /= 16;
	}
	num[++i] = base[nbr % 16];
	(*cnt) += i + 1;
	if (mode == 2)
		(*cnt) += write(1, "0x", 2);
	while (i >= 0)
		write(1, &num[i--], 1);
}
