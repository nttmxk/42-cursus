/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinoh <jinoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:31:37 by jinoh             #+#    #+#             */
/*   Updated: 2022/01/06 17:31:39 by jinoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_u(unsigned int n)
{
	int		i;
	int		j;
	char	temp[12];
	char	*ret;

	i = 12;
	if (n == 0)
		temp[--i] = '0';
	while (n != 0)
	{
		j = n % 10;
		temp[--i] = j + '0';
		n /= 10;
	}
	ret = ft_calloc(12 - i + 1, sizeof(char));
	if (!ret)
		return (NULL);
	j = -1;
	while (i < 12)
		ret[++j] = temp[i++];
	ret[++j] = '\0';
	return (ret);
}
