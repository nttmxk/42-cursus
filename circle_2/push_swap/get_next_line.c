/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinoh <jinoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 22:18:04 by jinoh             #+#    #+#             */
/*   Updated: 2022/01/31 02:38:56 by jinoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char		*gnl_exception(char **data, int r_size);
char		*gnl_with_data(char **data, int fd);
static char	*gnl_for_ps(void);

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*data;
	int			r_size;

	if (fd < 0)
		return (NULL);
	if (data != 0 && *data != 0)
		return (gnl_with_data(&data, fd));
	r_size = read(fd, buf, BUFFER_SIZE);
	if (r_size > 0)
	{
		buf[r_size] = '\0';
		data = ft_strjoin_g(data, buf);
		return (gnl_with_data(&data, fd));
	}
	return (gnl_exception(&data, r_size));
}

char	*gnl_exception(char **data, int r_size)
{
	char	*ret;

	if (r_size == 0)
	{
		if (*data)
		{
			ret = ft_substr_g(*data, ft_strlen(*data));
			if (!ret)
				return (gnl_for_ps());
			free(*data);
			*data = NULL;
			return (ret);
		}
		return (gnl_for_ps());
	}
	return (NULL);
}

static char	*gnl_for_ps(void)
{
	char	*ret;

	ret = malloc(sizeof(char));
	ret[0] = -1;
	return (ret);
}

char	*gnl_with_data(char **data, int fd)
{
	char	buf[BUFFER_SIZE + 1];
	char	*ret;
	int		pos;
	int		r_size;

	pos = ft_strchr_g(*data);
	if (pos == -1)
	{
		r_size = read(fd, buf, BUFFER_SIZE);
		if (r_size > 0)
		{
			buf[r_size] = '\0';
			*data = ft_strjoin_g(*data, buf);
			return (gnl_with_data(data, fd));
		}
		return (gnl_exception(data, r_size));
	}
	else
	{
		ret = ft_substr_g(*data, pos + 1);
		*data = ft_memmove_g(*data, *data + pos + 1, ft_strlen(*data) - pos);
		return (ret);
	}
}
