/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinoh <jinoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:42:05 by jinoh             #+#    #+#             */
/*   Updated: 2021/11/27 16:48:41 by jinoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	a;
	size_t	i;
	char	*ret;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ret = malloc(len * sizeof(char));
	if (!ret)
		return (NULL);
	i = -1;
	while (s1[++i])
		ret[i] = s1[i];
	a = i;
	i = -1;
	while (s2[++i])
		ret[a + i] = s2[i];
	ret[a + i] = 0;
	return (ret);
}
