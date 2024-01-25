/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinoh <jinoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:31:06 by jinoh             #+#    #+#             */
/*   Updated: 2022/01/06 17:35:30 by jinoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		i;
	int		cnt;
	char	c;

	i = -1;
	cnt = 0;
	va_start(ap, fmt);
	while (fmt[++i])
	{
		c = fmt[i];
		if (c == '%' && fmt[++i])
			ft_printf_parse(fmt[i], &ap, &cnt);
		else if (c != '%')
			cnt += write(1, &c, 1);
		else
			break ;
	}
	va_end(ap);
	return (cnt);
}

void	ft_printf_parse(char c, va_list *ap, int *cnt)
{
	if (c == 'c')
		ft_printf_char(va_arg(*ap, int), cnt);
	else if (c == 's')
		ft_printf_str(va_arg(*ap, char *), cnt);
	else if (c == 'p')
		ft_printf_hexa(va_arg(*ap, unsigned long long), 2, cnt);
	else if (c == 'd' || c == 'i')
		ft_printf_int(va_arg(*ap, int), cnt);
	else if (c == 'u')
		ft_printf_uint(va_arg(*ap, unsigned int), cnt);
	else if (c == 'x')
		ft_printf_hexa(va_arg(*ap, unsigned int), 0, cnt);
	else if (c == 'X')
		ft_printf_hexa(va_arg(*ap, unsigned int), 1, cnt);
	else
		(*cnt) += write(1, &c, 1);
}
