/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinoh <jinoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:41:40 by jinoh             #+#    #+#             */
/*   Updated: 2021/11/27 16:41:42 by jinoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	size;
	char	*ret;

	size = ft_strlen(str);
	ret = malloc(sizeof(char) * (size + 1));
	if (ret == NULL)
	{
		free(ret);
		ret = NULL;
		return (NULL);
	}
	ft_memcpy(ret, str, size + 1);
	return (ret);
}
