/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinoh <jinoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:43:03 by jinoh             #+#    #+#             */
/*   Updated: 2021/11/27 16:49:32 by jinoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	if (!s)
		return (NULL); // is this a 'guard'?
	ret = malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	i = -1;
	while (++i < len)
		ret[i] = f(i, s[i]);
	ret[i] = '\0';
	return (ret);
}
