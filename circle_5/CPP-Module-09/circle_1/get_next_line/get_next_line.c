#include "get_next_line.h"

char	*gnl_exception(char *data, int r_size);
char	*gnl_with_data(char **data, int fd);

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
		data = ft_strjoin(data, buf);
		return (get_next_line(fd));
	}
	return (gnl_exception(data, r_size));
}

char	*gnl_exception(char *data, int r_size)
{
	if (r_size == 0)
		return (ft_substr(data, ft_strlen(data)));
	else
		return (NULL);
}

char	*gnl_with_data(char **data, int fd)
{
	char	buf[BUFFER_SIZE + 1];
	char	*ret;
	int		pos;
	int		r_size;

	pos = ft_strchr(*data);
	if (pos == -1)
	{
		r_size = read(fd, buf, BUFFER_SIZE);
		if (r_size > 0)
		{
			buf[r_size] = '\0';
			*data = ft_strjoin(*data, buf);
			return (get_next_line(fd));
		}
		return (gnl_exception(*data, r_size));
	}
	else
	{
		ret = ft_substr(*data, pos + 1);
		*data = ft_memmove(*data, *data + pos + 1, ft_strlen(*data) - pos);
		return (ret);
	}
}