#include "get_next_line.h"

char *get_next_line(int fd)
{
	char buf[BUFFER_SIZE + 1];
	static char *data;
	char *ret;
	int size;
	int pos;

	if (fd < 0)
		return (NULL);
	if (data != 0 && *data != 0)
	{
		pos = ft_strchr(data, '\n');
		if (pos == -1)
		{
			size = read(fd, buf, BUFFER_SIZE);
			if (size > 0)
			{
				buf[size] = '\0';
				data = ft_strjoin(data, buf);
				return (get_next_line(fd));
			}
			else if (size == 0)
			{
				ret = ft_substr(data, 0, ft_strlen(data));
				return (ret);
			}
			else
				return (NULL);
		}
		else
		{ // we found LF
			ret = ft_substr(data, 0, pos + 1);
			ft_memmove(data, data + pos + 1, ft_strlen(data) - pos);
			return (ret);
		}
	}
	else
	{ // we have no data from ex
		size = read(fd, buf, BUFFER_SIZE);
		if (size > 0)
		{
			buf[size] = '\0';
			data = ft_strjoin(data, buf);
			return (get_next_line(fd));
		}
		else if (size == 0)
		{
			if (*data == 0)
				return (NULL);
			ret = ft_substr(data, 0, ft_strlen(data));
			return (ret);
		}
		else
			return (NULL);
	}
}

int main() {
	int fd;
	int i;
	int j;
	char *line;

	j = 1;
	printf("\n==========================================\n");
	printf("========= TEST 2 : Empty Lines ===========\n");
	printf("==========================================\n\n");

	if (!(fd = open("../test.txt", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((line = get_next_line(fd)) > 0)
	{
		printf("|%s\n", line);
		free(line);
		j++;
	}
	printf("|%s\n", line);
	free(line);
	close(fd);

}