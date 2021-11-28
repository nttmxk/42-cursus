/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinoh <jinoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:44:43 by jinoh             #+#    #+#             */
/*   Updated: 2021/11/28 20:24:37 by jinoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_find(const char *str, char c);
static int		ft_count(const char *str, char c);
static char		**ft_free(char **str, int size);

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		i;
	int		prev;
	int		next;

	ret = malloc((ft_count(s, c) + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	i = -1;
	prev = 0;
	while (s[prev])
	{
		next = ft_find(s + prev, c);
		if (next == 0)
		{
			++prev;
			continue ;
		}
		ret[++i] = ft_substr(s, prev, next);
		if (!ret[i])
			return (ft_free(ret, i));
		prev += next + 1;
	}
	ret[++i] = 0;
	return (ret);
}

static int	ft_count(const char *str, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			++cnt;
			while (str[i] && str[i] != c)
				++i;
		}
		else
			++i;
	}
	return (cnt);
}

static int	ft_find(const char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (i);
	return (i);
}

static char	**ft_free(char **str, int size)
{
	while (size >= 0 && str[size])
	{
		free(str[size]);
		str[size--] = NULL;
	}
	free(str);
	str = NULL;
	return (NULL);
}
