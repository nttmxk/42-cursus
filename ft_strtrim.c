/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinoh <jinoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:44:43 by jinoh             #+#    #+#             */
/*   Updated: 2021/11/28 18:29:48 by jinoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	size_t	a;
	char	*ret;

	if (!s1)
		return (NULL);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		++i;
	a = i;
	i = ft_strlen(s1) - 1;
	while (s1[i] && a <= i && ft_strchr(set, s1[i]))
		--i;
	len = i - a + 1;
	ret = ft_calloc(len + 1, sizeof(char));
	if (!ret)
		return (NULL);
	i = -1;
	while (++i < len)
		ret[i] = s1[a++];
	ret[i] = '\0';
	return (ret);
}
