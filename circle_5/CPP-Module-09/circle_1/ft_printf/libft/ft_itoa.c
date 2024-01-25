/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinoh <jinoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:39:04 by jinoh             #+#    #+#             */
/*   Updated: 2021/11/27 16:39:07 by jinoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_neg(int n);

char	*ft_itoa(int n)
{
	int		i;
	int		j;
	char	temp[12];
	char	*ret;

	if (n < 0)
		return (ft_itoa_neg(n));
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

static char	*ft_itoa_neg(int n)
{
	int		i;
	int		j;
	char	temp[12];
	char	*ret;

	i = 12;
	while (n != 0)
	{
		j = n % 10;
		temp[--i] = '0' - j;
		n /= 10;
	}
	ret = ft_calloc(13 - i + 1, sizeof(char));
	if (!ret)
		return (NULL);
	j = -1;
	ret[++j] = '-';
	while (i < 12)
		ret[++j] = temp[i++];
	ret[++j] = '\0';
	return (ret);
}
