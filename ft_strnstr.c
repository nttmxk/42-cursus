/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinoh <jinoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:44:10 by jinoh             #+#    #+#             */
/*   Updated: 2021/11/27 16:52:26 by jinoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	len_l;
	size_t	len_b;

	if (!little || !*little)
		return ((char *)big);
	i = 0;
	len_b = ft_strlen(big);
	len_l = ft_strlen(little);
	while (i + len_l <= len && i + len_l <= len_b)
	{
		j = 0;
		while (big[i + j] == little[j] && little[j])
		{
			++j;
		}
		if (j == len_l)
			return ((char *)&big[i]);
		++i;
	}
	return (NULL);
}
