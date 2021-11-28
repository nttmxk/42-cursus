/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinoh <jinoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:44:55 by jinoh             #+#    #+#             */
/*   Updated: 2021/11/27 16:52:50 by jinoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	i;

	if (start > ft_strlen(s) || len == 0)
	{
		ret = malloc(sizeof(char));
		if (!ret)
			return (NULL);
		else
		{
			ret[0] = 0;
			return (ret);
		}
	}
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	ret = malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	i = -1;
	while (++i < len && s[start + i])
		ret[i] = s[start + i];
	ret[i] = 0;
	return (ret);
}
